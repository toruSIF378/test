//�G�l�~�[(�G�l�~�[���Ǘ�����)
#pragma once
#include"DxLib.h"
#include"EnemyBase.h"
//�v���g�^�C�v�錾
struct Sprite;


class Enemy:public EnemyBase
{
private:
	
	
	//int DamageGraph;
	// �G�l�~�[���E�ړ����Ă��邩�ǂ����̃t���O�����Z�b�g
	bool enemyRightMove = true;

public:
	//���Ă邾���̂��̂�Getter����������
	//void OnHitShot();
	//Image GetImage() { return image; }
	//�������������
	//bool DamageFlag;
	//int DamageCounter;
	Enemy();
	virtual ~Enemy();
	Sprite sprite;
	void Initialize(int index);
	void Update();
	void Draw();

	//int enemyX, enemyY, enemyGraph;
	
	//int enemyW, enemyH;


};
