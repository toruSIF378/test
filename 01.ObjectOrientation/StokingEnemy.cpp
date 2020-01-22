#include "StokingEnemy.h"



StokingEnemy::StokingEnemy()
	:EnemyBase("date/texture/B9MTGDgCQABGtgB.png")
{

}


StokingEnemy::~StokingEnemy()
{
}

void StokingEnemy::Update()
{
}

void StokingEnemy::Draw()
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
