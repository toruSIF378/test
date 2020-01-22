//�v���C���[
#include"Sprite.h"
#include"Player.h"
#include"Shot.h"

//�v���C���[������������
void Player::Initialize()
{
	// �v���C���[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	sprite.graph = LoadGraph("data/texture/player.png");
	sprite.pos.x = 288;
	sprite.pos.y = 400;

	GetGraphSize(sprite.graph, &sprite.w, &sprite.h);

	// �O�t���[���ŃV���b�g�{�^����������Ă�������ۑ�����ϐ���true(������Ă���)����
	prevshotFlag = true;
}

//�v���C���[���X�V����
void Player::Update(Shot& shot)
{
	//------------------------------//
	// �v���C���[���[�`��
	//------------------------------//
	{
		// ���L�[�������Ă�����v���C���[���ړ�������
		if (CheckHitKey(KEY_INPUT_UP) == 1)
		{
			sprite.pos.y -= 3;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		{
			sprite.pos.y += 3;
		}
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			sprite.pos.x -= 3;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			sprite.pos.x += 3;
		}

		// �e�̔��ˏ���
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			// �O�t���[���ŃV���b�g�{�^���������������ۑ�����Ă���ϐ���false��������e�𔭎�
			if (prevshotFlag == false)
			{
				// ��ʏ�ɂłĂ��Ȃ��e�����邩�A�e�̐������J��Ԃ��Ē��ׂ�
				// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
				if (shot.shotFlag == false)
				{
					int Bw, Bh, Sw, Sh;

					// �v���C���[�ƒe�̉摜�̃T�C�Y�𓾂�
					GetGraphSize(sprite.graph, &Bw, &Bh);
					GetGraphSize(shot.sprite.graph, &Sw, &Sh);

					// �ey�ʒu���Z�b�g�A�ʒu�̓v���C���[�̒��S�ɂ���
					shot.sprite.pos.x = (Bw - Sw) / 2 + sprite.pos.x;
					shot.sprite.pos.y = (Bh - Sh) / 2 + sprite.pos.y;

					// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ���true��������
					shot.shotFlag = true;
				}
			}
			// �O�t���[���ŃV���b�g�{�^����������Ă�������ۑ�����ϐ���true(������Ă���)����
			prevshotFlag = true;
		
		}
		else
		{
			// �V���b�g�{�^����������Ă��Ȃ������ꍇ��
			// �O�t���[���ŃV���b�g�{�^����������Ă�������ۑ�����ϐ���false(������Ă��Ȃ�)����
			prevshotFlag = false;
		}

		// �v���C���[����ʍ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
		if (sprite.pos.x < 0)
		{
			sprite.pos.x = 0;
		}
		if (sprite.pos.x > 640 - 64)
		{
			sprite.pos.x = 640 - 64;
		}
		if (sprite.pos.y < 0)
		{
			sprite.pos.y = 0;
		}
		if (sprite.pos.y > 480 - 64)
		{
			sprite.pos.y = 480 - 64;
		}

		
	}
}

void Player::Draw()
{
	// �v���C���[��`��
	DrawGraph(sprite.pos.x, sprite.pos.y, sprite.graph, FALSE);
}
