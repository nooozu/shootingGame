#pragma once
#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 720
#define SCREEN_CENTER_X (SCREEN_WIDTH / 2)
#define SCREEN_CENTER_Y	(SCREEN_HEIGHT / 2)

#define UI_WIDTH        50

#define FIELD_TOP       0
#define FIELD_BOTTOM    SCREEN_HEIGHT
#define FIELD_LEFT      UI_WIDTH
#define FIELD_RIGHT     (SCREEN_WIDTH-UI_WIDTH)

#define PI 3.14159265359
#define DEG_TO_RAD(x) (x * PI / 180)
#define RAD_TO_DEG(x) (x * 180 / PI)

#define POW2(x) ((x) * (x))

//ÉAÉCÉeÉÄ

#define ITEM_RADIUS 10
#define ITEM_DELETE_TIME (60*30)        //(FPS*ïbêî)
#define ITEM_CREATE_INTERVAL (60*10)