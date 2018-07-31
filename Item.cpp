#include "Item.h"

Item::Item()
{
	frame = ITEM_DELETE_TIME;
	SRand(GetNowCount());
	
	int par = GetRand(99);

	if (par > 75) {
		bullet_type = shot;
	}
	else if (par > 50) {
		bullet_type = rapid;
	}
	else if (par > 25) {
		bullet_type = reflect;
	}
	else {
		bullet_type = slow;
	}
}

Item::~Item()
{
}

void Item::Update()
{
	if (frame <= 0) {
		flag = false;
	}

	frame--;
}

void Item::Draw()
{
	//DrawCircle(x, y, radius, GetColor(255, 255, 0), TRUE);
	DrawRotaGraph(x, y, 1.0, 0.0, image, FALSE);
}