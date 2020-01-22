#include<assert.h>
#include "EnemyManager.h"
#include"EnemyBase.h"
#include"Enemy.h"
#include"StokingEnemy.h"



EnemyManager::EnemyManager()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemies[i] = NULL;
	}
}


EnemyManager::~EnemyManager()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		assert(enemies[i] == NULL);
	}
}

void EnemyManager::CreateEnemy()
{
	// “G‚ğ¶¬.
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (i % 2 == 0)
		{
			enemies[i]=new Enemy();
		}
		else
		{
			enemies[i] = new StokingEnemy();
		}
	}
	// áŠQ•¨‚ÌˆÊ’u‚ğ‰Šú‰».
	float band = 10.0f;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemies[i]->SetPos(VGet(-band * (ENEMY_NUM / 2) + (band * i), 0, -1.0f));
	}
}

void EnemyManager::DestroyEnemy()
{
	// áŠQ•¨‚ğíœ.
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		delete(enemies[i]);
	}
}

void EnemyManager::Update()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemies[i]->Update();
	}
}

void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemies[i]->Draw();
	}
}
