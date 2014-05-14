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
    auto size = getContentSize();
    auto clickMe = createMenuItem("Click me!!");
    clickMe->setPosition(Point(size.width * 0.5, size.height * 0.5));
    clickMe->setCallback([](Ref *sender) {
        log("sound effect");
    });
    
    auto back = createMenuItem("back");
    back->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    back->setPosition(Point(clickMe->getPosition().x, 0));
    back->setCallback([](Ref *sender) {
        Director::getInstance()->popScene();
    });
    
    auto menu = AnzMenu::create(clickMe, back, NULL);
    menu->setPosition(Point::ZERO);
    menu->setSoundFilePath("click.mp3");    // 効果音設定

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