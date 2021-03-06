#ifndef __TurtleCar_SCENE_H__
#define __TurtleCar_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class TurtleCar: public CCSprite {
private:
	TurtleCar();
	~TurtleCar();
	static TurtleCar * turtleCar;
	CCAction* actionForward;
	CCAction* actionLeft;
	CCAction* actionRight;
	CCAction* actionHover;
public:
	CCAnimate *animateCrash;
public:

	// returns a pointer to new Ball instance.
	int keySoundHover;
	int keyAlmostScore;
	int keyEqualScore;
	static TurtleCar* create(const char *pszFileName);
	void runActionForward();
	void runActionLeft();
	void runActionRight();
	void createActionCrash();
	void stopActionForward();
	void stopActionLeft();
	void stopActionRight();
	void runActionHoverMode();
	void stopActionHoverMode();
	void runActionFlash();
	int colliPos;
};

#endif // __TurtleCar_SCENE_H__
