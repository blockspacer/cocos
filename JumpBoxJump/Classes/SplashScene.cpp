#include "SplashScene.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"
#include "GameScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

	SoundController::getInstance();

	cocos2d::Sprite* background = Sprite::create("sprites/background.jpg");
	background->setPosition(Vec2(visibleSize.width/2+origin.x,visibleSize.height/2+origin.y));
	this->addChild(background);

	Label* tutorialText = cocos2d::Label::createWithBMFont("fonts/bitmapFonts/carrier_command.xml", "TOUCH TO JUMP");
	//CCLabelBMFont *label = CCLabelBMFont::create("Bitmap Font Atlas", ");
	tutorialText->setPosition(Vec2(120, visibleSize.height-50));
	tutorialText->setBMFontSize(20);
	tutorialText->setAnchorPoint(Vec2(0,0.5));
	this->addChild(tutorialText);

	auto handTutorial = Sprite::create("sprites/hand-touch.png");
	handTutorial->setScale(0.7);
	handTutorial->setPosition(tutorialText->getPosition().x + tutorialText->getContentSize().width + 50, tutorialText->getPosition().y);
	handTutorial->setAnchorPoint(Vec2(0, 1));
	this->addChild(handTutorial);

	auto theSquareTutorial = Sprite::create("sprites/pattern4.png");
	theSquareTutorial->setContentSize(Size(SQUARE_SIZE, SQUARE_SIZE));
	theSquareTutorial->setPosition(handTutorial->getPosition().x + -10, handTutorial->getPosition().y+30);
	theSquareTutorial->setAnchorPoint(Vec2(0, 1));
	theSquareTutorial->setRotation(-10);
	this->addChild(theSquareTutorial);

	auto progressBG = Sprite::create("sprites/maingame/progress.jpg");
	progressBG->setPosition(Vec2(400,visibleSize.height+origin.y- 150));
	progressBG->setAnchorPoint(Vec2(0, 1));
	progressBG->setAnchorPoint(Vec2(0, 1));
	this->addChild(progressBG);

	auto progress = Sprite::create("sprites/maingame/progress_blank.jpg");
	progress->setPosition(progressBG->getPosition());
	progress->setColor(Color3B(255,102,153));
	progress->setContentSize(Size(progress->getContentSize().width,progress->getContentSize().height));
	progress->setAnchorPoint(Vec2(0, 1));
	progress->setScaleX(0);
	this->addChild(progress);

	auto theSquare = Sprite::create("sprites/pattern4.png");
	theSquare->setPosition(Vec2(progressBG->getPosition().x,progressBG->getPosition().y+30));
	theSquare->setContentSize(Size(SQUARE_SIZE, SQUARE_SIZE));
	theSquare->setColor(Color3B(255, 102, 153));
	theSquare->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(theSquare);


	float duration = 2.0f;
	// Scale uniformly by 1x over 2 seconds
	auto scaleBy = ScaleTo::create(duration, 1.0f,1.0f);
	progress->runAction(scaleBy);

	auto moveTo = MoveTo::create(duration,Vec2(theSquare->getPosition().x + progressBG->getContentSize().width - 20,theSquare->getPosition().y));
	auto rotateTo = RotateTo::create(duration + 5*3, -20 - 360*3);
	auto spawnActionSprite = Spawn::createWithTwoActions(moveTo, rotateTo);
	theSquare->runAction(spawnActionSprite);

	this->scheduleOnce(schedule_selector(SplashScene::showBtnMove2NextScene), DISPLAY_TIME_SPLASH_SCREEN);

    return true;
}

void SplashScene::showBtnMove2NextScene(float dt) {


	auto playBtn = ui::Button::create("sprites/gameover/play-btn.png",
		"sprites/gameover/play-btn.png");
	playBtn->setAnchorPoint(Vec2(0.5,0.5));
	playBtn->setScale(1.5);
	playBtn->setPosition(Vec2(visibleSize.width/2+origin.x, visibleSize.height/2+origin.y));
	playBtn->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType touchType){
		if (touchType == cocos2d::ui::Widget::TouchEventType::ENDED) {
			playBtn->setTouchEnabled(false);
			GoToGameScene(0);
		}
	});
	this->addChild(playBtn);
}

void SplashScene::GoToGameScene(float dt) {
	//stop time
	//this->unschedule(schedule_selector(SplashScene::UpdateTimer));

	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}

