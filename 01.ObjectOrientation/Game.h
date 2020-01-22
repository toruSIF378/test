#pragma once
#include"DxLib.h"

class Player;
class EnemyManager;
class Shot;

class Game
{
public:
	int Initialize();//������
	void Finalize();	//�I������

	void Update();//�X�V
	void Draw();//�`��

	// �v���C���[�𐶐�.
	Player* player;
	//// ��Q���𐶐�.
	EnemyManager* enemyManager;
	//*�e�𐶐�
	Shot* shot;
};

