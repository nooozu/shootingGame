#pragma once
#include "DxLib.h"
#include "DefaultConfig.h"
#include <math.h>

class Controller
{
private:
	int game_pad;
	XINPUT_STATE input;

	float rot;

	float stick_lx, stick_ly, stick_rx, stick_ry;

	/*
	struct XINPUT_STATE
	{
		unsigned char	Buttons[ 16 ] ;	// ボタン１６個( 添字には XINPUT_BUTTON_DPAD_UP 等を使用する、
						//			0:押されていない  1:押されている )
		unsigned char	LeftTrigger ;	// 左トリガー( 0～255 )
		unsigned char	RightTrigger ;	// 右トリガー( 0～255 )
		short		ThumbLX ;	// 左スティックの横軸値( -32768 ～ 32767 )
		short		ThumbLY ;	// 左スティックの縦軸値( -32768 ～ 32767 )
		short		ThumbRX ;	// 右スティックの横軸値( -32768 ～ 32767 )
		short		ThumbRY ;	// 右スティックの縦軸値( -32768 ～ 32767 )
	} ;
	// XInputボタン入力定義
	#define XINPUT_BUTTON_DPAD_UP		    (0)	    // デジタル方向ボタン上
	#define XINPUT_BUTTON_DPAD_DOWN		    (1)	    // デジタル方向ボタン下
	#define XINPUT_BUTTON_DPAD_LEFT		    (2)	    // デジタル方向ボタン左
	#define XINPUT_BUTTON_DPAD_RIGHT	    (3)	    // デジタル方向ボタン右
	#define XINPUT_BUTTON_START		        (4)	    // STARTボタン
	#define XINPUT_BUTTON_BACK		        (5)	    // BACKボタン
	#define XINPUT_BUTTON_LEFT_THUMB	    (6)	    // 左スティック押し込み
	#define XINPUT_BUTTON_RIGHT_THUMB	    (7)	    // 右スティック押し込み
	#define XINPUT_BUTTON_LEFT_SHOULDER	    (8)	    // LBボタン
	#define XINPUT_BUTTON_RIGHT_SHOULDER	(9)	    // RBボタン
	#define XINPUT_BUTTON_A			        (10)	// Aボタン
	#define XINPUT_BUTTON_B			        (11)	// Bボタン
	#define XINPUT_BUTTON_X			        (12)	// Xボタン
	#define XINPUT_BUTTON_Y			        (13)	// Yボタン
	*/

public:

	Controller();
	~Controller();

	void Update();
	void Draw();

	void SetGamePad(int i) { game_pad = i; }
	int GetGamePad() { return game_pad; }
	
	float GetStick_LeftY() { return stick_ly; }
	float GetStick_LeftX() { return stick_lx; }
	float GetStick_RightY() { return stick_ry; }
	float GetStick_RightX() { return stick_rx; }

	float GetStickRightRotate() { return rot; }

	bool IsStickRDown();
	bool GetLeftButton() { return ((input.Buttons[8]) ? true : false); }
	bool GetRightButton() { return ((input.Buttons[9]) ? true : false); }
	bool GetButtonX() { return ((input.Buttons[12]) ? true : false); }
	//bool GetRightButton() { return ((input.Buttons[9]) ? true : false); }
};