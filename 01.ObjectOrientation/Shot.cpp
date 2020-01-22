#include"Sprite.h"
#include"Player.h"
#include"Enemy.h"
#include"Shot.h"

void Shot::Initialize()
{
	// �V���b�g�̃O���t�B�b�N���������Ƀ��[�h.
	sprite.graph = LoadGraph("data/texture/shot.png");
	// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����false�������Ă���
	shotFlag = false;
	

	// �e�̃O���t�B�b�N�̃T�C�Y������
	GetGraphSize(sprite.graph, &sprite.w, &sprite.h);
}

void Shot::Update(EnemyBase enemyArray[], int arrayNum)
{
	//------------------------------//
	// �e���[�`��
	//------------------------------//
	
	// ���@�̒ei�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e��true(���݂���)�̏ꍇ�̂ݍs�� )
	if (shotFlag == true)
	{
		// �ei���P�U�h�b�g��Ɉړ�������
		sprite.pos.y -= 16;

		// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ���false(���݂��Ȃ�)��������
		if (sprite.pos.y < -80)
		{
			shotFlag = false;
		}

		
	}

	// �e�̂����蔻��.
	// �ei�����݂��Ă���ꍇ�̂ݎ��̏����ɉf��
	if (shotFlag == 1)
	{
		for (int i = 0; i < arrayNum; i++)
		{
			// �G�l�~�[�Ƃ̓����蔻��
			if (((sprite.pos.x > enemyArray[i].sprite.pos.x && sprite.pos.x < enemyArray[i].sprite.pos.x + enemyArray[i].sprite.w) ||
				(enemyArray[i].sprite.pos.x > sprite.pos.x && enemyArray[i].sprite.pos.x < sprite.pos.x + sprite.w)) &&
				((sprite.pos.y > enemyArray[i].sprite.pos.y && sprite.pos.y< sprite.pos.y + enemyArray[i].sprite.h) ||
				(enemyArray[i].sprite.pos.y > sprite.pos.y && enemyArray[i].sprite.pos.y < sprite.pos.y + sprite.h)))
			{
				// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
				shotFlag = 0;

				// �G�l�~�[�̊��c�߂Ă��邩�ǂ�����ێ�����ϐ��Ɂw�c�߂Ă���x��\���P����
				enemyArray[i].enemyDamageFlag = 1;

				// �G�l�~�[�̊��c�߂Ă��鎞�Ԃ𑪂�J�E���^�ϐ��ɂO����
				enemyArray[i].enemyDamageCounter = 0;
			}
		}
			
	}
}

void Shot::Draw()
{
	// ��ʂɒei��`�悷��
	DrawGraph(sprite.pos.x, sprite.pos.y, sprite.graph, FALSE);
}
	




