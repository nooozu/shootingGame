#pragma once
#include "Item.h"
#include "Player.h"
#include <vector>

class ItemManager
{
	int frame;
	std::vector<Item> item_array;
	SoundManager sound_mgr;

public:
	ItemManager();
	~ItemManager();
	void Update();
	void Draw();

	void CreateItem();

	void HitPlayer(Player& p);
};

