#pragma once

class EnemyBase;

#define ENEMY_NUM 10

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void CreateEnemy(); //�G�̐���
	void DestroyEnemy(); //�K�̍폜
	void Update();
	void Draw();
private:
	EnemyBase* enemies[ENEMY_NUM];
};

