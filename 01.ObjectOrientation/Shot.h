//�V���b�g
#pragma once
#include"Dxlib.h"
//�v���g�^�C�v�錾
struct Sprite;
struct Player;
struct Enemy;
class EnemyBase;

// �V���b�g�̐�.
//#define SHOT 20

class Shot
{
public:
	Sprite sprite;
	bool shotFlag;

	void Initialize();
	void Update( EnemyBase enemyArray[], int arrayNum);
	void Draw();
	//int shotX, shotY;
	//int shotGraph;
	// �V���b�g�{�^�����O�̃t���[���ŉ����ꂽ���ǂ�����ۑ�����ϐ���false(�����ꂢ�Ȃ�)����
	//bool prevshotFlag = false;
	//int shotW, shotH;
};
