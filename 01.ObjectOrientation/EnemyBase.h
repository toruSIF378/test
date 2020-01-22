#pragma once
#include"DxLib.h"
#include "Sprite.h";

class EnemyBase
{
public:
	EnemyBase(char* path);
	virtual~EnemyBase();

	int GetGraphHandle() { return graphHandle; }

	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	void Update();

	void Draw();

	Sprite sprite;

	int enemyDamageCounter, enemyDamageGraph;
	bool enemyDamageFlag;
protected:
	int graphHandle;
	VECTOR pos;
	float speed;
	bool RightMove;
	
};

