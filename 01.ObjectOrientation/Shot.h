//ショット
#pragma once
#include"Dxlib.h"
//プロトタイプ宣言
struct Sprite;
struct Player;
struct Enemy;
class EnemyBase;

// ショットの数.
//#define SHOT 20

class Shot
{
public:
	Sprite sprite;
	bool shotFlag;

	void Initialize();
	void Update( EnemyBase enemyArray[], int arrayNum);
	void Draw();
	//int shotX, shotY;
	//int shotGraph;
	// ショットボタンが前のフレームで押されたかどうかを保存する変数にfalse(押されいない)を代入
	//bool prevshotFlag = false;
	//int shotW, shotH;
};
