//
//  CCChar.h
//  AloGame
//
//  Created by NEMO_IT_KHTN on 10/19/13.
//
//

#include "cocos2d.h"

#ifndef AloGame_CCChar_h
#define AloGame_CCChar_h

NS_CC_BEGIN

class CC_DLL CCChar : public CCObject
{
public:
    CCChar(char v)
    : m_nValue(v) {}
    char getValue() const {return m_nValue;}
    
    static CCChar* create(char v)
    {
        CCChar* pRet = new CCChar(v);
        pRet->autorelease();
        return pRet;
    }
    
    /* override functions */
//    virtual void acceptVisitor(CCDataVisitor &visitor) { visitor.visit(this); }
    
private:
    int m_nValue;
};

// end of data_structure group
/// @}

NS_CC_END



#endif
