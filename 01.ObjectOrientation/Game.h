#pragma once
#include"DxLib.h"

class Player;
class EnemyManager;
class Shot;

class Game
{
public:
	int Initialize();//初期化
	void Finalize();	//終了処理

	void Update();//更新
	void Draw();//描画

	// プレイヤーを生成.
	Player* player;
	//// 障害物を生成.
	EnemyManager* enemyManager;
	//*弾を生成
	Shot* shot;
};

