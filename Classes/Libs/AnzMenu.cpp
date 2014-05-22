//
//  AnzMenu.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/06.
//
//

#include "AnzMenu.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

AnzMenu::AnzMenu()
{
}

AnzMenu::~AnzMenu()
{
}

AnzMenu* AnzMenu::create(cocos2d::MenuItem *item, ...)
{
    va_list args;
    va_start(args,item);
    
    AnzMenu *ret = AnzMenu::createWithItems(item, args);
    
    va_end(args);
    
    return ret;

}

AnzMenu* AnzMenu::createWithItems(cocos2d::MenuItem *firstItem, va_list args)
{
    Vector<MenuItem*> items;
    if( firstItem )
    {
        items.pushBack(firstItem);
        MenuItem *i = va_arg(args, MenuItem*);
        while(i)
        {
            items.pushBack(i);
            i = va_arg(args, MenuItem*);
        }
    }
    
    return AnzMenu::createWithArray(items);
}

AnzMenu* AnzMenu::createWithArray(const Vector<MenuItem*>& arrayOfItems)
{
    auto ret = new AnzMenu();
    if (ret && ret->initWithArray(arrayOfItems))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    
    return ret;
}


bool AnzMenu::initWithArray(const Vector<MenuItem*>& arrayOfItems)
{
    if (! Menu::initWithArray(arrayOfItems)) {
        return false;
    }

    callbackTracking_ = nullptr;
    soundFilePath_ = nullptr;
    soundOn_ = true;
    
    return true;
}

bool AnzMenu::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    // 該当するMenuItemがなければfalseが返ってくる
    if ( ! Menu::onTouchBegan(touch, event)) {
        return false;
    }
    
    if ( callbackTracking_ != nullptr && _selectedItem != nullptr) {
        scheduleUpdate();
    }
    
    soundEffect();
    
    return true;
}

void AnzMenu::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    Menu::onTouchEnded(touch, event);
    
    if ( callbackTracking_ != nullptr) {
        unscheduleUpdate();
    }
}

void AnzMenu::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
{
    Menu::onTouchCancelled(touch, event);
    
    if ( callbackTracking_ != nullptr) {
        unscheduleUpdate();
    }
}

void AnzMenu::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    State before = _state;
    
    Menu::onTouchMoved(touch, event);
    
    if ( callbackTracking_ == nullptr) {
        return;
    }
    
    if (before == _state) {
        return;
    }
    
    // ココに来るときは画面タップ状態で一旦領域から外れて戻ってきた時
    if (_state == State::WAITING) {
        unscheduleUpdate();
    } else if (_state == State::TRACKING_TOUCH) {
        scheduleUpdate();
        soundEffect();
    }
}

Menu::State AnzMenu::getState()
{
    return _state;
}

MenuItem* AnzMenu::getCurrentMenuItem()
{
    return _selectedItem;
}

/** 押され続けられてるかどうか */
void AnzMenu::setCallbackTracking(std::function<void (cocos2d::MenuItem *)> callback)
{
    callbackTracking_ = callback;
}

void AnzMenu::setSoundFilePath(const char *soundFilePath)
{
    setSoundFilePath(soundFilePath, true);
}

void AnzMenu::setSoundFilePath(const char *soundFilePath, bool isPreLoad)
{
    soundFilePath_ = soundFilePath;
    if (isPreLoad) {
        SimpleAudioEngine::getInstance()->preloadEffect(soundFilePath_);
    }
}

void AnzMenu::isSound(bool isOn)
{
    soundOn_ = isOn;
}

/** MenuItemで音変えたいならこっちも設定 tag=>filepath */
void AnzMenu::setSoundList(std::map<int, const char *> soundList)
{
    setSoundList(soundList, true);
}

/** MenuItemで音変えたいならこっち tag=>filepath(true指定でPreLoad実施) */
void AnzMenu::setSoundList(std::map<int, const char *> soundList, bool isPreLoad)
{
    soundList_ = soundList;
    
    if ( ! isPreLoad) {
        return;
    }
    
    for (auto kvs : soundList) {
        SimpleAudioEngine::getInstance()->preloadEffect(kvs.second);
    }
}

void AnzMenu::setChildrenPositionOffset(cocos2d::Point offset)
{
    auto children = getChildren();
    if (children.empty()) {
        return;
    }
    
    for (auto child : children) {
        auto p = child->getPosition();
        child->setPosition(p.x + offset.x, p.y + offset.y);
    }
}

void AnzMenu::update(float dt)
{
    if (callbackTracking_ == nullptr || _selectedItem == nullptr) {
        return;
    }
    callbackTracking_(_selectedItem);
}

void AnzMenu::soundEffect()
{
    if (! soundOn_ || (soundFilePath_ == nullptr && soundList_.empty() )) {
        return;
    }
    
    // リスト指定がないなら
    if (soundList_.empty()) {
        SimpleAudioEngine::getInstance()->playEffect(soundFilePath_);
        return;
    }
    
    // リストの中に該当するtagがあれば、そっちから
    // なければメインのほう
    if (soundList_.find(_selectedItem->getTag()) != soundList_.end()) {
        auto kv = soundList_.at(_selectedItem->getTag());
        SimpleAudioEngine::getInstance()->playEffect(kv);
    } else {
        SimpleAudioEngine::getInstance()->playEffect(soundFilePath_);
    }
}

