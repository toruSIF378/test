//エネミー
#include"Sprite.h"
#include"Enemy.h"
#include"Shot.h"



Enemy::Enemy()
	: EnemyBase("data/texture/enemy.png")
{
	sprite.pos.x =(float)(0 * 100);
	sprite.pos.y = 50;
	speed = 2.5f;
	RightMove = true;
}

Enemy::~Enemy()
{
	DeleteGraph(graphHandle);
}

//エネミーを初期化する
void Enemy::Initialize(int index)
{
	
}

void Enemy::Update()
{
	//------------------------------//
	// エネミールーチン
	//------------------------------//
	
		// エネミーの座標を移動している方向に移動する
		if (enemyRightMove == true)
		{
			sprite.pos.x += 3;
		}
		else
		{
			sprite.pos.x -= 3;
		}

		// エネミーが画面端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
		if (sprite.pos.x > 576)
		{
			sprite.pos.x = 576;
			enemyRightMove = false;
		}
		else if (sprite.pos.x < 0)
		{
			sprite.pos.x = 0;
			enemyRightMove = true;
		}
		// エネミーのグラフィックをメモリにロード＆ダメージ時の状態管理用の変数を初期化
		enemyDamageGraph = LoadGraph("data/texture/enemyDamage.png");

		// エネミーが顔を歪めているかどうかの変数に『歪めていない』を表す０を代入
		enemyDamageFlag = 0;
}

void Enemy::Draw()
{
	// エネミーを描画
	// 顔を歪めているかどうかで処理を分岐
	if (enemyDamageFlag == 1)
	{
		// 顔を歪めている場合はダメージ時のグラフィックを描画する
		DrawGraph(sprite.pos.x, sprite.pos.y, enemyDamageGraph, FALSE);

		// 顔を歪めている時間を測るカウンターに１を加算する
		enemyDamageCounter++;

		// もし顔を歪め初めて ３０ フレーム経過していたら顔の歪んだ状態から
		// 元に戻してあげる
		if (enemyDamageCounter == 30)
		{
			// 『歪んでいない』を表す０を代入
			enemyDamageFlag = 0;
		}
	}
	else
	{
		DrawGraph(sprite.pos.x, sprite.pos.y, sprite.graph, FALSE);
	}
}
