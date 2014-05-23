//
//  SoundActionSampleScene.h
//  cocos3
//
//  Created by ANZ on 2014/05/24.
//
//

#ifndef __cocos3__SoundActionSampleScene__
#define __cocos3__SoundActionSampleScene__

#include "cocos2d.h"

class SoundActionSampleScene : public cocos2d::Layer
{
    
public:
    SoundActionSampleScene();
    virtual ~SoundActionSampleScene();
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(SoundActionSampleScene);
    
    virtual void onExit();
    
protected:
    
private:
    
};

#endif /* defined(__cocos3__SoundActionSampleScene__) */
