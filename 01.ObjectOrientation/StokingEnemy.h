#pragma once
#include"DxLib.h"
#include"Sprite.h"
#include"EnemyBase.h"
class StokingEnemy
	:public EnemyBase
{
public:
	StokingEnemy();
	~StokingEnemy();

	void Update();
	void Draw();
};