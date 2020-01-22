//�G�l�~�[
#include"Sprite.h"
#include"Enemy.h"
#include"Shot.h"



Enemy::Enemy()
	: EnemyBase("data/texture/enemy.png")
{
	sprite.pos.x =(float)(0 * 100);
	sprite.pos.y = 50;
	speed = 2.5f;
	RightMove = true;
}

Enemy::~Enemy()
{
	DeleteGraph(graphHandle);
}

//�G�l�~�[������������
void Enemy::Initialize(int index)
{
	
}

void Enemy::Update()
{
	//------------------------------//
	// �G�l�~�[���[�`��
	//------------------------------//
	
		// �G�l�~�[�̍��W���ړ����Ă�������Ɉړ�����
		if (enemyRightMove == true)
		{
			sprite.pos.x += 3;
		}
		else
		{
			sprite.pos.x -= 3;
		}

		// �G�l�~�[����ʒ[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
		if (sprite.pos.x > 576)
		{
			sprite.pos.x = 576;
			enemyRightMove = false;
		}
		else if (sprite.pos.x < 0)
		{
			sprite.pos.x = 0;
			enemyRightMove = true;
		}
		// �G�l�~�[�̃O���t�B�b�N���������Ƀ��[�h���_���[�W���̏�ԊǗ��p�̕ϐ���������
		enemyDamageGraph = LoadGraph("data/texture/enemyDamage.png");

		// �G�l�~�[�����c�߂Ă��邩�ǂ����̕ϐ��Ɂw�c�߂Ă��Ȃ��x��\���O����
		enemyDamageFlag = 0;
}

void Enemy::Draw()
{
	// �G�l�~�[��`��
	// ���c�߂Ă��邩�ǂ����ŏ����𕪊�
	if (enemyDamageFlag == 1)
	{
		// ���c�߂Ă���ꍇ�̓_���[�W���̃O���t�B�b�N��`�悷��
		DrawGraph(sprite.pos.x, sprite.pos.y, enemyDamageGraph, FALSE);

		// ���c�߂Ă��鎞�Ԃ𑪂�J�E���^�[�ɂP�����Z����
		enemyDamageCounter++;

		// �������c�ߏ��߂� �R�O �t���[���o�߂��Ă������̘c�񂾏�Ԃ���
		// ���ɖ߂��Ă�����
		if (enemyDamageCounter == 30)
		{
			// �w�c��ł��Ȃ��x��\���O����
			enemyDamageFlag = 0;
		}
	}
	else
	{
		DrawGraph(sprite.pos.x, sprite.pos.y, sprite.graph, FALSE);
	}
}
