//プレイヤー
#pragma once
#include"DxLib.h"

struct Sprite;
struct Shot;

class Player
{
public:
	/*Player();
	~Player();*/
	void Initialize();
	void Update(Shot& shot);
	void Draw();
	//VECTOR pos;
	VECTOR dir;
	bool prevshotFlag;	//ショットキーが押されたかのフラグ
//	Image GetImage() { return image; }
	//bool SHOT;
	//プロトタイプ宣言
	Sprite sprite;
private:
	
	//int playerX, playerY, playerGraph;
	
};



