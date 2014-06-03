/*
 * FishGutouyu.h
 *
 *  Created on: Sep 6, 2013
 *      Author: Admin
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include "cocos2d.h"
#include <iostream>
#include "CCDate.h"
USING_NS_CC;
using namespace std;
class Database: public CCNode {
public:
	virtual bool init();
	Database();
	~Database();
	void initTextureRes();
	CCSprite* drawScore(const char * str);
	CCArray *numberArr;
	void saveData(int score);
	CCSpriteFrame* getKey(int key);
	CCSprite* getNumberFont(int number);
	void initNumber();
};

#endif
