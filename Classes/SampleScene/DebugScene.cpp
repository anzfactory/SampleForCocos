//
//  DebugScene.cpp
//  cocos3
//
//  Created by ANZ on 2014/06/14.
//
//

#include "DebugScene.h"

USING_NS_CC;
using namespace std;

DebugScene::DebugScene()
{
    
}

DebugScene::~DebugScene()
{
    
}

Scene* DebugScene::createScene()
{
    auto scene = CCScene::create();
	auto layer = DebugScene::create();
    scene->addChild(layer);
    return scene;
}

void DebugScene::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    
    auto spr1 = getChildByTag(1);
    auto spr2 = getChildByTag(2);
    auto action = ScaleTo::create(3.f, 0.1);
    runAction(Sequence::create(DelayTime::create(13),
                               TargetedAction::create(spr1, action),
                               DelayTime::create(2),
                               TargetedAction::create(spr2, action->clone()),
                               NULL));
}

bool DebugScene::init()
{
    if (! Layer::init()) {
        return false;
    }
    
    auto size = getContentSize();
    
    auto createSprite = []() {
        auto spr = Sprite::create("HelloWorld.png");
        return spr;
    };
    auto spr1 = createSprite();
    spr1->setPosition(size.width * .5f, size.height * 0.75);
    spr1->setTag(1);
    addChild(spr1);
    auto spr2 = createSprite();
    spr2->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    spr2->setPosition(spr1->getPositionX() - (spr2->getContentSize().width * .5), size.height * 0.25 - (spr2->getContentSize().height * .5f));
    spr2->setTag(2);
    addChild(spr2);
    
    return true;
}
