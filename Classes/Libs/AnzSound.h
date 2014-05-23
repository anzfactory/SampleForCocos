//
//  AnzSound.h
//  cocos3
//
//  Created by ANZ on 2014/05/24.
//
//

#ifndef __cocos3__AnzSound__
#define __cocos3__AnzSound__

#include "cocos2d.h"

/**
 * @brief BGMを鳴らす
 */
class PlayBGM : public cocos2d::ActionInstant
{
    
public:
    PlayBGM(){}
    virtual ~PlayBGM(){}
    
    /** @return nullptr */
    static PlayBGM* create(){ return nullptr; }
    /**
     * @param filePath 音源ファイルパス
     * @param doPreload preloadを実行するか
     */
    static PlayBGM* create(const char* filePath);
    virtual PlayBGM* clone() const;
    virtual cocos2d::ActionInstant *reverse() const;
    virtual void update(float time) override;
    
    void init(const char* filePath);
    
protected:
    
private:
    const char* filePath_;
};

/**
 * @brief BGMをストップ
 */
class StopBGM : public cocos2d::ActionInstant
{
    
public:
    StopBGM(){}
    virtual ~StopBGM(){}
    
    static StopBGM* create();
    virtual StopBGM* clone() const;
    virtual cocos2d::ActionInstant *reverse() const;
    virtual void update(float time) override;
    
protected:
    
private:
};


/**
 * @brief BGMの音量を指定された値に徐々にしていく
 */
class FadeToVolumeOfBGM : public cocos2d::ActionInterval
{
    
public:
    FadeToVolumeOfBGM(){}
    virtual ~FadeToVolumeOfBGM(){}
    
    /**
     * @param duration 時間
     * @param 最終的にするボリュームの値
     */
    static FadeToVolumeOfBGM* create(float duration, float volume);
    virtual FadeToVolumeOfBGM* clone() const;
    virtual FadeToVolumeOfBGM* reverse(void) const;
    virtual void update(float time) override;
    virtual void startWithTarget(cocos2d::Node *target) override;
    
protected:
    
    virtual bool initWithDuration(float duration, float volume);
    
private:
    float toVolume_;
    float fromVolume_;
};



#endif /* defined(__cocos3__AnzSound__) */
