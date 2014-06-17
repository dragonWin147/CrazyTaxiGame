#include "MainMenu.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "../AppDelegate.h"
#include "SoundManager.h"
using namespace CocosDenshion;
using namespace std;
MainMenu* MainMenu::instance = NULL;

MainMenu* MainMenu::getInstance() {
	if (instance == NULL) {
		instance = new MainMenu();
	}
	return instance;
}
MainMenu::MainMenu() {
	initValueGame();
	controlGame = NULL;
	layerGameOver = NULL;
	layerStar = NULL;
	readyGame = NULL;
	layerCar = NULL;
	firstAppearance = false;
	releaseTime = 0;
	listCar = new CCArray();
	x_star = (int*)calloc(20,sizeof(int));
	y_star = (int*)calloc(20,sizeof(int));
	numberGames = 0;

}
MainMenu::~MainMenu() {

}

CCScene* MainMenu::scene() {
	CCScene *scene = CCScene::create();

	MainMenu *layer = MainMenu::create();

	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MainMenu::init() {
	if (!CCLayer::init()) {
		return false;
	}
	this->setTouchEnabled(true);
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

//	initNumber();
	CCLog("MainMenu::init()");
	database = new Database();
	randomPosStar();
	background_1 = CCSprite::create("FinalPNG/City_Background.png");
	background_1->setAnchorPoint(ccp(0,0));
	scaleNode(background_1);
	background_1->setPosition(ccp(0,0));
	this->addChild(background_1);

	background_2 = CCSprite::create("FinalPNG/City_Background.png");
	background_2->setAnchorPoint(ccp(0,0));
	scaleNode(background_2);
	background_2->setPosition(ccp(0,visibleSize.height));
	this->addChild(background_2);

	randomMapRes();

	timeGame = CCSprite::create("FinalPNG/TT_Scorebadge.png");
	scaleNode(timeGame);
	timeGame->setPosition(
			ccp(timeGame->boundingBox().size.width/2 + 10 *AppDelegate::getScaleX(),visibleSize.height - timeGame->boundingBox().size.height/2 - 10 *AppDelegate::getScaleY()));
	this->addChild(timeGame);

	timeSprite_1 = CCSprite::create();
	timeSprite_1->setDisplayFrame(database->getNumberFont(0)->displayFrame());
	timeGame->addChild(timeSprite_1);
	timeSprite_1->setPosition(ccp(timeSprite_1->getContentSize().width/2,timeGame->getContentSize().height/2));


	CCSprite *_cham = CCSprite::create();
	_cham->setDisplayFrame(database->getKey(3));
	timeSprite_1->addChild(_cham);
	_cham->setPosition(ccp(timeSprite_1->getContentSize().width,0));

	timeSprite_2 = CCSprite::create();
	timeSprite_2->setDisplayFrame
			(database->getNumberFont(0)->displayFrame());
	timeGame->addChild(timeSprite_2);
	timeSprite_2->setPosition(ccp(timeSprite_2->getContentSize().width,timeGame->getContentSize().height/2));

	timeSprite_3 = CCSprite::create();
	timeSprite_3->setDisplayFrame
			(database->getNumberFont(0)->displayFrame());
	timeGame->addChild(timeSprite_3);
	timeSprite_3->setPosition(ccp(timeSprite_3->getContentSize().width*3/2,timeGame->getContentSize().height/2));

	timeSprite_1->setScale(0.5f);
	timeSprite_2->setScale(0.5f);
	timeSprite_3->setScale(0.5f);

	scoreGame = CCSprite::create("FinalPNG/TT_Scorebadge.png");
	scaleNode(scoreGame);
	scoreGame->setPosition(
			ccp(visibleSize.width - scoreGame->boundingBox().size.width/2 - 10 *AppDelegate::getScaleX(),timeGame->getPositionY()));
	this->addChild(scoreGame);


	scoreSprite = CCSprite::create();
	scoreSprite = database->getNumberFont(0);
	scoreGame->addChild(scoreSprite);
	scoreSprite->setPosition(ccp(scoreGame->getContentSize().width/2, scoreGame->getContentSize().height/2));


	scoreGame->setVisible(false);
	timeGame->setVisible(false);

	turtleCar = TurtleCar::create(
			"TurtleForward/Turtle Animation 1_Forward1.png");
	turtleCar->retain();
//	scaleNode(turtleCar);
	turtleCar->setScaleX(AppDelegate::getScaleX()*1.2f);
	turtleCar->setScaleY(AppDelegate::getScaleY()*1.2f);
	turtleCar->setPosition(ccp( visibleSize.width/2,turtleCar->boundingBox().size.height));
	this->addChild(turtleCar,1000);

	initlayerControl();
	layerCar = CCLayer::create();
	layerCar->retain();
	this->addChild(layerCar);

	date = new CCDate();
	timeStr = CCString::createWithFormat("%d/%d/%d", date->mday(), date->month(), date->year());
	timeStr->retain();
	return true;
}
void MainMenu::randomMapRes(){
	int randomMap = rand()%2;
	const char * mapRes;
	if(randomMap == 0)
		mapRes = "FinalPNG/Country Background.png";
	else
		mapRes = "FinalPNG/City_Background.png";

	background_1->setTexture(CCSprite::create(mapRes)->getTexture());
	background_1->setTextureRect(CCSprite::create(mapRes)->getTextureRect());

	background_2->setTexture(CCSprite::create(mapRes)->getTexture());
	background_2->setTextureRect(CCSprite::create(mapRes)->getTextureRect());
}
void MainMenu::onEnter(){
	CCLayer::onEnter();
	SoundManager::gI()->playSoundBackground(TT_Title);

	NDKHelper::AddSelector("Selectors", "postScoreFaceBookSuccess",
	callfuncND_selector(MainMenu::postScoreFaceBookSuccess), this);

	NDKHelper::AddSelector("Selectors", "postScoreTwitterSuccess",
	callfuncND_selector(MainMenu::postScoreTwitterSuccess), this);

	NDKHelper::AddSelector("Selectors", "likeFaceBookSuccess",
	callfuncND_selector(MainMenu::likeFaceBookSuccess), this);

	NDKHelper::AddSelector("Selectors", "showAdsSuccess",
	callfuncND_selector(MainMenu::showAdsSuccess), this);

	NDKHelper::AddSelector("Selectors", "hideAdsSuccess",
	callfuncND_selector(MainMenu::hideAdsSuccess), this);
}

void MainMenu::initlayerControl() {
	controlGame = CCLayer::create();
	controlGame->retain();
	CCSprite* titleGame = CCSprite::create("FinalPNG/TT_Title.png");
	scaleNode(titleGame);
	titleGame->setPosition(
			ccp(visibleSize.width/2,visibleSize.height - titleGame->boundingBox().size.height/2 - 100*AppDelegate::getScaleY()));
	controlGame->addChild(titleGame);

	CCMenuItemImage* startGame = CCMenuItemImage::create(
			"FinalPNG/TT_StartButton_OFF.png", "FinalPNG/TT_StartButton_ON.png",
			this, menu_selector(MainMenu::playGame));
	scaleNode(startGame);
	startGame->setPosition(
			ccp(startGame->boundingBox().size.width/2 + 50*AppDelegate::getScaleX(),startGame->boundingBox().size.height*3/2));

	CCMenuItemImage* rateGame = CCMenuItemImage::create(
			"FinalPNG/TT_RateButton_OFF.png", "FinalPNG/TT_RateButton_ON.png",
			this, menu_selector(MainMenu::ratingApp));
	scaleNode(rateGame);
	rateGame->setPosition(
			ccp(visibleSize.width/2,startGame->getPositionY() + startGame->boundingBox().size.height));

	CCMenuItemImage* leaderGame = CCMenuItemImage::create(
			"FinalPNG/TT_LeaderButton_OFF.png",
			"FinalPNG/TT_LeaderButton_ON.png", this,
			menu_selector(MainMenu::leaderGame));
	scaleNode(leaderGame);
	leaderGame->setPosition(
			ccp(visibleSize.width - leaderGame->boundingBox().size.width /2 - 50*AppDelegate::getScaleX() ,startGame->getPositionY()));


	CCMenuItemImage* facebookLike = CCMenuItemImage::create(
			"FinalPNG/Facebook.png",
			"FinalPNG/Facebook.png", this,
			menu_selector(MainMenu::likeFaceBook));
	scaleNode(facebookLike);
	facebookLike->setPosition(
			ccp(visibleSize.width /5 ,rateGame->getPositionY()));

	CCMenu* pMenu = CCMenu::create(rateGame,startGame, leaderGame,facebookLike, NULL);
	pMenu->setPosition(CCPointZero);
	controlGame->addChild(pMenu, 1);
	this->addChild(controlGame);
}

void MainMenu::initLayerReady() {
	readyGame = CCLayer::create();
	readyGame->retain();

	ready_1 = CCSprite::create("FinalPNG/TT_Ready_1.png");
	scaleNode(ready_1);
	ready_1->setPosition(
			ccp(visibleSize.width/2,visibleSize.height - ready_1->boundingBox().size.height /2 - 170 *AppDelegate::getScaleY()));

	ready_2 = CCSprite::create("FinalPNG/TT_Ready_2.png");
	scaleNode(ready_2);
	ready_2->setPosition(ccp(visibleSize.width/2,ready_1->getPositionY() ));

	ready_3 = CCSprite::create("FinalPNG/TT_Ready_3.png");
	scaleNode(ready_3);
	ready_3->setPosition(ccp(visibleSize.width/2,ready_1->getPositionY() ));

	ready_4 = CCSprite::create("FinalPNG/TT_Ready_4GO.png");
	scaleNode(ready_4);
	ready_4->setPosition(ccp(visibleSize.width/2,ready_1->getPositionY() ));

	readyGame->addChild(ready_1, 4);
	readyGame->addChild(ready_2, 3);
	readyGame->addChild(ready_3, 2);
	readyGame->addChild(ready_4, 1);

	swipe_ready = CCSprite::create("FinalPNG/TT_SwipeWord.png");
	scaleNode(swipe_ready);
	swipe_ready->setPosition(turtleCar->getPosition());
	readyGame->addChild(swipe_ready);

	this->addChild(readyGame);
}

void MainMenu::initLayerGameOver(){
	layerGameOver = CCLayer::create();
	layerGameOver->retain();

	CCSprite* titleSmall = CCSprite::create("FinalPNG/TT_Title_SMALL.png");
	scaleNode(titleSmall);
	titleSmall->setPosition(
			ccp(visibleSize.width/2,visibleSize.height - titleSmall->boundingBox().size.height/2 - 20 *AppDelegate::getScaleY()));
	layerGameOver->addChild(titleSmall);

	titleGameOver = CCSprite::create("FinalPNG/TT_GameOverTitle.png");
	scaleNode(titleGameOver);
	titleGameOver->setPosition(
			ccp(visibleSize.width/2,visibleSize.height - titleGameOver->boundingBox().size.height/2 - 200*AppDelegate::getScaleY()));
	layerGameOver->addChild(titleGameOver);

	gameOverBk = CCSprite::create("FinalPNG/TT_GameOverScoreBackground.png");
	scaleNode(gameOverBk);
	gameOverBk->setPosition(
			ccp(visibleSize.width/2,titleGameOver->getPositionY() - titleGameOver->boundingBox().size.height/2 - gameOverBk->boundingBox().size.height/2));
	layerGameOver->addChild(gameOverBk);

	CCSprite* scoreLabel = database->getNumberFont(score);
	scoreLabel->setAnchorPoint(ccp(0,0.5f));
	gameOverBk->addChild(scoreLabel);
	scoreLabel->setPosition(
			ccp(gameOverBk->getContentSize().width/2 , gameOverBk->getContentSize().height * 0.85));

	CCSprite* timeLabel_1 = database->getNumberFont(time/60);
	timeLabel_1->setAnchorPoint(ccp(0,0.5));
	gameOverBk->addChild(timeLabel_1);
	timeLabel_1->setPosition(
			ccp(scoreLabel->getPositionX(), gameOverBk->getContentSize().height * 0.7));

	CCSprite* _c = CCSprite::create();
	_c->setAnchorPoint(ccp(0,0.5));
	_c->setDisplayFrame(database->getKey(1));
	gameOverBk->addChild(_c);
	_c->setPosition(
			ccp(timeLabel_1->getPositionX() + timeLabel_1->getContentSize().width, timeLabel_1->getPositionY()));

	CCSprite* timeLabel_2 = database->getNumberFont((time%60)/10);
	timeLabel_2->setAnchorPoint(ccp(0,0.5));
	gameOverBk->addChild(timeLabel_2);
	timeLabel_2->setPosition(
			ccp(_c->getPositionX() + _c->getContentSize().width, timeLabel_1->getPositionY()));

	CCSprite* timeLabel_3 = database->getNumberFont(time%10);
	gameOverBk->addChild(timeLabel_3);
	timeLabel_3->setPosition(
			ccp(timeLabel_2->getPositionX() + timeLabel_2->getContentSize().width + 10, timeLabel_1->getPositionY()));


	int scoreData = CCUserDefault::sharedUserDefault()->getIntegerForKey("highScore0",0);

	CCSprite* highScore = database->getNumberFont(scoreData);
	highScore->setAnchorPoint(ccp(0,0.5));
	gameOverBk->addChild(highScore);
	highScore->setPosition(
			ccp(gameOverBk->getContentSize().width*2/3 , gameOverBk->getContentSize().height * 0.45f));

	int scoreOfDay = CCUserDefault::sharedUserDefault()->getIntegerForKey(timeStr->getCString(),0);

	CCSprite* highScoreOfDay = database->getNumberFont(scoreOfDay);
	highScoreOfDay->setAnchorPoint(ccp(0,0.5));
	gameOverBk->addChild(highScoreOfDay);
	highScoreOfDay->setPosition(
			ccp(highScore->getPositionX(), gameOverBk->getContentSize().height * 0.28));
	if(score >= scoreOfDay*0.8f && score < scoreOfDay) {
		CCSprite* almost = CCSprite::create("FinalPNG/TT_AlmostBadge.png");
		almost->setAnchorPoint(ccp(0,0));
		gameOverBk->addChild(almost);
		almost->setPosition(
				ccp(highScore->getPositionX(), highScore->getPositionY() + 65));
	}else if(score == scoreOfDay) {
		CCSprite* equal = CCSprite::create("FinalPNG/TT_SameBadge.png");
		equal->setAnchorPoint(ccp(0,0));
		gameOverBk->addChild(equal);
		equal->setPosition(
				ccp(highScore->getPositionX(), highScore->getPositionY() + 65));
	}
	else if (score > scoreOfDay) {
		CCSprite* better = CCSprite::create("FinalPNG/TT_NewBadge.png");
		better->setAnchorPoint(ccp(0,0));
		gameOverBk->addChild(better);
		better->setPosition(
				ccp(highScore->getPositionX(), highScore->getPositionY() + 65));

		if(layerStar == NULL){
			layerStar = CCLayer::create();
			layerStar->retain();
		}
		schedule(schedule_selector(MainMenu::starAnimation));
	}
	//------------------------------------------
	CCMenuItemImage* startGame = CCMenuItemImage::create(
			"FinalPNG/TT_StartButton_OFF.png", "FinalPNG/TT_StartButton_ON.png",
			this, menu_selector(MainMenu::playGame));
	scaleNode(startGame);
	startGame->setPosition(
			ccp(startGame->boundingBox().size.width/2 + 50*AppDelegate::getScaleX(),gameOverBk->getPositionY()- gameOverBk->boundingBox().size.height/2 - startGame->boundingBox().size.height/2));

	leaderGameButton = CCMenuItemImage::create(
			"FinalPNG/TT_LeaderButton_OFF.png",
			"FinalPNG/TT_LeaderButton_ON.png", this,
			menu_selector(MainMenu::leaderGame));
	scaleNode(leaderGameButton);
	leaderGameButton->setPosition(
			ccp(visibleSize.width - leaderGameButton->boundingBox().size.width /2 - 50*AppDelegate::getScaleX() ,startGame->getPositionY()));

	CCMenu* pMenu = CCMenu::create(startGame, leaderGameButton, NULL);
	pMenu->setPosition(CCPointZero);
	layerGameOver->addChild(pMenu, 1);
	this->addChild(layerGameOver);

	layerStar = CCLayer::create();
	layerStar->retain();
	layerGameOver->addChild(layerStar,100);
}
void MainMenu::leaderGame(CCObject* obj){
	SoundManager::gI()->playSoundEffect(TT_Button_Press);
	if(controlGame)
		controlGame->setVisible(false);

	if(layerGameOver == NULL){
		initLayerGameOver();
	}

	if(layerStar){
		CCLOG("layerStar false");
		layerStar->removeAllChildrenWithCleanup(true);
		layerStar->release();
		layerStar = NULL;
	}
	titleGameOver->setTexture(CCSprite::create("FinalPNG/TT_LeaderTitle.png")->getTexture());
	titleGameOver->setTextureRect(CCSprite::create("FinalPNG/TT_LeaderTitle.png")->getTextureRect());

	gameOverBk->removeAllChildrenWithCleanup(true);
	gameOverBk->setTexture(CCSprite::create("FinalPNG/TT_LeaderBoard.png")->getTexture());
	gameOverBk->setTextureRect(CCSprite::create("FinalPNG/TT_LeaderBoard.png")->getTextureRect());
	leaderGameButton->setVisible(false);

	for(int i = 0 ; i <8 ; i++){
		CCString* str = CCString::createWithFormat("%s%d", "highScore", i);
		CCSprite* sprite = database->drawScore(str->getCString());
		gameOverBk->addChild(sprite);
		sprite->setAnchorPoint(ccp(0,0.5f));
		sprite->setPosition(ccp(gameOverBk->getContentSize().width * 0.44f,gameOverBk->getContentSize().height*0.87f -
				gameOverBk->getContentSize().height*0.085f * i));
	}

	CCMenuItemImage* faceBook = CCMenuItemImage::create(
			"FinalPNG/Facebook.png", "FinalPNG/Facebook.png",
			this, menu_selector(MainMenu::postScoreFaceBook));
	scaleNode(faceBook);
	faceBook->setPosition(
			ccp(faceBook->boundingBox().size.width/2 + visibleSize.width/2
					,gameOverBk->getPositionY()- gameOverBk->boundingBox().size.height/2 - faceBook->boundingBox().size.height/2 - 20*AppDelegate::getScaleY()));

	CCMenuItemImage* twitter = CCMenuItemImage::create(
			"FinalPNG/Twitter_logo_blue.png", "FinalPNG/Twitter_logo_blue.png",
			this, menu_selector(MainMenu::postScoreTwitter));
	scaleNode(twitter);
	twitter->setPosition(
			ccp(twitter->boundingBox().size.width *2/3 + visibleSize.width/2 + faceBook->boundingBox().size.width
					,faceBook->getPositionY()));

	CCMenu* pMenu = CCMenu::create(faceBook, twitter, NULL);
	pMenu->setPosition(CCPointZero);
	layerGameOver->addChild(pMenu, 1);
}

void MainMenu::postScoreFaceBook(CCObject* obj){
	CCDictionary *dic = CCDictionary::create();
	dic->setObject(CCString::createWithFormat("%d", score), "score");
	SendMessageWithParams(string("postScoreFaceBook"), dic);
}

void MainMenu::postScoreTwitter(CCObject* obj){
	CCDictionary *dic = CCDictionary::create();
	dic->setObject(CCString::createWithFormat("%d",score),"score");
	SendMessageWithParams(string("postScoreTwitter"),dic);
}

void MainMenu::likeFaceBook(CCObject* obj){
	SendMessageWithParams(string("likeFaceBook"), NULL);
}

void MainMenu::ratingApp(CCObject* obj){
	SendMessageWithParams(string("ratingApp"), NULL);
}


void MainMenu::showAdvertisementTop(float dt){
	if(time % 6 == 0 ){
		SendMessageWithParams(string("showAdsTop"),NULL);
	}
}

void MainMenu::showAdvertisementCenter(float dt){
	if(numberGames % 6 == 2 || numberGames % 6 == 4){
		CCLog("showAdvertisementCenter %d",numberGames);
		SendMessageWithParams(string("showAdsCenter"),NULL);
	}
}
void MainMenu::hideAds(float dt){
	SendMessageWithParams(string("hideAds"),NULL);
}
void MainMenu::postScoreFaceBookSuccess(){
	CCLog("postScoreFaceBookSuccess");
}

void MainMenu::postScoreTwitterSuccess(){
	CCLog("postScoreTwitterSuccess");
}

void MainMenu::likeFaceBookSuccess(){
	CCLog("likeFaceBookSuccess");
}

void MainMenu::showAdsSuccess(){
	if(startGame){
		scheduleOnce(schedule_selector(MainMenu::hideAds),3);
		CCLog("showAdsSuccess");
	}
}

void MainMenu::hideAdsSuccess(){
	CCLog("hideAdsSuccess");
}

void MainMenu::saveData(int score){
	int scoreData = CCUserDefault::sharedUserDefault()->getIntegerForKey("highScore0",0);
	int scoreOfDay = CCUserDefault::sharedUserDefault()->getIntegerForKey(timeStr->getCString(),0);
	if(score > scoreOfDay)
		CCUserDefault::sharedUserDefault()->setIntegerForKey(timeStr->getCString(),score);

	int _score;
	for (int i = 0; i < 8; i++) {
		CCString* str = CCString::createWithFormat("%s%d", "highScore", i);
		_score = CCUserDefault::sharedUserDefault()->getIntegerForKey(
				str->getCString(), 0);
		if (score > _score) {
				CCString* str_day = CCString::createWithFormat("%s%s", str->getCString(), "day");
				CCString* str_month = CCString::createWithFormat("%s%s", str->getCString(), "month");
				CCString* str_year = CCString::createWithFormat("%s%s", str->getCString(), "year");
				CCUserDefault::sharedUserDefault()->setIntegerForKey(
						str->getCString(), score);
				CCUserDefault::sharedUserDefault()->setIntegerForKey(
						str_day->getCString(), date->mday());
				CCUserDefault::sharedUserDefault()->setIntegerForKey(
						str_month->getCString(), date->month());
				CCUserDefault::sharedUserDefault()->setIntegerForKey(
						str_year->getCString(), date->year());
				if(_score > 0 )
					saveData(_score);
				break;
		}
	}

}
bool MainMenu::checkScoreInit(int i){
	if(i < 7){
		CCString* str = CCString::createWithFormat("%s%d", "highScore", i);
		int _score = CCUserDefault::sharedUserDefault()->getIntegerForKey(
				str->getCString(), 0);
		if(_score > 0)
			return true;
		else
			return false;
	}else
		return true;

}
void MainMenu::stateReady(float dt) {
	if (ready_1->isVisible()){
		SoundManager::gI()->playSoundEffect(TT_LightCountDownRed);
		ready_1->setVisible(false);
	}
	else if (ready_2->isVisible()){
		SoundManager::gI()->playSoundEffect(TT_LightCountDownRed);
		ready_2->setVisible(false);
	}
	else if (ready_3->isVisible()){
		SoundManager::gI()->playSoundEffect(TT_LightCountDownGreen);
		ready_3->setVisible(false);
	}
	else if (ready_4->isVisible()) {

		ready_4->setVisible(false);
		swipe_ready->setVisible(false);
		unschedule(schedule_selector(MainMenu::stateReady));
		schedule(schedule_selector(MainMenu::carAppearanceRandom));
		runGame();
	}
}
void MainMenu::randomPosStar(){
	int x = 0;
	int y = 0;
	for(int i = 0 ; i < 15 ; i++){
		if(i < 3){
			x =  50 * AppDelegate::getScaleX() * (1 - i) + arc4random()%(int)(visibleSize.width/3) + visibleSize.width * i/3;
			y = visibleSize.height - 300 * AppDelegate::getScaleY();
		}
		else if(i < 5){
			x =  100 * AppDelegate::getScaleX() * (0.5 - (i%2)) + arc4random()%(int)(visibleSize.width/2) + visibleSize.width * (i%2)/2;
			y = visibleSize.height - 600 * AppDelegate::getScaleY();
		}
		else if(i < 8){
			x =  50 * AppDelegate::getScaleX() * (1 - (i%3)) + arc4random()%(int)(visibleSize.width/3) + visibleSize.width * (i%3)/3;
			y = visibleSize.height - 900 * AppDelegate::getScaleY();
		}
		else if(i < 10){
			x =  100 * AppDelegate::getScaleX() * (0.5 - (i%2)) + arc4random()%(int)(visibleSize.width/2) + visibleSize.width * (i%2)/2;
			y = visibleSize.height - 1200 * AppDelegate::getScaleY();
		}
		else if(i < 13){
			x =  50 * AppDelegate::getScaleX() * (1 - (i%3)) + arc4random()%(int)(visibleSize.width/3) + visibleSize.width * (i%3)/3;
			y = visibleSize.height - 1500 * AppDelegate::getScaleY();
		}
		else if(i < 15){
			x =  100 * AppDelegate::getScaleX() * (0.5 - (i%2)) + arc4random()%(int)(visibleSize.width/2) + visibleSize.width * (i%2)/2;
			y = visibleSize.height - 1800 * AppDelegate::getScaleY();
		}
		x_star[i] = x;
		y_star[i] = y;
	}
}
void MainMenu::starAnimation(float dt){
	if(posStarCount >= 14){
		posStarCount = 0;
		unschedule(schedule_selector(MainMenu::starAnimation));
		randomPosStar();
		scheduleOnce(schedule_selector(MainMenu::delayStarAniamation),2);
	}
	CCSprite *star = CCSprite::create("FinalPNG/star.png");
	int begin_X = x_star[posStarCount];
	int end_Y = y_star[posStarCount];
	star->setScale(AppDelegate::getMinScale());
	star->setPosition(ccp(begin_X,visibleSize.height + star->boundingBox().size.width));
	layerStar->addChild(star);
	CCMoveTo* move = CCMoveTo::create(2,ccp(star->getPositionX(), end_Y));
    CCActionInterval* move_ease = CCEaseBackInOut::create((CCActionInterval*)(move->copy()->autorelease()) );
	star->runAction(move_ease);
	posStarCount ++;
}

void MainMenu::delayStarAniamation(float dt){
	if(layerStar){
		layerStar->removeAllChildrenWithCleanup(true);
		schedule(schedule_selector(MainMenu::starAnimation));
	}
}

void MainMenu::carAppearanceRandom(float dt){
	unschedule(schedule_selector(MainMenu::carAppearanceRandom));
	setLaneCar();
	int r_1 = rand()% 6;
	CCLOG("MainMenu::carAppearanceRandom %d",r_1);
	if (r_1 < 4) {
		//create Car
		int r_2 = rand() % 3;
		if (r_2 == 0) {
			//create Blue
			CCLOG("MainMenu::carAppearanceRandom1");
			createBlueCar();
		} else if (r_2 == 1) {
			//create Pink
			CCLOG("MainMenu::carAppearanceRandom2");
			createPinkCar();
		} else if (r_2 == 2) {
			//create Orange
			CCLOG("MainMenu::carAppearanceRandom3");
			createOrangeCar();
		}
	} else {
		//create truck
		CCLOG("MainMenu::carAppearanceRandom4");
		createBlueTruckCar();
	}
	int  a = randomReleaseTime();
	schedule(schedule_selector(MainMenu::carAppearanceRandom), a);
}
void MainMenu::setLaneCar(){
	if (lane == 0)
		lane = 2;
	else if (lane == 1) {
		if (rand() % 2 == 0)
			lane = 2;
		else
			lane = 3;
	} else if (lane == 2) {
		if (rand() % 2 == 0)
			lane = 1;
		else
			lane = 3;
	} else if (lane == 3) {
		if (rand() % 2 == 0)
			lane = 1;
		else
			lane = 2;
	}
	CCLOG("MainMenu::setLaneCar() %d",lane);
}

float MainMenu::positionXCarRelease(){
	CCLOG("MainMenu::positionXCarRelease() %d",lane);
	if (lane == 1)
		return visibleSize.width/3.2;
	else if (lane == 2)
		return visibleSize.width/2;
	else if (lane == 3)
		return visibleSize.width/1.4;
	return  0;
}

int MainMenu::randomReleaseTime(){
	releaseTime = 0;
	int r = rand()%7 + 1;
	if(r < 2){
		releaseTime = 1;
	}else if( r < 5){
		releaseTime = 2;
	}else if( r < 8){
		releaseTime = 3;
	}
	return releaseTime * miniReleaseCarTime *CarSpeed;
}

void MainMenu::createBlueCar(){
	CCLOG("MainMenu::createBlueCar" );
	Car *car = Car::createBlueCar();
	car->typeCar = 1;
	car->speed = CarSpeed;
	scaleNode(car);
	car->setPosition(ccp(positionXCarRelease(), visibleSize.height + car->boundingBox().size.height/2));
	car->runActionNormal();
	layerCar->addChild(car);
	listCar->addObject(car);
}

void MainMenu::createPinkCar(){
	CCLOG("MainMenu::createPinkCar" );
	Car *car = Car::createPinkCar();
	car->typeCar = 2;
	car->speed = CarSpeed;
	scaleNode(car);
	car->setPosition(ccp(positionXCarRelease(), visibleSize.height + car->boundingBox().size.height/2));
	car->runActionNormal();
	layerCar->addChild(car);
	listCar->addObject(car);
}

void MainMenu::createOrangeCar(){
	CCLOG("MainMenu::createOrangeCar" );
	Car *car = Car::createOrangeCar();
	car->typeCar = 3;
	car->speed = CarSpeed;
	scaleNode(car);
	car->setPosition(ccp(positionXCarRelease(), visibleSize.height + car->boundingBox().size.height/2));
	car->runActionNormal();
	layerCar->addChild(car);
	listCar->addObject(car);
}

void MainMenu::createBlueTruckCar(){
	CCLOG("MainMenu::createBlueTruckCar" );
	Car *car = Car::createBlueTruck();
	car->typeCar = 4;
	car->speed = TruckSpeed;
	scaleNode(car);
	car->setPosition(ccp(positionXCarRelease(), visibleSize.height + car->boundingBox().size.height/2));
	car->runActionNormal();
	layerCar->addChild(car);
	listCar->addObject(car);
}

void MainMenu::runGame() {
	numberGames++;
	SoundManager::gI()->playSoundBackground(TT_Title2);
	startGame = true;
	turtleCar->runActionForward();
	turtleCar->keyAlmostScore = 0;
	turtleCar->keyEqualScore = 0;
	schedule(schedule_selector(MainMenu::updateGame));
	schedule(schedule_selector(MainMenu::updateTime),1);
	schedule(schedule_selector(MainMenu::updateMusic));
	schedule(schedule_selector(MainMenu::showAdvertisementTop),1);
	randomModeHover();
}
void MainMenu::updateTime(float dt){
	time = time++;
	timeSprite_1->setDisplayFrame(database->getNumberFont(time/60)->displayFrame());
	timeSprite_2->setDisplayFrame(database->getNumberFont((time%60)/10)->displayFrame());
	timeSprite_3->setDisplayFrame(database->getNumberFont(time%10)->displayFrame());
}
void MainMenu::updateGame(float dt) {
	updateBackGround();
	if (turtleCar != NULL && startGame) {
		// collision Side
		collisionSideOfRoad();
		//collision Car
		if(!modeHover)
			collisionCar();

		updatePosTurtle();
		updatePositionCar(1);
		if(time == timeHover && !modeHover){
			SoundManager::gI()->playSoundEffect(TT_Hover);
			SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5f);
			modeHover = true;
			turtleCar->runActionHoverMode();
			scheduleOnce(schedule_selector(MainMenu::sche_timeModeHover),10);
		}
	}

}


