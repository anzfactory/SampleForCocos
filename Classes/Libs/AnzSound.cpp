//
//  AnzSound.cpp
//  cocos3
//
//  Created by ANZ on 2014/05/24.
//
//

#include "AnzSound.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;


/*****************************************
 *  ( ‘ω’o[ PlayBGM ]o
 *****************************************/

PlayBGM* PlayBGM::create(const char *filePath)
{
    auto ret = new PlayBGM();
    ret->init(filePath);
    ret->autorelease();
    return ret;
}

PlayBGM* PlayBGM::clone() const
{
    auto ret = new PlayBGM();
    ret->autorelease();
    return ret;
}
ActionInstant* PlayBGM::reverse() const
{
    auto ret = new PlayBGM();
    ret->autorelease();
    return ret;
}

void PlayBGM::init(const char *filePath)
{
    filePath_ = filePath;
}

void PlayBGM::update(float time)
{
    CC_UNUSED_PARAM(time);
    SimpleAudioEngine::getInstance()->playBackgroundMusic(filePath_);
}

/*****************************************
 *  ( ‘ω’o[ StopBGM ]o
 *****************************************/

StopBGM* StopBGM::create()
{
    auto ret = new StopBGM();
    ret->autorelease();
    return ret;
}

StopBGM* StopBGM::clone() const
{
    auto ret = new StopBGM();
    ret->autorelease();
    return ret;
}

ActionInstant* StopBGM::reverse() const
{
    auto ret = new StopBGM();
    ret->autorelease();
    return ret;
}

void StopBGM::update(float time)
{
    CC_UNUSED_PARAM(time);
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}


/*****************************************
 *  ( ‘ω’o[ FadeToVolumeOfBGM ]o
 *****************************************/

FadeToVolumeOfBGM* FadeToVolumeOfBGM::create(float duration, float volume)
{
    auto ret = new FadeToVolumeOfBGM();
    ret->initWithDuration(duration, volume);
    ret->autorelease();
    return ret;
}

bool FadeToVolumeOfBGM::initWithDuration(float duration, float volume)
{
    if ( ! ActionInterval::initWithDuration(duration)) {
        return false;
    }
    
    toVolume_ = volume;
    
    return true;
}

FadeToVolumeOfBGM* FadeToVolumeOfBGM::clone() const
{
	// no copy constructor
	auto a = new FadeToVolumeOfBGM();
	a->initWithDuration(_duration, toVolume_);
	a->autorelease();
	return a;
}

FadeToVolumeOfBGM* FadeToVolumeOfBGM::reverse() const
{
	CCASSERT(false, "reverse() not supported in FadeToVolumeOfBGM");
	return nullptr;
}

void FadeToVolumeOfBGM::update(float time)
{
    auto vol = (fromVolume_ + (toVolume_ - fromVolume_) * time);
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(vol);
}

void FadeToVolumeOfBGM::startWithTarget(cocos2d::Node *target)
{
    ActionInterval::startWithTarget(target);
    
    fromVolume_ = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
}


