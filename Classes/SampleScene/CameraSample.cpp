//
//  CameraSample.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/17.
//
//

#include "CameraSample.h"

USING_NS_CC;
using namespace std;

CameraSample::CameraSample()
{
    
}

CameraSample::~CameraSample()
{
    delete camera_;
}

Scene* CameraSample::createScene()
{
    auto scene = CCScene::create();
	auto layer = CameraSample::create();
    scene->addChild(layer);
    return scene;
}

void CameraSample::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    
    throwWord(items_.begin());
}

bool CameraSample::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    setCamera();
    
    prepare();
    
    return true;
}

/** カメラセッティング */
void CameraSample::setCamera()
{
    auto cameraLayer = Layer::create();
    cameraLayer->setTag(Tags::kTagCamleraLayer);
    addChild(cameraLayer);
    
    camera_ = new ActionCamera();
    
    // 全体に効果を及ぼしたい場合は
    // thisをターゲットにしたらいい
    camera_->setTarget(cameraLayer);
    
    // camera の始点を設定
    auto eye = camera_->getEye();
    eye.y -= 0.0000003;
    camera_->setEye(eye);
    
}

/** 準備 */
void CameraSample::prepare()
{
    auto size = getContentSize();
    
    auto createLabel = [](const char* text, float fontSize = 40) {
        return Label::createWithSystemFont(text, "Arial", fontSize);
    };
    
    // 背景
    // これはthisにaddchildしているので
    // camera支店変更の影響は及ばない
    auto bg = Sprite::create("HelloWorld.png");
    bg->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    bg->setPosition(Point(size.width * .5f, size.height));
    addChild(bg);
    
    // ながすアイテムの設定
    auto cameraLayer = getChildByTag(Tags::kTagCamleraLayer);
    auto plist = FileUtils::getInstance()->getValueVectorFromFile("words.plist");
    
    for (auto item : plist) {
        auto label = createLabel(item.asString().c_str(), 50);
        label->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
        label->setPosition(Point(size.width * .5f, label->getContentSize().height * -1));
        label->setVisible(false);
        items_.pushBack(label);
        cameraLayer->addChild(label);
    }
    
    // back
    auto layerSize = Size(size.width, 50);
    auto menuLayer = LayerColor::create(Color4B::BLACK, layerSize.width, layerSize.height);
    menuLayer->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    addChild(menuLayer);
    
    auto normal = createLabel("back");
    auto selected = createLabel("back");
    selected->setColor(Color3B::GRAY);
    auto menuItem = MenuItemSprite::create(normal, selected, [](Ref *sender) {
        Director::getInstance()->popScene();
    });
    menuItem->setPosition(Point(layerSize.width * .5f, layerSize.height * .5f));
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Point::ZERO);
    menuLayer->addChild(menu);
}

/** items_を画面にながす */
void CameraSample::throwWord(cocos2d::Vector<cocos2d::Label *>::iterator it)
{
    if (it == items_.end()) {
        return;
    }
    
    auto item = *it;
    auto distance = getContentSize().height + item->getContentSize().height * 2;
    auto duration = distance / 100.f;
    auto delay = duration / 10.f;
    auto startPosition = item->getPosition();
    
    it++;
    
    // 画面下から上に流しつつ
    // 流し始めてしばらくしてから、次のアイテムを流す
    // 奥に行くに従ってfade out
    item->runAction(Sequence::create(Show::create(),
                                     Spawn::create(MoveBy::create(duration, Point(0, distance)),
                                                   Sequence::create(DelayTime::create(delay),
                                                                    CallFunc::create([it, this](){
                                                       this->throwWord(it);
                                                   }),
                                                                    FadeOut::create(duration - delay),
                                                                    NULL),
                                                   
                                                   NULL),
                                     Hide::create(),
                                     CallFunc::create([item, startPosition, it, this](){
        item->setPosition(startPosition);
        item->setOpacity(255);
        this->completed(it);
    }),
                                     NULL));
}


/** 最後のitemのactionが終了した場合発動 */
void CameraSample::completed(cocos2d::Vector<cocos2d::Label *>::iterator it)
{
    if (it != items_.end()) {
        return;
    }
    
    it = items_.begin();
    
    runAction(Sequence::create(DelayTime::create(.5f),
                               CallFunc::create([it, this](){
        this->throwWord(it);
    }),
                               NULL));
}