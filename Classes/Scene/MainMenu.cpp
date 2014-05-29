#include "MainMenu.h"
#include "../AppDelegate.h"
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
	readyGame = NULL;
	layerCar = NULL;
	firstAppearance = false;
	releaseTime = 0;
	listCar = new CCArray();
	initTextureRes();
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

	background_1 = CCSprite::create("FinalPNG/Country Background.png");
	background_1->setAnchorPoint(ccp(0,0));
	scaleNode(background_1);
	background_1->setPosition(ccp(0,0));
	this->addChild(background_1);

	background_2 = CCSprite::create("FinalPNG/Country Background.png");
	background_2->setAnchorPoint(ccp(0,0));
	scaleNode(background_2);
	background_2->setPosition(ccp(0,visibleSize.height));
	this->addChild(background_2);

	timeGame = CCSprite::create("FinalPNG/TT_Scorebadge.png");
	scaleNode(timeGame);
	timeGame->setPosition(
			ccp(timeGame->boundingBox().size.width/2 + 10 *AppDelegate::getScaleX(),visibleSize.height - timeGame->boundingBox().size.height/2 - 10 *AppDelegate::getScaleY()));
	this->addChild(timeGame);

	scoreGame = CCSprite::create("FinalPNG/TT_Scorebadge.png");
	scaleNode(scoreGame);
	scoreGame->setPosition(
			ccp(visibleSize.width - scoreGame->boundingBox().size.width/2 - 10 *AppDelegate::getScaleX(),timeGame->getPositionY()));
	this->addChild(scoreGame);

	scoreLabel = CCLabelTTF::create("0","font/MarkerFelt.ttf",150);
	scoreGame->addChild(scoreLabel);
	scoreLabel->setPosition(ccp(scoreGame->getContentSize().width/2, scoreGame->getContentSize().height/2));

	timeLabel = CCLabelTTF::create("0.00","font/MarkerFelt.ttf",70 );
	timeGame->addChild(timeLabel);
	timeLabel->setPosition(ccp(timeGame->getContentSize().width/2, timeGame->getContentSize().height/2));

	scoreGame->setVisible(false);
	timeGame->setVisible(false);

	turtleCar = TurtleCar::create(
			"TurtleForward/Turtle Animation 1_Forward1.png");
	turtleCar->retain();
	scaleNode(turtleCar);
	turtleCar->setPosition(ccp( visibleSize.width/2,turtleCar->boundingBox().size.height));
	this->addChild(turtleCar);

	initlayerControl();

	layerCar = CCLayer::create();
	layerCar->retain();
	this->addChild(layerCar);

	_rt = CCRenderTexture::create(visibleSize.width * 2, visibleSize.height * 2);
    _rt->setPosition(ccp(visibleSize.width, visibleSize.height));
    _rt->retain();
    _rt->setVisible(false);
	return true;
}
void MainMenu::initTextureRes(){
	//Turtle Car
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward1.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward2.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward3.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward4.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward5.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward6.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward7.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward8.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left1.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left2.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left3.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left4.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left5.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left6.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left7.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left8.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right1.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right2.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right3.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right4.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right5.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right6.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right7.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right8.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash1.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash2.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash3.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash4.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash5.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash6.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash7.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash8.png");

	//Blue Car
	CCSprite::create("BlueCarNormal/Blue Care Normal1.png");
	CCSprite::create("BlueCarNormal/Blue Care Normal2.png");
	CCSprite::create("BlueCarNormal/Blue Care Normal3.png");
	CCSprite::create("BlueCarNormal/Blue Care Normal4.png");
	CCSprite::create("BlueCarScore/Blue Care Score1.png");
	CCSprite::create("BlueCarScore/Blue Care Score2.png");
	CCSprite::create("BlueCarScore/Blue Care Score3.png");
	CCSprite::create("BlueCarScore/Blue Care Score4.png");
	//Pink
	CCSprite::create("PinkCarNormal/Pink Car Normal1.png");
	CCSprite::create("PinkCarNormal/Pink Car Normal2.png");
	CCSprite::create("PinkCarNormal/Pink Car Normal3.png");
	CCSprite::create("PinkCarNormal/Pink Car Normal4.png");
	CCSprite::create("PinkCarScore/Pink Car Score1.png");
	CCSprite::create("PinkCarScore/Pink Car Score2.png");
	CCSprite::create("PinkCarScore/Pink Car Score3.png");
	CCSprite::create("PinkCarScore/Pink Car Score4.png");
	//Blue truck

	CCSprite::create("BlueTruckNormal/Blue Truck Normal1.png");
	CCSprite::create("BlueTruckNormal/Blue Truck Normal2.png");
	CCSprite::create("BlueTruckNormal/Blue Truck Normal3.png");
	CCSprite::create("BlueTruckNormal/Blue Truck Normal4.png");
	CCSprite::create("BlueTruckScore/Blue Truck Score1.png");
	CCSprite::create("BlueTruckScore/Blue Truck Score2.png");
	CCSprite::create("BlueTruckScore/Blue Truck Score3.png");
	CCSprite::create("BlueTruckScore/Blue Truck Score4.png");

	//Orange
	CCSprite::create("OrangeCarNormal/Orange Car_Normal1.png");
	CCSprite::create("OrangeCarNormal/Orange Car_Normal2.png");
	CCSprite::create("OrangeCarNormal/Orange Car_Normal3.png");
	CCSprite::create("OrangeCarNormal/Orange Car_Normal4.png");
	CCSprite::create("OrangeCarScore/Orange Car_Score1.png");
	CCSprite::create("OrangeCarScore/Orange Car_Score2.png");
	CCSprite::create("OrangeCarScore/Orange Car_Score3.png");
	CCSprite::create("OrangeCarScore/Orange Car_Score4.png");

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
			this, menu_selector(MainMenu::playGame));
	scaleNode(rateGame);
	rateGame->setPosition(
			ccp(visibleSize.width/2,startGame->getPositionY() + startGame->boundingBox().size.height));

	CCMenuItemImage* leaderGame = CCMenuItemImage::create(
			"FinalPNG/TT_LeaderButton_OFF.png",
			"FinalPNG/TT_LeaderButton_ON.png", this,
			menu_selector(MainMenu::playGame));
	scaleNode(leaderGame);
	leaderGame->setPosition(
			ccp(visibleSize.width - leaderGame->boundingBox().size.width /2 - 50*AppDelegate::getScaleX() ,startGame->getPositionY()));

	CCMenu* pMenu = CCMenu::create(startGame, rateGame, leaderGame, NULL);
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
	CCSprite* titleGame = CCSprite::create("FinalPNG/TT_GameOverTitle.png");
	scaleNode(titleGame);
	titleGame->setPosition(
			ccp(visibleSize.width/2,visibleSize.height - titleGame->boundingBox().size.height/2 - 100*AppDelegate::getScaleY()));
	layerGameOver->addChild(titleGame);

	CCSprite* scoreGame = CCSprite::create("FinalPNG/TT_GameOverScoreBackground.png");
	scaleNode(scoreGame);
	scoreGame->setPosition(
			ccp(visibleSize.width/2,titleGame->getPositionY() - titleGame->boundingBox().size.height/2 - scoreGame->boundingBox().size.height/2));
	layerGameOver->addChild(scoreGame);

	CCMenuItemImage* startGame = CCMenuItemImage::create(
			"FinalPNG/TT_StartButton_OFF.png", "FinalPNG/TT_StartButton_ON.png",
			this, menu_selector(MainMenu::playGame));
	scaleNode(startGame);
	startGame->setPosition(
			ccp(startGame->boundingBox().size.width/2 + 50*AppDelegate::getScaleX(),scoreGame->getPositionY()- scoreGame->boundingBox().size.height/2 - startGame->boundingBox().size.height/2));

	CCMenuItemImage* rateGame = CCMenuItemImage::create(
			"FinalPNG/TT_RateButton_OFF.png", "FinalPNG/TT_RateButton_ON.png",
			this, menu_selector(MainMenu::playGame));
	scaleNode(rateGame);
	rateGame->setPosition(
			ccp(visibleSize.width/2,startGame->getPositionY()- startGame->boundingBox().size.height/2 - rateGame->boundingBox().size.height/2));

	CCMenuItemImage* leaderGame = CCMenuItemImage::create(
			"FinalPNG/TT_LeaderButton_OFF.png",
			"FinalPNG/TT_LeaderButton_ON.png", this,
			menu_selector(MainMenu::playGame));
	scaleNode(leaderGame);
	leaderGame->setPosition(
			ccp(visibleSize.width - leaderGame->boundingBox().size.width /2 - 50*AppDelegate::getScaleX() ,startGame->getPositionY()));

	CCMenu* pMenu = CCMenu::create(startGame, rateGame, leaderGame, NULL);
	pMenu->setPosition(CCPointZero);
	layerGameOver->addChild(pMenu, 1);
	this->addChild(layerGameOver);
}

