#pragma once

//�v���C���[HP
#define MAX_LIFE 4

//�������G����
#define FIRST_INVICIBLE_FRAME  180
#define DAMAGE_INVICIBLE_FRAME 120

//1�t���[���̉�����
#define ACCELERATION  0.07
//1�t���[���̌�����
#define DECELERATION  0.01

//�U�����̍ő�ړ����x
#define ATTACK_MAX_ACCELERATION 0.5

//�X�e�B�b�N�̊��x
#define STICK_SENSITIVITY 0.6

//�e�e�̔��ˊԊu
#define BULLET_INTERVAL_NORMAL   35
#define BULLET_INTERVAL_SHOT     50
#define BULLET_INTERVAL_REFLECT  45
#define BULLET_INTERVAL_RAPID    6
#define BULLET_INTERVAL_SLOW     20

//�e�e�̓����蔻��i���a�j
#define BULLET_RADIUS_NORMAL     2
#define BULLET_RADIUS_SHOT       4
#define BULLET_RADIUS_REFLECT    5
#define BULLET_RADIUS_RAPID      2
#define BULLET_RADIUS_SLOW       35

//�e�e�̈ړ����x
#define BULLET_SPEED_NORMAL      5
#define BULLET_SPEED_SHOT        5
#define BULLET_SPEED_REFLECT     4.5
#define BULLET_SPEED_RAPID       4.5
#define BULLET_SPEED_SLOW        1.0

//�e�e�̑��e��
#define BULLET_AMMO_SHOT         5*4
#define BULLET_AMMO_REFLECT      15
#define BULLET_AMMO_RAPID        35
#define BULLET_AMMO_SLOW         1

//�����t���[��
#define REFLECT_DELETE_TIME      (60*10)
#define RAPID_DELETE_TIME        (60*2.1)
#define SLOW_DELETE_TIME         (60*30)
