#pragma once
#include "BaseScene.h"

//���j���[��ʃN���X
class Menu : public BaseScene {
private:
	int frame;
	int select_mode;
	int image;
public :
    Menu(ISceneChanger* changer);
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    //void Finalize() override ;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B

};
