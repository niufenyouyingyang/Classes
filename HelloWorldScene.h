#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"//播放音乐的头文件
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace cocos2d::ui;
using namespace CocosDenshion;//使用CocosDeshion 命名空间

class HelloWorld : public Layer
{
public:
    static Scene * createScene();
    void loadMusic(); // 加载音乐
    void MusicMenuCallBack();//  音乐开关按钮的回调函数
    void MenuCallBack(Ref * sender);
    
    //滑块儿的调用函数
    void sliderCall(Ref * sender,
                    cocos2d::ui::Slider::EventType ty);
    
    virtual bool init();
    CREATE_FUNC(HelloWorld);
    
    void onEnter();
    void onExit();
};
#endif // __HELLOWORLD_SCENE_H__
