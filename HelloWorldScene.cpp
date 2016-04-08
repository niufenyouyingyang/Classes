#include "HelloWorldScene.h"

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    
    auto layer = HelloWorld::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto item1 = MenuItemImage::create("soundController.png",
                                       "soundController.png");
    
    auto item2 = MenuItemImage::create("soundController2.png",
                                       "soundController2.png");
    
    auto switchMenu = MenuItemToggle::createWithCallback(CC_CALLBACK_0(HelloWorld::MusicMenuCallBack, this),item1,
        item2,
        NULL);
    switchMenu->setPosition(Vec2(100, 100));
    auto menu = Menu::create();
    menu->addChild(switchMenu);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
    
    auto pause = MenuItemImage::create("stopMenu.png","stopMenu.png");
    pause->setCallback(CC_CALLBACK_1(HelloWorld::MenuCallBack, this));
    pause->setTag(1);
    pause->setPosition(Vec2(960, 640)-Vec2(100, 100));
    menu->addChild(pause);
    
    auto resume = MenuItemImage::create("CloseNormal.png",
                                        "CloseSelected.png");
    resume->setCallback(CC_CALLBACK_1(HelloWorld::MenuCallBack, this));
    resume->setTag(2);
    resume->setPosition(Vec2(960, 640)-Vec2(150, 100));
    menu->addChild(resume);
    
    auto slider = cocos2d::ui::Slider::create();
    slider->loadBarTexture("xuetiao1.png");
    slider->loadProgressBarTexture("xuetiao2.png");
    slider->loadSlidBallTextureNormal("switch-thumb.png");
    slider->loadSlidBallTexturePressed("switch-thumb.png");
    slider->loadSlidBallTextureDisabled("switch-thumb.png");
    slider->setPosition(Vec2(480, 320));
    slider->setPercent(10);
    slider->addEventListener(CC_CALLBACK_2(HelloWorld::sliderCall, this));
    slider->setName("slider");
    addChild(slider);
    
    return true;
}
void HelloWorld::sliderCall(Ref * sender,cocos2d::ui::Slider::EventType ty)
{
    cocos2d::ui::Slider * slider = dynamic_cast<cocos2d::ui::Slider*>(sender);
    
    auto volume = slider->getPercent();//得到滑块当前的值
    
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume/100.0);//使用滑块的值来设置音乐的音量
}
void HelloWorld::MenuCallBack(Ref * sender)
{
    auto item = (MenuItemImage *)sender;
    if (item->getTag() == 1)
    {
        //暂停背景音乐
        SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    }
    else if (item->getTag() == 2)
    {
        //恢复音乐
        SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    }
    
}
void HelloWorld::onEnter()//进入场景时调用
{
    Layer::onEnter();//调用父类的onEnter函数
    auto musicIsOn = UserDefault::getInstance()->getBoolForKey("musicIsOn", false);
    if (musicIsOn) {
        
    }
    else
    {
        SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3",true);//播放音乐
        //得到滑块
        cocos2d::ui::Slider * slider =
                            dynamic_cast<cocos2d::ui::Slider*>(this->getChildByName("slider"));
        //使用滑块儿的值来初始化背景音乐的音量
        SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(slider->getPercent()/100.0);
        
    }
    
}
void HelloWorld::onExit()//退出场景时调用
{
    auto musicIsOn = SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
    UserDefault::getInstance()->setBoolForKey("musicIsOn", musicIsOn);
    UserDefault::getInstance()->flush();//保存
    Layer::onExit();
}
void HelloWorld::loadMusic()
{
    //Director::getInstance()->getTextureCache()->addImage("HelloWorld.png");
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("background.mp3");//预加载背景音乐文件
}
void HelloWorld::MusicMenuCallBack()
{
    auto simple = SimpleAudioEngine::getInstance();
    if (simple->isBackgroundMusicPlaying())
    {
        simple->stopBackgroundMusic();
    }
    else
    {
        simple->playBackgroundMusic("background.mp3");
    }
}
