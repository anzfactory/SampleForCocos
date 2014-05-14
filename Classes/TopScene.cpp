//
//  TopScene.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/06.
//
//

#include "TopScene.h"

#include "MenuSampleScene.h"
#include "SoundMenuSampleScene.h"
#include "MenuOffsetSample.h"

USING_NS_CC;
using namespace std;

TopScene::TopScene()
{
    
}

TopScene::~TopScene()
{
    
}

Scene* TopScene::createScene()
{
    auto scene = CCScene::create();
	auto layer = TopScene::create();
    scene->addChild(layer);
    return scene;
}

bool TopScene::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    createMenu();
    
    return true;
}

void TopScene::createMenu()
{    
    auto itemMenu = createMenuItem("MenuSample", (int)TopMenuItem::kItemMenuSample);
    auto itemSoundMenu = createMenuItem("SouneMenuSample", (int)TopMenuItem::kItemSoundMenuSample);
    auto itemOffset = createMenuItem("MenuOffsetSample", (int)TopMenuItem::kItemMenuOffsetSample);
    
    auto menu = Menu::create(itemMenu, itemSoundMenu, itemOffset, NULL);
    menu->setPosition(Point::ZERO);
    addChild(menu, Tags::kTagTopMenu);
    
}

MenuItem* TopScene::createMenuItem(const char *label, int tag)
{
    
    auto normal = Label::createWithSystemFont(label, "Arial", 40);
    auto selected = Label::createWithSystemFont(label, "Arial", 40);
    selected->setColor(Color3B::GRAY);
    
    Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("hogehoge", this);
    
    auto p = Point::ZERO;
    auto size = getContentSize();
    p.x = size.width * 0.5;
    p.y = size.height - (size.height * (1.f / (TopMenuItem::kItemCount + 1)) * (tag + 1));
    
    auto item = MenuItemSprite::create(normal, selected, CC_CALLBACK_1(TopScene::tapMenu, this));
    item->setTag(tag);
    item->setPosition(p);
    return item;
}

void TopScene::tapMenu(cocos2d::Ref *sender)
{
    TopMenuItem tag = (TopMenuItem)((Node *)sender)->getTag();
    switch (tag) {
        case kItemMenuSample:
            Director::getInstance()->pushScene(MenuSampleScene::createScene());
            break;
            
        case kItemSoundMenuSample:
            Director::getInstance()->pushScene(SoundMenuSampleScene::createScene());
            break;
            
        case kItemMenuOffsetSample:
            Director::getInstance()->pushScene(MenuOffsetSample::createScene());
            
        default:
            break;
    }
}