#include"Sprite.h"
#include "Game.h"
#include"EnemyManager.h"
#include"Player.h"
#include"Enemy.h"
#include"Shot.h"


int Game::Initialize()
{
	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(640, 480, 16);		// �𑜓x��640*480�Acolor��16bit�ɐݒ�.
	ChangeWindowMode(TRUE);			// �E�C���h�E���[�h��.

	//�v���C���[�̐���
	player = new Player();
	//�G�l�~�[�}�l�[�W���[�𐶐��̐���
	enemyManager = new EnemyManager();

	//�G�̐���
	enemyManager->CreateEnemy();
	//�V���b�g�̐���
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

	DxLib_End();				// �c�w���C�u�����g�p�̏I������
}

void Game::Update()
{
	// �v���C���[����.
	player->Update(* shot);

	enemyManager->Update();
}

void Game::Draw()
{
	// ��ʂ�������(�^�����ɂ���)
	ClearDrawScreen();

	player->Draw();

	enemyManager->Draw();


	// ����ʂ̓��e��\��ʂɃR�s�[����i�`��̊m��j.
	ScreenFlip();
}