void MainMenu::sche_timeModeHover(float dt){
	turtleCar->stopActionHoverMode();
	scheduleOnce(schedule_selector(MainMenu::sche_timeModeFlash),5);
	turtleCar->runActionFlash();
}

void MainMenu::sche_timeModeFlash(float dt){
	timeHover = 0;
	randomModeHover();
	modeHover = false;
}

void MainMenu::updateMusic(float dt){
	int hightScore = CCUserDefault::sharedUserDefault()->getIntegerForKey("highScore0",0);
	if(hightScore > 0){
		if(score == (hightScore - 1) && turtleCar->keyAlmostScore == 0){
			turtleCar->keyAlmostScore = SimpleAudioEngine::sharedEngine()->playEffect("FinalSound/TT_AlmostHighScore.wav");
		}else if(score == hightScore && turtleCar->keyEqualScore == 0){
			SimpleAudioEngine::sharedEngine()->stopEffect(turtleCar->keyAlmostScore);
			turtleCar->keyAlmostScore = 0;
			turtleCar->keyEqualScore = SimpleAudioEngine::sharedEngine()->playEffect("FinalSound/TT_EqualHighScore.wav");
		}else if(score > hightScore ){
			SimpleAudioEngine::sharedEngine()->stopEffect(turtleCar->keyEqualScore);
			turtleCar->keyEqualScore = 0;
			unschedule(schedule_selector(MainMenu::updateMusic));
		}
	}
}
void MainMenu::updateBackGround(){
	background_1->setPositionY(background_1->getPositionY() - backgroundscrollspeed);
	background_2->setPositionY(
			background_1->getPositionY()
					+ background_1->boundingBox().size.height - backgroundscrollspeed);

	if (background_2->getPositionY() <= 0) {
		background_1->setPositionY(0);
	}
}

