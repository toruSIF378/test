#pragma once

class EnemyBase;

#define ENEMY_NUM 10

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void CreateEnemy(); //敵の生成
	void DestroyEnemy(); //適の削除
	void Update();
	void Draw();
private:
	EnemyBase* enemies[ENEMY_NUM];
};

