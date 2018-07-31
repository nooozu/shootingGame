#pragma once
#include "DxLib.h"
#include "DefaultConfig.h"
#include "Task.h"
#include "ISceneChanger.h"

//�V�[���̊��N���X�B
class BaseScene : public Task {

protected:
    ISceneChanger* mSceneChanger;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
	XINPUT_STATE pad1_input, pad2_input;

public :
    BaseScene(ISceneChanger* changer);
    virtual ~BaseScene(){}
    virtual void Initialize() override {}    //�������������I�[�o�[���C�h�B
	virtual void Finalize() override {}        //�I���������I�[�o�[���C�h�B
	virtual void Update() override;        //�X�V�������I�[�o�[���C�h�B
	virtual void Draw() override {}            //�`�揈�����I�[�o�[���C�h�B

};
