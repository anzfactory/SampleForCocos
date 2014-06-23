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

bool AnzCoverLayer::initWithColor4B(cocos2d::Color4B color)
{
    if (! LayerColor::initWithColor(color)) {
        return false;
    }
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    
    touchListener->onTouchBegan = CC_CALLBACK_2(AnzCoverLayer::onTouchBegan, this);
    
    return true;
}

bool AnzCoverLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return false;
}
