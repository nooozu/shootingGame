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
		unsigned char	Buttons[ 16 ] ;	// �{�^���P�U��( �Y���ɂ� XINPUT_BUTTON_DPAD_UP �����g�p����A
						//			0:������Ă��Ȃ�  1:������Ă��� )
		unsigned char	LeftTrigger ;	// ���g���K�[( 0�`255 )
		unsigned char	RightTrigger ;	// �E�g���K�[( 0�`255 )
		short		ThumbLX ;	// ���X�e�B�b�N�̉����l( -32768 �` 32767 )
		short		ThumbLY ;	// ���X�e�B�b�N�̏c���l( -32768 �` 32767 )
		short		ThumbRX ;	// �E�X�e�B�b�N�̉����l( -32768 �` 32767 )
		short		ThumbRY ;	// �E�X�e�B�b�N�̏c���l( -32768 �` 32767 )
	} ;
	// XInput�{�^�����͒�`
	#define XINPUT_BUTTON_DPAD_UP		    (0)	    // �f�W�^�������{�^����
	#define XINPUT_BUTTON_DPAD_DOWN		    (1)	    // �f�W�^�������{�^����
	#define XINPUT_BUTTON_DPAD_LEFT		    (2)	    // �f�W�^�������{�^����
	#define XINPUT_BUTTON_DPAD_RIGHT	    (3)	    // �f�W�^�������{�^���E
	#define XINPUT_BUTTON_START		        (4)	    // START�{�^��
	#define XINPUT_BUTTON_BACK		        (5)	    // BACK�{�^��
	#define XINPUT_BUTTON_LEFT_THUMB	    (6)	    // ���X�e�B�b�N��������
	#define XINPUT_BUTTON_RIGHT_THUMB	    (7)	    // �E�X�e�B�b�N��������
	#define XINPUT_BUTTON_LEFT_SHOULDER	    (8)	    // LB�{�^��
	#define XINPUT_BUTTON_RIGHT_SHOULDER	(9)	    // RB�{�^��
	#define XINPUT_BUTTON_A			        (10)	// A�{�^��
	#define XINPUT_BUTTON_B			        (11)	// B�{�^��
	#define XINPUT_BUTTON_X			        (12)	// X�{�^��
	#define XINPUT_BUTTON_Y			        (13)	// Y�{�^��
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