//エネミー(エネミーを管理する)
#pragma once
#include"DxLib.h"
#include"EnemyBase.h"
//プロトタイプ宣言
struct Sprite;


class Enemy:public EnemyBase
{
private:
	
	
	//int DamageGraph;
	// エネミーが右移動しているかどうかのフラグをリセット
	bool enemyRightMove = true;

public:
	//見てるだけのものはGetterを準備する
	//void OnHitShot();
	//Image GetImage() { return image; }
	//いじちゃったよ
	//bool DamageFlag;
	//int DamageCounter;
	Enemy();
	virtual ~Enemy();
	Sprite sprite;
	void Initialize(int index);
	void Update();
	void Draw();

	//int enemyX, enemyY, enemyGraph;
	
	//int enemyW, enemyH;


};
