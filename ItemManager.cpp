#include "ItemManager.h"

ItemManager::ItemManager()
{
	SRand(GetNowCount());
	sound_mgr.SetSE("sound/se/magic04.mp3");//アイテム出現
	sound_mgr.SetSE("sound/se/speed-up1.mp3");//アイテム取得
}

ItemManager::~ItemManager()
{
}

void ItemManager::Update()
{
	if (frame > ITEM_CREATE_INTERVAL) {
		CreateItem();
		frame = 0;
	}

	for (int i = 0; i < item_array.size();) {
		item_array[i].Update();

		//フラグがfalseのアイテムを消去
		if (!item_array[i].GetFlag()) {
			item_array.erase(item_array.begin() + i);
		}
		else {
			i++;
		}
	}

	frame++;
}

void ItemManager::Draw()
{
	for (int i = 0; i < item_array.size(); i++) {
		item_array[i].Draw();
	}
}

void ItemManager::CreateItem()
{
	int ix, iy;
	ix = GetRand(FIELD_RIGHT - FIELD_LEFT - ITEM_RADIUS * 2);
	iy = GetRand(FIELD_BOTTOM - FIELD_TOP - ITEM_RADIUS * 2);
	ix += FIELD_LEFT + ITEM_RADIUS;
	iy += FIELD_TOP + ITEM_RADIUS;

	Item* pItem = new Item;
	pItem->Initialize(ix, iy, ITEM_RADIUS, 0, "");
	pItem->SetImage("pic/item.png");
	item_array.push_back(*pItem);
	delete pItem;
	pItem = NULL;

	sound_mgr.PlaySE(0);
}

void ItemManager::HitPlayer(Player& p)
{
	for (int i = 0; i < item_array.size(); i++) {
		if (item_array[i].HitCheck(p)) {
			item_array[i].SetFlag(false);
			p.gun.SetBulletType(item_array[i].GetBulletType());
			sound_mgr.PlaySE(1);
		}
	}
}
