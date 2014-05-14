//
//  MenuOffsetSample.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/15.
//
//

#include "MenuOffsetSample.h"

#include "AnzMenu.h"

USING_NS_CC;
using namespace std;

MenuOffsetSample::MenuOffsetSample()
{
    
}

MenuOffsetSample::~MenuOffsetSample()
{
    
}

Scene* MenuOffsetSample::createScene()
{
    auto scene = CCScene::create();
	auto layer = MenuOffsetSample::create();
    scene->addChild(layer);
    return scene;
}

bool MenuOffsetSample::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    int tag = 0;
    auto createMenuItem = [&tag, this](const char* text) {
        tag++;
        auto normal = Label::createWithSystemFont(text, "Arial", 44);
        auto selected = Label::createWithSystemFont(text, "Arial", 44);
        selected->setColor(Color3B::GRAY);
        auto item = MenuItemSprite::create(normal, selected);
        item->setTag(tag);
        item->setCallback([this](Ref* sender) {
            this->tapMenuItem(((MenuItem *)sender)->getTag());
        });
        return item;
    };
    
    auto size = getContentSize();
    
    auto item1 = createMenuItem("item1");
    item1->setPosition(Point(size.width * .5f, size.height * .75f));
    auto item2 = createMenuItem("item2");
    item2->setPosition(Point(size.width * .25f, size.height * .5f));
    auto item3 = createMenuItem("item3");
    item3->setPosition(Point(size.width * .75f, item2->getPositionY()));
    auto item4 = createMenuItem("item4");
    item4->setPosition(Point(item1->getPositionX(), size.height * .25f));
    
    auto menu = AnzMenu::create(item1, item2, item3, item4, NULL);
    menu->setPosition(Point::ZERO);
    menu->setTag(100);
    
    addChild(menu);
    
    auto back = createMenuItem("back");
    back->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    back->setPosition(size.width * .5f, 0);
    auto menu2 = Menu::create(back, NULL);
    menu2->setPosition(Point::ZERO);
    addChild(menu2);
    
    return true;
}

void MenuOffsetSample::tapMenuItem(int tag)
{
    auto offset = Point::ZERO;
    switch (tag) {
        case 1:
            offset.y = 10;
            break;
            
        case 2:
            offset.x = -10;
            break;
            
        case 3:
            offset.x = 10;
            break;
            
        case 4:
            offset.y = -10;
            break;
            
        default:
            Director::getInstance()->popScene();
            return;
            break;
    }
    
    auto menu = (AnzMenu *)getChildByTag(100);
    menu->setChildrenPositionOffset(offset);
    
}
