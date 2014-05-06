//
//  AnzMenu.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/06.
//
//

#include "AnzMenu.h"

USING_NS_CC;
using namespace std;

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
    
    return true;
}

bool AnzMenu::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if ( ! Menu::onTouchBegan(touch, event)) {
        return false;
    }
    
    if ( callbackTracking_ != nullptr && _selectedItem != nullptr) {
        scheduleUpdate();
    }
    
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
    
    if (_state == State::WAITING) {
        unscheduleUpdate();
    } else if (_state == State::TRACKING_TOUCH) {
        scheduleUpdate();
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

void AnzMenu::setCallbackTracking(std::function<void (cocos2d::MenuItem *)> callback)
{
    callbackTracking_ = callback;
}

void AnzMenu::update(float dt)
{
    if (callbackTracking_ == nullptr || _selectedItem == nullptr) {
        return;
    }
    callbackTracking_(_selectedItem);
}

