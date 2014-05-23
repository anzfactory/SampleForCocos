//
//  SoundActionSampleScene.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/24.
//
//

#include "SoundActionSampleScene.h"

#include "AnzSound.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

SoundActionSampleScene::SoundActionSampleScene()
{
    
}

SoundActionSampleScene::~SoundActionSampleScene()
{
    
}

Scene* SoundActionSampleScene::createScene()
{
    auto scene = CCScene::create();
	auto layer = SoundActionSampleScene::create();
    scene->addChild(layer);
    return scene;
}

void SoundActionSampleScene::onExit()
{
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    
    Layer::onExit();
}

bool SoundActionSampleScene::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    auto size = getContentSize();
    
    auto createMenuItem = [](const char* text, float fonotSize = 40) {
        auto normal = Label::createWithSystemFont(text, "Arial", fonotSize);
        auto selected = Label::createWithSystemFont(text, "Arial", fonotSize);
        selected->setColor(Color3B::GRAY);
        return MenuItemSprite::create(normal, selected);
    };
    
    auto itemPlay = createMenuItem("PLAY", 50);
    itemPlay->setCallback([this](Ref *sender){
        // fadein 用に一旦vol=0
        SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.f);
        this->stopAllActions();
        this->runAction(Sequence::create(DelayTime::create(2.f),
                                   PlayBGM::create("arasuji_03.mp3"),
                                   FadeToVolumeOfBGM::create(3.f, .5f), // 3秒かけてvolume.5に
                                   CallFunc::create([](){
            log("volume:%f", SimpleAudioEngine::getInstance()->getBackgroundMusicVolume());
        }),
                                   DelayTime::create(5.f),
                                   FadeToVolumeOfBGM::create(3.f, 0.f), // 3秒書けてミュート
                                   CallFunc::create([](){
            log("volume:%f", SimpleAudioEngine::getInstance()->getBackgroundMusicVolume());
        }),
                                   StopBGM::create(),
                                   NULL));
    });
    itemPlay->setPosition(Point(size.width * .5f, size.height * .5f));
    
    auto itemBack = createMenuItem("Back");
    itemBack->setCallback([](Ref *sender){
        Director::getInstance()->popScene();
    });
    itemBack->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    itemBack->setPosition(itemPlay->getPositionX(), 0);
    
    auto menu = Menu::create(itemPlay, itemBack, NULL);
    menu->setPosition(Point::ZERO);
    addChild(menu);
    
    return true;
}
