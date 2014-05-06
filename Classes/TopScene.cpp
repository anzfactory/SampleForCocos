//
//  TopScene.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/06.
//
//

#include "TopScene.h"

#include "MenuSampleScene.h"

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
    auto itemAnzMenu = createMenuItem("AnzMenuSample", (int)TopMenuItem::kItemAnzMenuSample);
    
    auto menu = Menu::create(itemAnzMenu, NULL);
    menu->setPosition(Point::ZERO);
    addChild(menu, Tags::kTagTopMenu);
    
}

MenuItem* TopScene::createMenuItem(const char *label, int tag)
{
    
    auto normal = Label::createWithSystemFont(label, "Arial", 40);
    auto selected = Label::createWithSystemFont(label, "Arial", 40);
    selected->setColor(Color3B::GRAY);
    
    auto p = Point::ZERO;
    auto size = getContentSize();
    p.x = size.width * 0.5;
    p.y = size.height * 0.5;
    auto item = MenuItemSprite::create(normal, selected, CC_CALLBACK_1(TopScene::tapMenu, this));
    item->setTag(tag);
    item->setPosition(p);
    return item;
}

void TopScene::tapMenu(cocos2d::Ref *sender)
{
    TopMenuItem tag = (TopMenuItem)((Node *)sender)->getTag();
    switch (tag) {
        case kItemAnzMenuSample:
            Director::getInstance()->replaceScene(MenuSampleScene::createScene());
            break;
            
        default:
            break;
    }
}