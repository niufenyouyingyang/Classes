//
//  MyScene.h
//  MusicTest
//
//  Created by WF on 16/3/14.
//
//

#ifndef __MusicTest__MyScene__
#define __MusicTest__MyScene__

#include "cocos2d.h"
USING_NS_CC;

class MyScene:public Layer
{
public:
    static Scene * createScene();
    bool init();
    CREATE_FUNC(MyScene);
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event)override;
    virtual void onTouchMoved(Touch *touch, Event *unused_event)override;
    
    
    virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)override;
    virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)override;
    virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)override;
   

    virtual void onExit()override;
};

#endif /* defined(__MusicTest__MyScene__) */
