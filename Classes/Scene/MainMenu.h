#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"
#include "TurtleCar.h"
#include "XTLayer.h"
#include "Resourses.h"
#include "Car.h"
#include "CCDate.h"
#include "Database.h"
#include "../NDKHelper/NDKHelper.h"
USING_NS_CC;
class MainMenu: public XTLayer {
private:
	CCSprite* background_1;
	CCSprite* background_2;
	CCSprite* scoreGame;
	CCSprite* timeGame;
	CCLayer* controlGame;
	CCLayer* layerGameOver;
	CCLayer* layerStar;
	CCLayer* readyGame;
	CCLayer* layerCar;
	CCSize visibleSize;
	CCSprite* ready_1;
	CCSprite* ready_2;
	CCSprite* ready_3;
	CCSprite* ready_4;
	CCSprite* swipe_ready;
	CCSprite* timeSprite_1;
	CCSprite* timeSprite_2;
	CCSprite* timeSprite_3;
	CCSprite* scoreSprite;
	TurtleCar *turtleCar;
	CCRenderTexture *_rt;
	int swipeMaxMomentum ;
	float stepSperMomentum ;
	int moveChangesPerRandom ;
	float swipePerMomentumRandom_1 ;
	float swipePerMomentumRandom_2 ;
	float swipePerMomentumRandom_3 ;
	float miniReleaseCarTime;
	int randomMovementsPerTime ;
	int numberMovements;
	int momentums;
	int timeHover;
	int lane;
	int posStarCount;
	int releaseTime;
	int backgroundscrollspeed;
	float distance;
	bool startGame;
	bool leftMoving;
	bool rightMoving;
	bool randomMomentums;
	bool colliLeftSide;
	bool colliRightSide;
	bool firstAppearance;
	bool leftRoad;
	bool centerRoad;
	bool rightRoad;
	bool modeHover;
	int score;
	int time;
	int hightScore;
	int numberGames;
	CCDate* date;
	CCSprite* titleGameOver;
	CCSprite* gameOverBk;
	CCString * timeStr;
	CCMenuItemImage* leaderGameButton;
	CCArray *listCar;
	Database* database;
	MainMenu();
	static MainMenu* instance;
	~MainMenu();
public:
	int *x_star;
	int *y_star;
	virtual bool init();
	void onEnter();
	static CCScene* scene();

	static MainMenu* getInstance();
	void playGame(CCObject* obj);
	void menuCloseCallback(CCObject* pSender);
	void initlayerControl();
	void initLayerReady();
	void randomMapRes();
	void initLayerGameOver();
	void leaderGame(CCObject* obj);
	void sceneReady();
	void stateReady(float dt);
	void updateGame(float dt);
	void updateMusic(float dt);
	void timerRandomMomentums(float dt);
	void runGame();
	void scaleNode(CCNode *node);
	void updatePosTurtle();
	void gameOver();
	void updateBackGround();
	void tryAgain();
	void initValueGame();
	void collisionSideOfRoad();
	void collisionCar();
	void createBlueCar();
	void createBlueTruckCar();
	void createOrangeCar();
	void createPinkCar();
	void handleColliSide();
	void updateScore();
	void updateTime(float dt);
	void starMoveFinished(CCNode* sender, void * d);
	void setLaneCar();
	void randomModeHover();
	void saveData(int score);
	void starAnimation(float dt);
	void randomPosStar();
	bool checkScoreInit(int i);
	void sche_timeModeHover(float dt);
	void sche_timeModeFlash(float dt);
	void postScoreFaceBook(CCObject* obj);
	void postScoreFaceBookSuccess();
	void postScoreTwitter(CCObject* obj);
	void postScoreTwitterSuccess();
	void likeFaceBook(CCObject* obj);
	void ratingApp(CCObject* obj);
	void likeFaceBookSuccess();
	void showAdvertisementTop(float dt);
	void showAdvertisementCenter(float dt);
	void hideAds(float dt);
	void showAdsSuccess();
	void hideAdsSuccess();
	void delayStarAniamation(float dt);
	CCBezierTo *colliCar();
	void carAppearanceRandom(float dt);
	void updatePositionCar(float dt);
	int randomReleaseTime();
	bool isPointer(CCNode* node, CCPoint pos) ;
	float positionXCarRelease();
	//Swipe
	virtual void xtTouchesBegan(cocos2d::CCSet* _touches,cocos2d::CCEvent* event);
	virtual void xtTouchesMoved(cocos2d::CCSet* _touches,cocos2d::CCEvent* event);
	virtual void xtTouchesEnded(cocos2d::CCSet* _touches,cocos2d::CCEvent* event);

	virtual void xtTouchesBegan(CCPoint position);
	virtual void xtTouchesMoved(CCPoint position);
	virtual void xtTouchesEnded(CCPoint position);

	virtual void xtTapGesture(CCPoint position);
	virtual void xtDoubleTapGesture(CCPoint position);
	virtual void xtLongTapGesture(CCPoint position);
	virtual void xtSwipeGesture(XTTouchDirection direction, float distance,float speed);

	CREATE_FUNC(MainMenu)
	;
};

#endif // __MAINMENU_SCENE_H__