void MainMenu::stateReady(float dt) {
	if (ready_1->isVisible())
		ready_1->setVisible(false);
	else if (ready_2->isVisible())
		ready_2->setVisible(false);
	else if (ready_3->isVisible())
		ready_3->setVisible(false);
	else if (ready_4->isVisible()) {
		ready_4->setVisible(false);
		swipe_ready->setVisible(false);
		unschedule(schedule_selector(MainMenu::stateReady));
		schedule(schedule_selector(MainMenu::carAppearanceRandom));
		runGame();
	}
}
void MainMenu::getNumberFont(){
//	char n[10];
//	CCTexture2D * texture = CCTextureCache::sharedTextureCache()->addImage(
//			"FinalPNG/TT_FONTS.png");
//	CCArray* listNumber = CCArray::create();
//	for (int i = 0; i < 10; i++) {
//		CCSpriteFrame * number = CCSpriteFrame::createWithTexture(texture,
//				CCRect(16 * i, 0, 16, 20));
//		listNumber->addObject(number);
//	}
//	if(number < 0)
//		number = 0;
//	if(number > 9)
//		number = 9;
//	CCSprite* spriteNumber = CCSprite::create();
//	spriteNumber->setDisplayFrame(
//			(CCSpriteFrame*) listNumber->objectAtIndex(number));
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
	schedule(schedule_selector(MainMenu::updateGame));
	schedule(schedule_selector(MainMenu::updateTime),1);
	startGame = true;
	turtleCar->runActionForward();
}
void MainMenu::updateTime(float dt){
	time++;
	timeLabel->setString(CCString::createWithFormat("%d.%d%d",time/100,(time%100)/10,time%10)->getCString());
}
void MainMenu::updateGame(float dt) {
	updateBackGround();
	if (turtleCar != NULL && startGame) {
		// collision Side
		collisionSideOfRoad();
		//collision Car
		collisionCar();

		updatePosTurtle();
		updatePositionCar(1);
	}

}
void MainMenu::updateBackGround(){
	int dif = 8;
	background_1->setPositionY(background_1->getPositionY() - dif);
	background_2->setPositionY(
			background_1->getPositionY()
					+ background_1->boundingBox().size.height - dif);

	if (background_2->getPositionY() == 0) {
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
			score++;
			if (score > 9)
				scoreLabel->setFontSize(110);
			else if (score > 100)
				scoreLabel->setFontSize(50);
			scoreLabel->setString(CCString::createWithFormat("%d",score)->getCString());
		}
		if(car->getPositionY() <= -car->boundingBox().size.height/2){
			listCar->removeObjectAtIndex(i,true);
			layerCar->removeChild(car, true);
		}
	}
}

