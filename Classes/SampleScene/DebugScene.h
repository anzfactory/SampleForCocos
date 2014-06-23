//
//  DebugScene.h
//  cocos3
//
//  Created by ANZ on 2014/06/14.
//
//

#ifndef __cocos3__DebugScene__
#define __cocos3__DebugScene__

#include "cocos2d.h"

class DebugScene : public cocos2d::Layer
{
    
public:
    DebugScene();
    virtual ~DebugScene();
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(DebugScene);
    void onEnterTransitionDidFinish();
protected:
    
private:
    
};

#endif /* defined(__cocos3__DebugScene__) */
