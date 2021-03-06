#pragma once
#include "../BasePopup.h"

class FreeToPlayPopup : public BasePopup
{
private:
	cocos2d::Sprite* bg;

	cocos2d::ui::Button* btnBuyPkgBig;
	cocos2d::ui::Button* btnBuyPkgSmall;

	cocos2d::Label* txtCoinPkgBig;
	cocos2d::Label* txtCoinPkgSmall;
	cocos2d::Label* txtCrownPkgBig;
	cocos2d::Label* txtCrownPkgSmall;

	cocos2d::Label* createText(int fontSize, float percentX = 0.0f, float precentY = 0.0f);
	cocos2d::ui::Button* createButtonBuy(float scaleX, float scaleY, float percentX, float precentY);
	void onButtonTouched(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
public:
	/// <summary>
	/// init UI
	/// </summary>
	/// <returns>is init success</returns>
	virtual bool init();

	/**
	* prepare and show
	*/
	virtual bool prepareAndShow(cocos2d::Node* parent);

	/// <summary>
	/// define create function
	/// </summary>
	/// <param name="">name of class</param>
	/// <returns>return class object</returns>
	CREATE_FUNC(FreeToPlayPopup);
};