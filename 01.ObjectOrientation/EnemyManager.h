#pragma once

class EnemyBase;

#define ENEMY_NUM 10

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void CreateEnemy(); //“G‚Ì¶¬
	void DestroyEnemy(); //“K‚Ìíœ
	void Update();
	void Draw();
private:
	EnemyBase* enemies[ENEMY_NUM];
};

