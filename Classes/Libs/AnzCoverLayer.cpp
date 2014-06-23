//
//  AnzCoverLayer.cpp
//  cocos3
//
//  Created by ANZ on 2014/06/23.
//
//

#include "AnzCoverLayer.h"

USING_NS_CC;
using namespace std;

AnzCoverLayer::AnzCoverLayer()
{
    
}

AnzCoverLayer::~AnzCoverLayer()
{
    
}

AnzCoverLayer* AnzCoverLayer::create(Color4B color)
{
    auto pret = new AnzCoverLayer();
    if (pret && pret->initWithColor4B(color)) {
        pret->autorelease();
        return pret;
    }
    delete pret;
    return nullptr;
}

bool AnzCoverLayer::initWithColor4B(cocos2d::Color4B color)
{
    if (! LayerColor::initWithColor(color)) {
        return false;
    }
    
    // タッチイベントをもみ消すために
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(AnzCoverLayer::onTouchBegan, this);
     _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

bool AnzCoverLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}
