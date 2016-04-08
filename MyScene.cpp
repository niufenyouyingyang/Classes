//
//  MyScene.cpp
//  MusicTest
//
//  Created by WF on 16/3/14.
//
//

#include "MyScene.h"

Scene * MyScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MyScene::create();
    scene->addChild(layer);
    
    return scene;
}
bool  MyScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    auto bg = Sprite::create("HelloWorld.png");
    bg->setPosition(Vec2(480, 320));
    addChild(bg);
    
    bg->setVisible(false);
    /*
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("a.plist");
    Vector<SpriteFrame *> vec;
    char fileName[10];
    for (int i = 1; i<=10; i++)
    {
        sprintf(fileName, "0%d.png",i);
        SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(fileName);
        vec.pushBack(frame);
    }
    Animation * animation = Animation::createWithSpriteFrames(vec);
    animation->setDelayPerUnit(0.1);
    animation->setLoops(1);
    Animate * animate = Animate::create(animation);
    RepeatForever * repeatAction = RepeatForever::create(animate);
    bg->runAction(repeatAction);
    */
    EventDispatcher * dispatcher = Director::getInstance()->getEventDispatcher();
    EventListenerTouchAllAtOnce * listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(MyScene::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(MyScene::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(MyScene::onTouchesEnded, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    //EventListenerTouchOneByOne * listener2 = listener->clone();
    //dispatcher->addEventListenerWithSceneGraphPriority(listener2, bg);
    
    return true;
}
void MyScene::onExit()
{
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
    Layer::onExit();
}

bool MyScene::onTouchBegan(Touch *touch, Event *unused_event)
{
    log("onTouchBegan");
    return true;
}

void MyScene::onTouchMoved(Touch *touch, Event *unused_event)
{
    log("onTouchMoved");
}
void MyScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
    for (auto item:touches)
    {
        log("%f_%f",item->getLocation().x,item->getLocation().y);
    }
}
void MyScene::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
    
}
void MyScene::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
    
}