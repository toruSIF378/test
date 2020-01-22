#include"Sprite.h"
#include "Game.h"
#include"EnemyManager.h"
#include"Player.h"
#include"Enemy.h"
#include"Shot.h"


int Game::Initialize()
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	// 画面モードの設定
	SetGraphMode(640, 480, 16);		// 解像度を640*480、colorを16bitに設定.
	ChangeWindowMode(TRUE);			// ウインドウモードに.

	//プレイヤーの生成
	player = new Player();
	//エネミーマネージャーを生成の生成
	enemyManager = new EnemyManager();

	//敵の生成
	enemyManager->CreateEnemy();
	//ショットの生成
	shot = new Shot();

	return 0;
}

void Game::Finalize()
{
	delete(player);
	player = NULL;

	enemyManager->DestroyEnemy();
	delete(enemyManager);
	enemyManager = NULL;

	delete(shot);
	shot = NULL;

	DxLib_End();				// ＤＸライブラリ使用の終了処理
}

void Game::Update()
{
	// プレイヤー制御.
	player->Update(* shot);

	enemyManager->Update();
}

void Game::Draw()
{
	// 画面を初期化(真っ黒にする)
	ClearDrawScreen();

	player->Draw();

	enemyManager->Draw();


	// 裏画面の内容を表画面にコピーする（描画の確定）.
	ScreenFlip();
}
