//
//  AnzCoverLayer.h
//  cocos3
//
//  Created by ANZ on 2014/06/23.
//
//

#ifndef __cocos3__AnzCoverLayer__
#define __cocos3__AnzCoverLayer__

#include "cocos2d.h"

class AnzCoverLayer : public cocos2d::LayerColor
{
    
public:
    AnzCoverLayer();
    virtual ~AnzCoverLayer();
    virtual bool initWithColor4B(cocos2d::Color4B color);
    
protected:
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
private:

};

#endif /* defined(__cocos3__AnzCoverLayer__) */
