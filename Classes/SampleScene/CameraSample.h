//
//  CameraSample.h
//  cocos3
//
//  Created by ANZ on 2014/05/17.
//
//

#ifndef __cocos3__CameraSample__
#define __cocos3__CameraSample__

#include "cocos2d.h"

class CameraSample : public cocos2d::Layer
{
    
public:
    CameraSample();
    virtual ~CameraSample();
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(CameraSample);
    
    virtual void onEnterTransitionDidFinish();
    
protected:
    
private:
    
    enum Tags {
        kTagCamleraLayer = 1,
    };
    
    cocos2d::Vector<cocos2d::Label*> items_;
    cocos2d::ActionCamera *camera_;
    
    void setCamera();
    
    void prepare();
    
    void throwWord(cocos2d::Vector<cocos2d::Label*>::iterator it);
    void completed(cocos2d::Vector<cocos2d::Label*>::iterator it);
    
};

#endif /* defined(__cocos3__CameraSample__) */
