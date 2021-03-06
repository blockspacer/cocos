#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "KeyboardScene.h"
#include "Definitions.h"
#include "PhysicScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
	auto label = Label::createWithSystemFont("Hello World", "Arial", 96);
	label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
	this->addChild(label, 1);

	//GotoTouchScene();
	this->scheduleOnce(schedule_selector(HelloWorld::GotoTouchScene), 0);
    
    return true;
}

void HelloWorld::GotoTouchScene(float dt) {
	auto scene = PhysicScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0, scene));
}