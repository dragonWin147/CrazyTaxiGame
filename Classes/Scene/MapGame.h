#ifndef __MapGame_SCENE_H__
#define __MapGame_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class MapGame: public CCLayer {
private:
	MapGame();
	static MapGame* instance;
	~MapGame();
	CCTMXTiledMap *tileMap;
	CCTMXLayer  *background;
	CCTMXLayer  *meta;
	CCSprite *player;
	CCTMXLayer *foreground;
public:
	virtual bool init();
	void setViewPointCenter(CCPoint position);
	static CCScene* scene();

	static MapGame* getInstance();

	void registerWithTouchDispatcher();
	CCPoint tileCoordForPosition(CCPoint position);
	void setPlayerPosition(CCPoint position);

	bool ccTouchBegan(CCTouch *touch, CCEvent *event);
	void ccTouchMove(CCTouch *touch, CCEvent *event);
	void ccTouchEnded(CCTouch *touch, CCEvent *event);

	CREATE_FUNC(MapGame)
	;
};

#endif // __MapGame_SCENE_H__
