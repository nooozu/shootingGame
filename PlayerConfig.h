#pragma once

//プレイヤーHP
#define MAX_LIFE 4

//初期無敵時間
#define FIRST_INVICIBLE_FRAME  180
#define DAMAGE_INVICIBLE_FRAME 120

//1フレームの加速量
#define ACCELERATION  0.07
//1フレームの減速量
#define DECELERATION  0.01

//攻撃時の最大移動速度
#define ATTACK_MAX_ACCELERATION 0.5

//スティックの感度
#define STICK_SENSITIVITY 0.6

//各弾の発射間隔
#define BULLET_INTERVAL_NORMAL   35
#define BULLET_INTERVAL_SHOT     50
#define BULLET_INTERVAL_REFLECT  45
#define BULLET_INTERVAL_RAPID    6
#define BULLET_INTERVAL_SLOW     20

//各弾の当たり判定（半径）
#define BULLET_RADIUS_NORMAL     2
#define BULLET_RADIUS_SHOT       4
#define BULLET_RADIUS_REFLECT    5
#define BULLET_RADIUS_RAPID      2
#define BULLET_RADIUS_SLOW       35

//各弾の移動速度
#define BULLET_SPEED_NORMAL      5
#define BULLET_SPEED_SHOT        5
#define BULLET_SPEED_REFLECT     4.5
#define BULLET_SPEED_RAPID       4.5
#define BULLET_SPEED_SLOW        1.0

//各弾の総弾数
#define BULLET_AMMO_SHOT         5*4
#define BULLET_AMMO_REFLECT      15
#define BULLET_AMMO_RAPID        35
#define BULLET_AMMO_SLOW         1

//持続フレーム
#define REFLECT_DELETE_TIME      (60*10)
#define RAPID_DELETE_TIME        (60*2.1)
#define SLOW_DELETE_TIME         (60*30)
