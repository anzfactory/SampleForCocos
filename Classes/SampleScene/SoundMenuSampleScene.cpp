//
//  SoundMenuSampleScene.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/07.
//
//

#include "SoundMenuSampleScene.h"

#include "AnzMenu.h"

USING_NS_CC;
using namespace std;

SoundMenuSampleScene::SoundMenuSampleScene()
{
    
}

SoundMenuSampleScene::~SoundMenuSampleScene()
{
    
}

Scene* SoundMenuSampleScene::createScene()
{
    auto scene = CCScene::create();
	auto layer = SoundMenuSampleScene::create();
    scene->addChild(layer);
    return scene;
}

bool SoundMenuSampleScene::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    setupMenu();
    
    return true;
}


void SoundMenuSampleScene::setupMenu()
{
    map<int, const char*> anotherSounds;
    
    auto size = getContentSize();
    auto clickMe = createMenuItem("SE_CLICK_1");
    clickMe->setPosition(Point(size.width * 0.5, size.height * 0.7));
    clickMe->setCallback([](Ref *sender) {
        log("%d", sender->_ID);
    });
    
    auto clickMe2 = createMenuItem("SE_CKICK_1(2)");
    clickMe2->setPosition(Point(clickMe->getPositionX(), size.height * 0.6));
    clickMe2->setCallback([](Ref *sender) {
        log("%d", sender->_ID);
    });
    
    auto clickMe3 = createMenuItem("SE_CLICK_2");
    clickMe3->setPosition(clickMe2->getPositionX(), size.height * 0.5);
    clickMe3->setCallback([](Ref *sender){
        log("%d", sender->_ID);
    });
    // 音かえたい
    clickMe3->setTag(10);
    anotherSounds[clickMe3->getTag()] = "se_click_1.mp3";
    
    auto clickMe4 = createMenuItem("SE_TE");
    clickMe4->setPosition(clickMe3->getPositionX(), size.height * .4f);
    clickMe4->setCallback([](Ref *sender){
        log("%d", sender->_ID);
    });
    // 音変えたい
    clickMe4->setTag(20);
    anotherSounds[clickMe4->getTag()] = "se_te.mp3";
    
    auto back = createMenuItem("back");
    back->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    back->setPosition(Point(clickMe->getPosition().x, 0));
    back->setCallback([](Ref *sender) {
        log("%d", sender->_ID);
        Director::getInstance()->popScene();
    });
    
    auto menu = AnzMenu::create(clickMe, clickMe2, clickMe3, clickMe4, back, NULL);
    menu->setPosition(Point::ZERO);
    menu->setSoundFilePath("click.mp3");    // 効果音設定
    menu->setSoundList(anotherSounds);      // 別音

    addChild(menu);
}

MenuItem* SoundMenuSampleScene::createMenuItem(const char *text)
{
    auto normal = Label::createWithSystemFont(text, "Arial", 50);
    auto selected = Label::createWithSystemFont(text, "Arial", 50);
    selected->setColor(Color3B::GRAY);
    
    auto item = MenuItemSprite::create(normal, selected);
    
    return item;
}