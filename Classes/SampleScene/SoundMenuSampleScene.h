//
//  SoundMenuSampleScene.h
//  cocos3
//
//  Created by ANZ on 2014/05/07.
//
//

#ifndef __cocos3__SoundMenuSampleScene__
#define __cocos3__SoundMenuSampleScene__

#include "cocos2d.h"

class SoundMenuSampleScene : public cocos2d::Layer
{
    
public:
    SoundMenuSampleScene();
    virtual ~SoundMenuSampleScene();
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(SoundMenuSampleScene);
    
protected:
    
private:
    void setupMenu();
    cocos2d::MenuItem* createMenuItem(const char *text);
};

#endif /* defined(__cocos3__SoundMenuSampleScene__) */
