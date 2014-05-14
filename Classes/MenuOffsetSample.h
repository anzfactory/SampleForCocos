//
//  MenuOffsetSample.h
//  cocos3
//
//  Created by ANZ on 2014/05/15.
//
//

#ifndef __cocos3__MenuOffsetSample__
#define __cocos3__MenuOffsetSample__

#include "cocos2d.h"

class MenuOffsetSample : public cocos2d::Layer
{
    
public:
    MenuOffsetSample();
    virtual ~MenuOffsetSample();
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(MenuOffsetSample);
    
protected:
    
private:
    
    void tapMenuItem(int tag);
    
};

#endif /* defined(__cocos3__MenuOffsetSample__) */