void MainMenu::updatePositionCar(float dt){
	if(listCar->count() == 0) return;
	for(int i = 0 ; i< listCar->count(); i++){
		Car *car = (Car*)listCar->objectAtIndex(i);
		car->setPositionY(car->getPositionY() - car->speed);
		if(car->getPositionY() <=
				(turtleCar->getPositionY() + turtleCar->boundingBox().size.height/2) && !car->change){
			car->change = true;
			car->stopNormal();
			car->runActionScore();
		}
		if((car->getPositionY() + car->boundingBox().size.height/2 )<= (turtleCar->getPositionY() - turtleCar->boundingBox().size.height/2) && !car->pass){
			car->pass = true;
			score = score++;
			SoundManager::gI()->playSoundEffect(TT_Score);
			CCSprite* sprite = scoreSprite;
			scoreSprite = database->getNumberFont(score);
			scoreGame->removeChild(sprite,true);
			scoreGame->addChild(scoreSprite);
			scoreSprite->setPosition(ccp(scoreGame->getContentSize().width/2, scoreGame->getContentSize().height/2));
			if(score > 9){
				scoreSprite->setScale(0.8f);
				scoreSprite->setPosition(ccp(scoreGame->getContentSize().width/6, scoreGame->getContentSize().height/2));
			}
			else if(score >99){
				scoreSprite->setScale(0.5f);
				scoreSprite->setPosition(ccp(0, scoreGame->getContentSize().height/2));
			}

		}
		if(car->getPositionY() <= -car->boundingBox().size.height/2){
			listCar->removeObjectAtIndex(i,true);
			layerCar->removeChild(car, true);
		}
	}
}

