//
//  TopScene.h
//  cocos3
//
//  Created by ANZ on 2014/05/06.
//
//

#ifndef __cocos3__TopScene__
#define __cocos3__TopScene__

#include "cocos2d.h"

class TopScene : public cocos2d::Layer
{
    
public:
    TopScene();
    virtual ~TopScene();
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(TopScene);
    
protected:
    
private:
    
    enum TopMenuItem {
        kItemMenuSample = 0,
        kItemSoundMenuSample,
        kItemMenuOffsetSample,
        kItemCount,
    };
    enum Tags {
        kTagTopMenu = 1,
    };
    
    void createMenu();
    cocos2d::MenuItem* createMenuItem(const char *label, int currentCount);
    
    void tapMenu(cocos2d::Ref *sender);
    
};

#endif /* defined(__cocos3__TopScene__) */
