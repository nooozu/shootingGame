#include "BaseScene.h"
#include "DxLib.h"

BaseScene::BaseScene(ISceneChanger* changer)
{
    mSceneChanger = changer;
}

void BaseScene::Update()
{
	GetJoypadXInputState(DX_INPUT_PAD1, &pad1_input);
	GetJoypadXInputState(DX_INPUT_PAD2, &pad2_input);
}