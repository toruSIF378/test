//�v���C���[
#pragma once
#include"DxLib.h"

struct Sprite;
struct Shot;

class Player
{
public:
	/*Player();
	~Player();*/
	void Initialize();
	void Update(Shot& shot);
	void Draw();
	//VECTOR pos;
	VECTOR dir;
	bool prevshotFlag;	//�V���b�g�L�[�������ꂽ���̃t���O
//	Image GetImage() { return image; }
	//bool SHOT;
	//�v���g�^�C�v�錾
	Sprite sprite;
private:
	
	//int playerX, playerY, playerGraph;
	
};



