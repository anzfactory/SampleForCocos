//
//  MenuSampleScene.h
//  cocos3
//
//  おしっぱ判定サンプル
//
//  Created by ANZ on 2014/05/06.
//
//

#ifndef __cocos3__MenuSampleScene__
#define __cocos3__MenuSampleScene__

#include "cocos2d.h"

class MenuSampleScene : public cocos2d::Layer
{
    
public:
    MenuSampleScene();
    virtual ~MenuSampleScene();
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(MenuSampleScene);
    
protected:
    
private:
    
    enum ControlMenu {
        kUp = 1,
        kDown,
        kLeft,
        kRight,
    };
    
    enum Tags {
        kTagBoad = 1,
        kTagControlMenu,
        kTagMenu,
    };
    
    enum ZOrder {
        kBackground = 1,
        kForeground,
    };
    
    // ui create
    void setupBoard();
    void setupControlPanel();
    void setupMenu();
    cocos2d::MenuItem* createMenuItem(const char *text, int tag);
    
    // tap
    void tapControl(cocos2d::MenuItem *selectedItem);

};

#endif /* defined(__cocos3__MenuSampleScene__) */
