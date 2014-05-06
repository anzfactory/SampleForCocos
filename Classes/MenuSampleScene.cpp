//
//  MenuSampleScene.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/06.
//
//

#include "MenuSampleScene.h"

#include "TopScene.h"
#include "AnzMenu.h"

USING_NS_CC;
using namespace std;

MenuSampleScene::MenuSampleScene()
{
    
}

MenuSampleScene::~MenuSampleScene()
{
    
}

Scene* MenuSampleScene::createScene()
{
    auto scene = CCScene::create();
	auto layer = MenuSampleScene::create();
    scene->addChild(layer);
    return scene;
}

bool MenuSampleScene::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    setupBoard();
    setupControlPanel();
    setupMenu();
    
    return true;
}

void MenuSampleScene::setupBoard()
{
    auto size = getContentSize();
    
    auto board = Label::createWithSystemFont("", "Arial", 30);
    board->setContentSize(Size(size.width, 0));
    board->setAlignment(TextHAlignment::CENTER);
    board->setPosition(size.width * 0.5, size.height * 0.75);
    addChild(board, ZOrder::kForeground, Tags::kTagBoad);
}

void MenuSampleScene::setupControlPanel()
{
    
    auto size = getContentSize();
    auto p = Point(size.width * 0.5, size.height * 0.25);
    
    auto up = createMenuItem("↑", ControlMenu::kUp);
    up->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    up->setPosition(p);
    auto down = createMenuItem("↓", ControlMenu::kDown);
    down->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    down->setPosition(p);
    auto left = createMenuItem("←", ControlMenu::kLeft);
    left->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    left->setPosition(p);
    auto right = createMenuItem("→", ControlMenu::kRight);
    right->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    right->setPosition(p);
    
    auto menu = AnzMenu::create(up, down, left, right, NULL);
    menu->setPosition(Point::ZERO);
    menu->setCallbackTracking([this](MenuItem *selectedItem) {
        this->tapControl(selectedItem);
    });
    addChild(menu, ZOrder::kForeground, Tags::kTagControlMenu);
    
}
void MenuSampleScene::setupMenu()
{
    auto size = getContentSize();
    
    auto back = createMenuItem("back", -1);
    back->setCallback([](Ref *sender) {
        Director::getInstance()->replaceScene(TopScene::createScene());
    });
    back->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    back->setPosition(size.width * 0.5, 0);
    
    auto menu = Menu::create(back, NULL);
    menu->setPosition(Point::ZERO);
    addChild(menu, ZOrder::kForeground, Tags::kTagMenu);
    
}
MenuItem* MenuSampleScene::createMenuItem(const char *text, int tag)
{
    auto normal = Label::createWithSystemFont(text, "Arial", 50);
    auto selected = Label::createWithSystemFont(text, "Arial", 50);
    selected->setColor(Color3B::GRAY);
    
    auto item = MenuItemSprite::create(normal, selected);
    item->setTag(tag);
    
    return item;
}

void MenuSampleScene::tapControl(cocos2d::MenuItem *selectedItem)
{
    ControlMenu tag = (ControlMenu)selectedItem->getTag();
    
    const char* text;
    switch (tag) {
        case ControlMenu::kUp:
            text = "up";
            break;
            
        case ControlMenu::kDown:
            text = "down";
            break;
            
        case ControlMenu::kLeft:
            text = "left";
            break;
            
        case ControlMenu::kRight:
            text = "right";
            break;
            
        default:
            CCASSERT(1 != 0, "unknown control!!!");
            break;
    }
    log("%s",text);
    auto board = (Label *)getChildByTag(Tags::kTagBoad);
    board->setString(text);
}