void MainMenu::updatePosTurtle(){
	if (momentums < 0 && !leftMoving) {
		turtleCar->stopAllActions();
		leftMoving = true;
		rightMoving = false;
		turtleCar->runActionLeft();
	} else if (momentums > 0 && !rightMoving) {
		turtleCar->stopAllActions();
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
	if (numberMovements > 0
			&& (numberMovements % moveChangesPerRandom == 0) && !randomMomentums) {
		randomMomentums = true;
		int ran = rand() % 3;
		if (ran == 0) {
			stepSperMomentum = stepSperMomentum * swipePerMomentumRandom_1;
		} else if (ran == 1) {
			stepSperMomentum = stepSperMomentum * swipePerMomentumRandom_2;
		} else if (ran == 2) {
			stepSperMomentum = stepSperMomentum * swipePerMomentumRandom_3;
		}
		scheduleOnce(schedule_selector(MainMenu::timerRandomMomentums),5);
	}
	turtleCar->setPositionX(
			turtleCar->getPositionX()
					+ momentums * distance * stepSperMomentum /30);
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

void MainMenu::playGame(CCObject *obj) {
	turtleCar->setVisible(false);
	background_1->runAction(
			CCSequence::create(CCFadeOut::create(0.3f), CCCallFunc::create(this,
			callfunc_selector(MainMenu::sceneReady)), CCFadeIn::create(0.3f),
			NULL));
	if(controlGame)
		controlGame->setVisible(false);
	if(layerGameOver)
		layerGameOver->setVisible(false);
}

void MainMenu::sceneReady() {
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
					,car->boundingBox().origin.x +car->boundingBox().size.width*0.9
					, car->boundingBox().size.height);
		}else if(car->typeCar == 4){
			rectCar = CCRect(car->boundingBox().origin.x + car->boundingBox().size.width*0.2  ,
					car->boundingBox().origin.y + car->boundingBox().size.height/26
					,car->boundingBox().size.width*0.9
					, car->boundingBox().size.height);
		}
		if (rectTurtle.intersectsRect(rectCar)) {
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
	unschedule(schedule_selector(MainMenu::updateGame));
	unschedule(schedule_selector(MainMenu::updateTime));
	unschedule(schedule_selector(MainMenu::carAppearanceRandom));
	listCar->removeAllObjects();
	startGame = false;
	turtleCar->stopAllActions();
	turtleCar->createActionCrash();
	if(colliLeftSide||colliRightSide)
		handleColliSide();
	else{
		turtleCar->runAction(CCSequence::create(turtleCar->animateCrash,CCCallFunc::create(this, callfunc_selector(MainMenu::tryAgain)), NULL));
	}
}

void MainMenu::tryAgain(){
	initValueGame();
	background_1->setPosition(ccp(0,0));
	background_2->setPosition(ccp(0,visibleSize.height));
	scoreGame->setVisible(false);
	timeGame ->setVisible(false);
	layerCar->removeAllChildrenWithCleanup(true);
	initLayerGameOver();
}
void MainMenu::initValueGame(){
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
		if (turtleCar != NULL && startGame) {
			momentums++;
			numberMovements++;
		}
		break;
	case XTLayer::RIGHT:
		directionStr = "RIGHT";
		if (turtleCar != NULL && startGame) {
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
