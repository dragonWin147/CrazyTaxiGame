#include "TurtleCar.h"
#include "../AppDelegate.h"

TurtleCar::TurtleCar() {
	actionForward = NULL;
	actionLeft = NULL;
	actionRight = NULL;
	colliPos = 0;
}
TurtleCar::~TurtleCar() {

}
TurtleCar* TurtleCar::turtleCar = NULL;
TurtleCar* TurtleCar::create(const char * pszFileName){
	if(turtleCar == NULL){
		turtleCar = new TurtleCar();
		if (turtleCar && turtleCar->initWithFile(pszFileName))
		{
			return turtleCar;
		}
		CC_SAFE_DELETE(turtleCar);
		return NULL;
	}else{
		return turtleCar;
	}
}
void TurtleCar::runActionForward(){
	if(actionForward == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("TurtleForward/Turtle Animation 1_Forward1.png");
		animation->addSpriteFrameWithFileName("TurtleForward/Turtle Animation 1_Forward2.png");
		animation->addSpriteFrameWithFileName("TurtleForward/Turtle Animation 1_Forward3.png");
		animation->addSpriteFrameWithFileName("TurtleForward/Turtle Animation 1_Forward4.png");
		animation->addSpriteFrameWithFileName("TurtleForward/Turtle Animation 1_Forward5.png");
		animation->addSpriteFrameWithFileName("TurtleForward/Turtle Animation 1_Forward6.png");
		animation->addSpriteFrameWithFileName("TurtleForward/Turtle Animation 1_Forward7.png");
		animation->addSpriteFrameWithFileName("TurtleForward/Turtle Animation 1_Forward8.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionForward = CCRepeatForever::create(animate);
		actionForward->retain();
	}
	turtleCar->runAction(actionForward);
}

void TurtleCar::runActionLeft(){
	if(actionLeft==NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("TurtleLeft/Turtle Animation 1_Left1.png");
		animation->addSpriteFrameWithFileName("TurtleLeft/Turtle Animation 1_Left2.png");
		animation->addSpriteFrameWithFileName("TurtleLeft/Turtle Animation 1_Left3.png");
		animation->addSpriteFrameWithFileName("TurtleLeft/Turtle Animation 1_Left4.png");
		animation->addSpriteFrameWithFileName("TurtleLeft/Turtle Animation 1_Left5.png");
		animation->addSpriteFrameWithFileName("TurtleLeft/Turtle Animation 1_Left6.png");
		animation->addSpriteFrameWithFileName("TurtleLeft/Turtle Animation 1_Left7.png");
		animation->addSpriteFrameWithFileName("TurtleLeft/Turtle Animation 1_Left8.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionLeft = CCRepeatForever::create(animate);
		actionLeft->retain();
	}
	turtleCar->runAction(actionLeft);
}

void TurtleCar::runActionRight(){
	if(actionRight == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("TurtleRight/Turtle Animation 1_Right1.png");
		animation->addSpriteFrameWithFileName("TurtleRight/Turtle Animation 1_Right2.png");
		animation->addSpriteFrameWithFileName("TurtleRight/Turtle Animation 1_Right3.png");
		animation->addSpriteFrameWithFileName("TurtleRight/Turtle Animation 1_Right4.png");
		animation->addSpriteFrameWithFileName("TurtleRight/Turtle Animation 1_Right5.png");
		animation->addSpriteFrameWithFileName("TurtleRight/Turtle Animation 1_Right6.png");
		animation->addSpriteFrameWithFileName("TurtleRight/Turtle Animation 1_Right7.png");
		animation->addSpriteFrameWithFileName("TurtleRight/Turtle Animation 1_Right8.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionRight = CCRepeatForever::create(animate);
		actionRight->retain();
	}
	turtleCar->runAction(actionRight);
}
void TurtleCar::createActionCrash(){
	CCAnimation* animation = CCAnimation::create();
	animation->addSpriteFrameWithFileName(
			"TurtleCrash/Turtle Animation 1_Crash1.png");
	animation->addSpriteFrameWithFileName(
			"TurtleCrash/Turtle Animation 1_Crash2.png");
	animation->addSpriteFrameWithFileName(
			"TurtleCrash/Turtle Animation 1_Crash3.png");
	animation->addSpriteFrameWithFileName(
			"TurtleCrash/Turtle Animation 1_Crash4.png");
	animation->addSpriteFrameWithFileName(
			"TurtleCrash/Turtle Animation 1_Crash5.png");
	animation->addSpriteFrameWithFileName(
			"TurtleCrash/Turtle Animation 1_Crash6.png");
	animation->addSpriteFrameWithFileName(
			"TurtleCrash/Turtle Animation 1_Crash7.png");
	animation->addSpriteFrameWithFileName(
			"TurtleCrash/Turtle Animation 1_Crash8.png");
	animation->setDelayPerUnit(0.1f);
	animateCrash = CCAnimate::create(animation);
}
void TurtleCar::stopActionForward(){
	if(actionForward)
	turtleCar->stopAction(actionForward);
}

void TurtleCar::stopActionLeft(){
	if(actionLeft)
	turtleCar->stopAction(actionLeft);
}

void TurtleCar::stopActionRight(){
	if(actionRight)
	turtleCar->stopAction(actionRight);
}







