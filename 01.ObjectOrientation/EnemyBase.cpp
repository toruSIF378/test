#include "EnemyBase.h"



EnemyBase::EnemyBase(char* path)
{
	//�摜�̓ǂݍ���
	graphHandle = LoadGraph(path);
	if (graphHandle < 0)
	{
		printfDx("EnemyBase:�f�[�^�ǂݍ��݂Ɏ��s");
	}
	printfDx("EnemyBase!\n");
}


EnemyBase::~EnemyBase()
{
	printfDx("~EnemyBase!\n");
}

void EnemyBase::Update()
{
	
	// �G�l�~�[�̃O���t�B�b�N�̃T�C�Y�𓾂�
	GetGraphSize(sprite.graph, &sprite.w, &sprite.h);
}

void EnemyBase::Draw()
{
	//�摜�̕`��
	DrawGraph(graphHandle,sprite.pos.x,sprite.pos.y,TRUE);
}
