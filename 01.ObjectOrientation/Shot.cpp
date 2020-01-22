#include"Sprite.h"
#include"Player.h"
#include"Enemy.h"
#include"Shot.h"

void Shot::Initialize()
{
	// ショットのグラフィックをメモリにロード.
	sprite.graph = LoadGraph("data/texture/shot.png");
	// 弾が画面上に存在しているか保持する変数に『存在していない』を意味するfalseを代入しておく
	shotFlag = false;
	

	// 弾のグラフィックのサイズをえる
	GetGraphSize(sprite.graph, &sprite.w, &sprite.h);
}

void Shot::Update(EnemyBase enemyArray[], int arrayNum)
{
	//------------------------------//
	// 弾ルーチン
	//------------------------------//
	
	// 自機の弾iの移動ルーチン( 存在状態を保持している変数の内容がtrue(存在する)の場合のみ行う )
	if (shotFlag == true)
	{
		// 弾iを１６ドット上に移動させる
		sprite.pos.y -= 16;

		// 画面外に出てしまった場合は存在状態を保持している変数にfalse(存在しない)を代入する
		if (sprite.pos.y < -80)
		{
			shotFlag = false;
		}

		
	}

	// 弾のあたり判定.
	// 弾iが存在している場合のみ次の処理に映る
	if (shotFlag == 1)
	{
		for (int i = 0; i < arrayNum; i++)
		{
			// エネミーとの当たり判定
			if (((sprite.pos.x > enemyArray[i].sprite.pos.x && sprite.pos.x < enemyArray[i].sprite.pos.x + enemyArray[i].sprite.w) ||
				(enemyArray[i].sprite.pos.x > sprite.pos.x && enemyArray[i].sprite.pos.x < sprite.pos.x + sprite.w)) &&
				((sprite.pos.y > enemyArray[i].sprite.pos.y && sprite.pos.y< sprite.pos.y + enemyArray[i].sprite.h) ||
				(enemyArray[i].sprite.pos.y > sprite.pos.y && enemyArray[i].sprite.pos.y < sprite.pos.y + sprite.h)))
			{
				// 接触している場合は当たった弾の存在を消す
				shotFlag = 0;

				// エネミーの顔を歪めているかどうかを保持する変数に『歪めている』を表す１を代入
				enemyArray[i].enemyDamageFlag = 1;

				// エネミーの顔を歪めている時間を測るカウンタ変数に０を代入
				enemyArray[i].enemyDamageCounter = 0;
			}
		}
			
	}
}

void Shot::Draw()
{
	// 画面に弾iを描画する
	DrawGraph(sprite.pos.x, sprite.pos.y, sprite.graph, FALSE);
}
	




