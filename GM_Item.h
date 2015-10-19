#pragma once
#include "game_body.h"
#define item_max	50
struct Item
{
	int x;
	int y;
	int g_w;//‰æ‘œƒTƒCƒY
	int g_h;//V


	int spead;
	int Glaphic;
	int pattern;
	int kouka;
};
class CItem
{
private:
	CGame_Body* body;
	int max;
	
public:
	Item item[item_max];
	int Set_Item(int x,int y,int *glaphic_id,int pattern,int spead,int kouka);
	int DeleteAt_Item(int num);
	int Farst_Section(CGame_Body* body_dist);
	int DrawItem(void);
	int Glaphic_ID_check(int kouka_num);
};
extern CItem item;