void MainMenu::updatePosTurtle(){
//	if(!modeHover){
	if (momentums < 0 && !leftMoving) {
		turtleCar->stopActionRight();
		turtleCar->stopActionForward();
		leftMoving = true;
		rightMoving = false;
		turtleCar->runActionLeft();
	} else if (momentums > 0 && !rightMoving) {
		turtleCar->stopActionLeft();
		turtleCar->stopActionForward();
		rightMoving = true;
		leftMoving = false;
		turtleCar->runActionRight();
	} else if (momentums == 0) {
		if (leftMoving)
			turtleCar->stopActionLeft();
		if (rightMoving)
			turtleCar->stopActionRight();
		if (leftMoving || rightMoving)
			turtleCar->runActionForward();
		leftMoving = false;
		rightMoving = false;
	}
	// random momentums
	if (numberMovements > 0 && (numberMovements % moveChangesPerRandom == 0)
			&& !randomMomentums) {
		randomMomentums = true;
		int ran = rand() % 3;
		if (ran == 0) {
			stepSperMomentum = stepSperMomentum * swipePerMomentumRandom_1;
		} else if (ran == 1) {
			stepSperMomentum = stepSperMomentum * swipePerMomentumRandom_2;
		} else if (ran == 2) {
			stepSperMomentum = stepSperMomentum * swipePerMomentumRandom_3;
		}
		scheduleOnce(schedule_selector(MainMenu::timerRandomMomentums), 5);
	}
	turtleCar->setPositionX(
			turtleCar->getPositionX()
					+ momentums * distance * stepSperMomentum / 30);
//	}
}
void MainMenu::timerRandomMomentums(float dt){
	stepSperMomentum = StepSperMomentum;
	randomMomentums = false;
}
void MainMenu::scaleNode(CCNode * node) {
	if (node->getContentSize().width == node->getContentSize().height)
		node->setScale(AppDelegate::getMinScale());
	else {
		node->setScaleX(AppDelegate::getScaleX());
		node->setScaleY(AppDelegate::getScaleY());
	}

}

