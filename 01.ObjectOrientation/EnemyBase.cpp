#include "EnemyBase.h"



EnemyBase::EnemyBase(char* path)
{
	//画像の読み込み
	graphHandle = LoadGraph(path);
	if (graphHandle < 0)
	{
		printfDx("EnemyBase:データ読み込みに失敗");
	}
	printfDx("EnemyBase!\n");
}


EnemyBase::~EnemyBase()
{
	printfDx("~EnemyBase!\n");
}

void EnemyBase::Update()
{
	
	// エネミーのグラフィックのサイズを得る
	GetGraphSize(sprite.graph, &sprite.w, &sprite.h);
}

void EnemyBase::Draw()
{
	//画像の描画
	DrawGraph(graphHandle,sprite.pos.x,sprite.pos.y,TRUE);
}
