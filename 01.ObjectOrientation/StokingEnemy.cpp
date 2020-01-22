#include "StokingEnemy.h"



StokingEnemy::StokingEnemy()
	:EnemyBase("date/texture/B9MTGDgCQABGtgB.png")
{

}


StokingEnemy::~StokingEnemy()
{
}

void StokingEnemy::Update()
{
}

void StokingEnemy::Draw()
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