void MainMenu::randomModeHover(){
	int rand = arc4random()%7 + 4;
	timeHover = rand * Hovertimemultiplier;
}

void MainMenu::playGame(CCObject *obj) {
	randomMapRes();
	SoundManager::gI()->playSoundEffect(TT_Button_Press);
	initValueGame();
	turtleCar->setVisible(false);
	background_1->runAction(
			CCSequence::create(CCFadeOut::create(0.3f), CCCallFunc::create(this,
			callfunc_selector(MainMenu::sceneReady)), CCFadeIn::create(0.3f),
			NULL));
	if(controlGame)
		controlGame->setVisible(false);
	if(layerGameOver){
		layerGameOver->removeAllChildrenWithCleanup(true);
		this->removeChild(layerGameOver,true);
		layerGameOver = NULL;
//		layerGameOver->setVisible(false);
	}

}

void MainMenu::sceneReady() {
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SoundManager::gI()->playSoundEffect(TT_LightCountDownRed);
	if(readyGame == NULL)
		initLayerReady();
	else{
		ready_1->setVisible(true);
		ready_2->setVisible(true);
		ready_3->setVisible(true);
		ready_4->setVisible(true);
		swipe_ready->setVisible(true);
	}
	turtleCar->setTexture(CCSprite::create("TurtleForward/Turtle Animation 1_Forward1.png")->getTexture());
	turtleCar->setTextureRect(CCSprite::create("TurtleForward/Turtle Animation 1_Forward1.png")->getTextureRect());
	turtleCar->setVisible(true);
	turtleCar->setPosition(ccp( visibleSize.width/2,turtleCar->boundingBox().size.height));
	scoreGame->setVisible(true);
	timeGame->setVisible(true);
	schedule(schedule_selector(MainMenu::stateReady), 1);
}

