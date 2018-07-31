#include "Controller.h"

Controller::Controller()
{
	rot = 0;

	game_pad = 0;
	stick_lx = 0, stick_ly = 0;
	stick_rx = 0, stick_ry = 0;
}

Controller::~Controller()
{

}

void Controller::Update()
{
	if (game_pad != 0) {
		GetJoypadXInputState(game_pad, &input);

		stick_lx = (float)input.ThumbLX / 32767;
		stick_ly = (float)input.ThumbLY / 32767;
		stick_rx = (float)input.ThumbRX / 32767;
		stick_ry = (float)input.ThumbRY / 32767;

		if (IsStickRDown()) {
			rot = atan2(-stick_ry, stick_rx) * 180.0 / PI;
		}
	}
}

void Controller::Draw()
{
	if (game_pad != 0) {
		
		// ‰æ–Ê‚É XINPUT_STATE ‚Ì’†g‚ğ•`‰æ
		int Color = GetColor(255, 255, 255);
		DrawFormatString(0, 0, Color, "LeftTrigger:%d RightTrigger:%d",
			input.LeftTrigger, input.RightTrigger);
		DrawFormatString(0, 16, Color, "LX:%.5f - LY:%.5f", stick_lx, stick_ly);
		DrawFormatString(0, 32, Color, "RX:%.5f - RY:%.5f", stick_rx, stick_ry);
		DrawFormatString(0, 48, Color, "Rstick_rot = %.3f", rot);
	}
}

bool Controller::IsStickRDown()
{
	if (fabs(stick_rx) > 0.7 || fabs(stick_ry) > 0.7) {
		return true;
	}
	else {
		return false;
	}
}