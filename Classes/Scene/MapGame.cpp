#include "MapGame.h"
#include "../AppDelegate.h"
using namespace std;
using namespace cocos2d;
MapGame* MapGame::instance = NULL;

MapGame* MapGame::getInstance() {
	if (instance == NULL) {
		instance = new MapGame();
	}
	return instance;
}
MapGame::MapGame() {

}
MapGame::~MapGame() {

}

CCScene* MapGame::scene() {
	CCScene *scene = CCScene::create();

	MapGame *layer = MapGame::create();

	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MapGame::init() {
	if (!CCLayer::init()) {
		return false;
	}
	this->setTouchEnabled(true);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	tileMap = new CCTMXTiledMap();
	tileMap->initWithTMXFile("map.tmx");
	background = tileMap->layerNamed("MapOne");
	meta = tileMap->layerNamed("Meta");
	meta->setVisible(false);
	foreground = tileMap->layerNamed("Eat");
	this->addChild(tileMap);

	CCTMXObjectGroup *objectGroup = tileMap->objectGroupNamed("Objects");
	if (objectGroup == NULL) {
		 CCLog("tile map has no objects object layer");
		return false;
	}

	CCDictionary *spawnPoint = objectGroup->objectNamed("SpawnPoint");

	int x = ((CCString*) spawnPoint->valueForKey("x"))->intValue();
	int y = ((CCString*) spawnPoint->valueForKey("y"))->intValue();

	player = new CCSprite();
	player->initWithFile("Player.png");
	player->setPosition(ccp(x,y));
	this->addChild(player);

	this->setViewPointCenter(player->getPosition());
    this->setScaleX(AppDelegate::getScaleX());
    this->setScaleY(AppDelegate::getScaleY());
	return true;
}
CCPoint MapGame::tileCoordForPosition(CCPoint position)
{
    int x = position.x / tileMap->getTileSize().width;
    int y = ((tileMap->getMapSize().height * tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;
    return ccp(x, y);
}
void MapGame::setViewPointCenter(CCPoint position) {
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	int x = MAX(position.x, winSize.width/2);
	int y = MAX(position.y, winSize.height/2);
	x = MIN(x, (tileMap->getMapSize().width * this->tileMap->getTileSize().width) - winSize.width / 2);
	y = MIN(y, (tileMap->getMapSize().height * tileMap->getTileSize().height) - winSize.height/2);
	CCPoint actualPosition = ccp(x, y);

	CCPoint centerOfView = ccp(winSize.width/2, winSize.height/2);
	CCPoint viewPoint = ccpSub(centerOfView, actualPosition);
	this->setPosition(viewPoint);
}


void MapGame::registerWithTouchDispatcher() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool MapGame::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
    return true;
}

void MapGame::setPlayerPosition(CCPoint position) {
	CCPoint pos = this->tileCoordForPosition(position);
	int tileID = meta->tileGIDAt(pos);
	CCLog("TileID %d", tileID);
	if(tileID){
		CCDictionary *dic = tileMap->propertiesForGID(tileID);
		if(dic){
			if(dic->valueForKey("Colli")->compare("True")==0){
				return;
			}
			CCString *collectible = new CCString();
			*collectible = *dic->valueForKey("collectable");
			if (collectible && (collectible->compare("True") == 0)) {
			    meta->removeTileAt(pos);
			    foreground->removeTileAt(pos);
			}
		}
	}

    player->setPosition(position);
}

void MapGame::ccTouchEnded(CCTouch *touch, CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    touchLocation = this->convertToNodeSpace(touchLocation);

    CCPoint playerPos = player->getPosition();
    CCPoint diff = ccpSub(touchLocation, playerPos);

    if ( abs((int)diff.x) > abs((int)diff.y) ) {
        if (diff.x > 0) {
            playerPos.x += tileMap->getTileSize().width/2;
        } else {
            playerPos.x -= tileMap->getTileSize().width/2;
        }
    } else {
        if (diff.y > 0) {
            playerPos.y += tileMap->getTileSize().height/2;
        } else {
            playerPos.y -= tileMap->getTileSize().height/2;
        }
    }

    // safety check on the bounds of the map
    if (playerPos.x <= (tileMap->getMapSize().width * tileMap->getTileSize().width) &&
        playerPos.y <= (tileMap->getMapSize().height * tileMap->getTileSize().height) &&
        playerPos.y >= 0 &&
        playerPos.x >= 0 )
    {
        this->setPlayerPosition(playerPos);
    }

    this->setViewPointCenter(player->getPosition());
}





