void MainMenu::collisionCar(){
	CCObject* it = NULL;
	CCRect rectTurtle = CCRect(turtleCar->boundingBox().origin.x +turtleCar->boundingBox().size.width*0.15f,
			turtleCar->boundingBox().origin.y + turtleCar->boundingBox().size.height*0.25f,
			turtleCar->boundingBox().size.width *0.68f ,
			turtleCar->boundingBox().size.height * 0.57f);
	CCRect rectCar = CCRectZero;
	CCARRAY_FOREACH(listCar, it) {
		Car * car = dynamic_cast<Car*>(it);
		if(car->typeCar == 1){
			rectCar = CCRect(car->boundingBox().origin.x + car->boundingBox().size.width*0.1  ,
					car->boundingBox().origin.y + car->boundingBox().size.height/7
					,car->boundingBox().size.width*0.9
					, car->boundingBox().size.height);
		}else if(car->typeCar == 2){
			rectCar = CCRect(car->boundingBox().origin.x + car->boundingBox().size.width*0.1  ,
					car->boundingBox().origin.y + car->boundingBox().size.height/7
					,car->boundingBox().size.width*0.9
					, car->boundingBox().size.height);
		}else if(car->typeCar == 3){
			rectCar = CCRect(car->boundingBox().origin.x +car->boundingBox().size.width*0.1  ,
					car->boundingBox().origin.y + car->boundingBox().size.height/7
					,car->boundingBox().size.width*0.9
					, car->boundingBox().size.height);
		}else if(car->typeCar == 4){
			rectCar = CCRect(car->boundingBox().origin.x + car->boundingBox().size.width*0.2  ,
					car->boundingBox().origin.y + car->boundingBox().size.height/26
					,car->boundingBox().size.width*0.9
					, car->boundingBox().size.height);
		}
		if (rectTurtle.intersectsRect(rectCar)) {
			int t_1 = turtleCar->getPositionY()
					+ turtleCar->boundingBox().size.height / 2;
			if (t_1 <= car->getPositionY()) {
				if (turtleCar->getPositionX() <= car->getPositionX()) {
					turtleCar->colliPos = 1;//duoi trai
				} else {
					turtleCar->colliPos = 2;//duoi phai
				}
			} else {
				if (turtleCar->getPositionX() <= car->getPositionX()) {
					turtleCar->colliPos = 3;// tren trai
				} else {
					turtleCar->colliPos = 4;// tren phai
				}
			}
			gameOver();
		}
	}
}

