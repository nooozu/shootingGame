#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"

#include "Player.h"
#include "ItemManager.h"
#include "SoundManager.h"

//�Q�[����ʃN���X
class Game : public BaseScene {
private:
	static int p1_win, p2_win;

	int frame, select_mode;
	bool fight;
	std::string s_win;

	Player *p1, *p2;
	SoundManager sound_mgr;
	ItemManager item_mgr;

	int background;

public :
    Game::Game(ISceneChanger* changer);
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B

};
