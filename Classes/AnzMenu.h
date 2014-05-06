//
//  AnzMenu.h
//  cocos3
//
//  Created by ANZ on 2014/05/06.
//
//

#ifndef __cocos3__AnzMenu__
#define __cocos3__AnzMenu__

#include "cocos2d.h"

class AnzMenu : public cocos2d::Menu
{
    
public:
    AnzMenu();
    virtual ~AnzMenu();
    
    static AnzMenu* create(cocos2d::MenuItem* item, ...);
    static AnzMenu* createWithItems(cocos2d::MenuItem *firstItem, va_list args);
    static AnzMenu* createWithArray(const cocos2d::Vector<cocos2d::MenuItem*>& arrayOfItems);
    
    virtual bool initWithArray(const cocos2d::Vector<cocos2d::MenuItem*>& arrayOfItems);
    
    cocos2d::Menu::State getState();
    cocos2d::MenuItem* getCurrentMenuItem();
    
    // properties
    void setCallbackTracking(std::function<void(cocos2d::MenuItem*)> callback);
    void setSoundFilePath(const char *soundFilePath);
    void setSoundFilePath(const char *soundFilePath, bool isPreLoad);
    
protected:
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    
private:

    std::function<void(cocos2d::MenuItem*)> callbackTracking_;
    const char *soundFilePath_;
    
    void update(float dt);
    void soundEffect();
    
};

#endif /* defined(__cocos3__AnzMenu__) */