void MainMenu::collisionSideOfRoad(){
	if((turtleCar->getPositionX() - turtleCar->boundingBox().size.width/2 <=300 * AppDelegate::getScaleX())){
		colliLeftSide = true;
		colliRightSide = false;
		gameOver();
	}
	else if(turtleCar->getPositionX() + turtleCar->boundingBox().size.width/2 >=1236* AppDelegate::getScaleX()){
		colliLeftSide = false;
		colliRightSide = true;
		gameOver();
	}
}

void MainMenu::handleColliSide(){
	ccBezierConfig bezier ;
	bezier.controlPoint_1 = CCPointMake(visibleSize.width/3, visibleSize.height/4);
	bezier.controlPoint_2 = CCPointMake(visibleSize.width/2, visibleSize.height/3);
	float x_ = 0;
	float y_ = 0;

	if (colliLeftSide) {
		x_ = rand() % ((int)visibleSize.width / 3) + visibleSize.width / 2;
		y_ = rand() % ((int)visibleSize.height / 3);
	} else if (colliRightSide) {
		x_ = rand() % ((int)visibleSize.width / 2);
		y_ = rand() % ((int)visibleSize.height / 2);
	}
	bezier.endPosition = CCPointMake(x_, y_);
	CCBezierTo * bezierBy = CCBezierTo::create(2,bezier);
	turtleCar->runAction(turtleCar->animateCrash);
	turtleCar->runAction(CCSequence::create(bezierBy,CCCallFunc::create(this, callfunc_selector(MainMenu::tryAgain)), NULL));
}

void MainMenu::gameOver(){
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SoundManager::gI()->playSoundEffect(TT_Crash);

	unschedule(schedule_selector(MainMenu::updateGame));
	unschedule(schedule_selector(MainMenu::updateTime));
	unschedule(schedule_selector(MainMenu::carAppearanceRandom));
	unschedule(schedule_selector(MainMenu::updateMusic));
	unschedule(schedule_selector(MainMenu::showAdvertisementTop));
	listCar->removeAllObjects();
	startGame = false;
	turtleCar->stopActionForward();
	turtleCar->stopActionLeft();
	turtleCar->stopActionRight();
	turtleCar->stopActionHoverMode();
	turtleCar->createActionCrash();
	if(colliLeftSide||colliRightSide)
		handleColliSide();
	else{
		turtleCar->runAction(turtleCar->animateCrash);
		turtleCar->runAction(CCSequence::create(colliCar(),CCCallFunc::create(this, callfunc_selector(MainMenu::tryAgain)), NULL));
	}
	scheduleOnce(schedule_selector(MainMenu::showAdvertisementCenter),1);
}
CCBezierTo* MainMenu::colliCar(){
	ccBezierConfig bezier ;
	bezier.controlPoint_1 = turtleCar->getPosition();
	if (turtleCar->colliPos == 1) { //duoi trai
		bezier.controlPoint_2 = CCPointMake(arc4random()%(int)turtleCar->getPositionX(), arc4random()%(int)turtleCar->getPositionY());
		bezier.endPosition = CCPointMake(arc4random()%(int)bezier.controlPoint_2.x, arc4random()%(int)bezier.controlPoint_2.y);
	} else if (turtleCar->colliPos == 2) {// duoi phai
		bezier.controlPoint_2 = CCPointMake(arc4random()%(int)(visibleSize.width - turtleCar->getPositionX()) + turtleCar->getPositionX() , arc4random()%(int)turtleCar->getPositionY());
		bezier.endPosition = CCPointMake(arc4random()%(int)(visibleSize.width - bezier.controlPoint_2.x) + bezier.controlPoint_2.x , arc4random()%(int)bezier.controlPoint_2.y);
	} else if (turtleCar->colliPos == 3) {// tren trai
		bezier.controlPoint_2 = CCPointMake(arc4random()%(int)turtleCar->getPositionX(), arc4random()%(int)(visibleSize.height/3 - turtleCar->getPositionY()) + turtleCar->getPositionY());
		bezier.endPosition = CCPointMake(arc4random()%(int)bezier.controlPoint_2.x, arc4random()%(int)(visibleSize.height/3 - bezier.controlPoint_2.y) + bezier.controlPoint_2.y);
	} else if (turtleCar->colliPos == 4) {// tren phai
		bezier.controlPoint_2 = CCPointMake(arc4random()%(int)(visibleSize.width - turtleCar->getPositionX()) + turtleCar->getPositionX(), arc4random()%(int)(visibleSize.height/3 - turtleCar->getPositionY()) + turtleCar->getPositionY());
		bezier.endPosition = CCPointMake(arc4random()%(int)(visibleSize.width - bezier.controlPoint_2.x) + bezier.controlPoint_2.x, arc4random()%(int)(visibleSize.height/3 - bezier.controlPoint_2.y) + bezier.controlPoint_2.y);
}
	CCBezierTo * bezierBy = CCBezierTo::create(2,bezier);
	return bezierBy;
}
void MainMenu::tryAgain(){
	background_1->setPosition(ccp(0,0));
	background_2->setPosition(ccp(0,visibleSize.height));
	scoreGame->setVisible(false);
	timeGame ->setVisible(false);
	layerCar->removeAllChildrenWithCleanup(true);
	initLayerGameOver();
	SoundManager::gI()->playSoundBackground(TT_GameOver_Music);
	saveData(score);
	timeSprite_1->setDisplayFrame(database->getNumberFont(0)->displayFrame());
	timeSprite_2->setDisplayFrame(database->getNumberFont(0)->displayFrame());
	timeSprite_3->setDisplayFrame(database->getNumberFont(0)->displayFrame());
	CCSprite* sprite = scoreSprite;
	scoreSprite = database->getNumberFont(0);
	scoreGame->removeChild(sprite,true);
	scoreGame->addChild(scoreSprite);
	scoreSprite->setPosition(ccp(scoreGame->getContentSize().width/2, scoreGame->getContentSize().height/2));
}
void MainMenu::initValueGame(){
	backgroundscrollspeed = Backgroundscrollspeed * AppDelegate::getScaleY();
	swipeMaxMomentum = SwipeMaxMomentum;
	stepSperMomentum = StepSperMomentum;
	moveChangesPerRandom = MoveChangesPerRandom;
	swipePerMomentumRandom_1 = SwipePerMomentumRandom_1;
	swipePerMomentumRandom_2 = SwipePerMomentumRandom_2;
	swipePerMomentumRandom_3 = SwipePerMomentumRandom_3;
	randomMovementsPerTime = RandomMovementsPerTime;
	miniReleaseCarTime = MiniReleaseCarTime;
	numberMovements = 0;
	momentums = 0;
	startGame = false;
	randomMomentums = false;
	distance = 1536 * AppDelegate::getScaleX() / 200;
	leftMoving = false;
	rightMoving = false;
	colliLeftSide = false;
	colliRightSide = false;
	lane = 0;
	score = 0;
	time = 0;
	posStarCount = 0;
	timeHover = 0;
	modeHover = false;
}
bool MainMenu::isPointer(CCNode* node, CCPoint pos) {
	if (node != NULL) {
		if (node->convertToNodeSpace(pos).x > 0
				&& node->convertToNodeSpace(pos).x
						< node->getContentSize().width
				&& node->convertToNodeSpace(pos).y > 0
				&& node->convertToNodeSpace(pos).y
						< node->getContentSize().height) {
			return true;
		}
	}
	return false;

}
void MainMenu::xtTouchesBegan(cocos2d::CCSet* _touches,
		cocos2d::CCEvent* event) {
	CCLog("xtTouchesBegan");
	CCSetIterator it = _touches->begin();
	CCTouch* touch = (CCTouch*) (*it);
	CCPoint m_tBeginPos = touch->getLocation();
	if (startGame && turtleCar != NULL) {
		if (isPointer(turtleCar, m_tBeginPos)) {
			if (abs(momentums) <= 3)
				momentums = 0;
		}
	}
}

void MainMenu::xtTouchesMoved(cocos2d::CCSet* _touches,
		cocos2d::CCEvent* event) {
	CCLog("xtTouchesMoved");
}

void MainMenu::xtTouchesEnded(cocos2d::CCSet* _touches,
		cocos2d::CCEvent* event) {
	CCLog("xtTouchesEnded");
}

void MainMenu::xtTouchesBegan(CCPoint position) {
	CCLog("xtTouchesBegan x: %f, y: %f", position.x, position.y);
}

void MainMenu::xtTouchesMoved(CCPoint position) {
	CCLog("xtTouchesMoved x: %f, y: %f", position.x, position.y);
}

void MainMenu::xtTouchesEnded(CCPoint position) {
	CCLog("xtTouchesEnded x: %f, y: %f", position.x, position.y);
}

void MainMenu::xtTapGesture(CCPoint position) {
	CCLog("xtTapGesture x: %f, y: %f", position.x, position.y);
}

void MainMenu::xtDoubleTapGesture(CCPoint position) {
	CCLog("xtDoubleTapGesture x: %f, y: %f", position.x, position.y);
}

void MainMenu::xtLongTapGesture(CCPoint position) {
	CCLog("xtLongTapGesture x: %f, y: %f", position.x, position.y);
}

void MainMenu::xtSwipeGesture(XTTouchDirection direction, float distance,
		float speed) {
	float x_left = 0;
	float x_right = 0;
	std::string directionStr = "";
	switch (direction) {
	case XTLayer::UP:
		directionStr = "UP";
		break;
	case XTLayer::DOWN:
		directionStr = "DOWN";
		break;
	case XTLayer::LEFT:
		directionStr = "LEFT";
		if (turtleCar != NULL && startGame ) {
			SoundManager::gI()->playSoundEffect(TT_SwipeRight);
			momentums++;
			numberMovements++;
		}
		break;
	case XTLayer::RIGHT:
		directionStr = "RIGHT";
		if (turtleCar != NULL && startGame) {
			SoundManager::gI()->playSoundEffect(TT_SwipeLeft);
			momentums--;
			numberMovements++;
		}
		break;
	default:
		break;
	}

	CCLog("xtSwipeGesture direction: %s, distance: %f, speed: %f",
			directionStr.c_str(), distance, speed);

}

void MainMenu::menuCloseCallback(CCObject* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}
