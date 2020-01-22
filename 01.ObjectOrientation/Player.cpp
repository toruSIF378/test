//プレイヤー
#include"Sprite.h"
#include"Player.h"
#include"Shot.h"

//プレイヤーを初期化する
void Player::Initialize()
{
	// プレイヤーのグラフィックをメモリにロード＆表示座標を初期化
	sprite.graph = LoadGraph("data/texture/player.png");
	sprite.pos.x = 288;
	sprite.pos.y = 400;

	GetGraphSize(sprite.graph, &sprite.w, &sprite.h);

	// 前フレームでショットボタンを押されていたかを保存する変数にtrue(おされていた)を代入
	prevshotFlag = true;
}

//プレイヤーを更新する
void Player::Update(Shot& shot)
{
	//------------------------------//
	// プレイヤールーチン
	//------------------------------//
	{
		// 矢印キーを押していたらプレイヤーを移動させる
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

		// 弾の発射処理
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			// 前フレームでショットボタンを押したかが保存されている変数がfalseだったら弾を発射
			if (prevshotFlag == false)
			{
				// 画面上にでていない弾があるか、弾の数だけ繰り返して調べる
				// 弾iが画面上にでていない場合はその弾を画面に出す
				if (shot.shotFlag == false)
				{
					int Bw, Bh, Sw, Sh;

					// プレイヤーと弾の画像のサイズを得る
					GetGraphSize(sprite.graph, &Bw, &Bh);
					GetGraphSize(shot.sprite.graph, &Sw, &Sh);

					// 弾y位置をセット、位置はプレイヤーの中心にする
					shot.sprite.pos.x = (Bw - Sw) / 2 + sprite.pos.x;
					shot.sprite.pos.y = (Bh - Sh) / 2 + sprite.pos.y;

					// 弾iは現時点を持って存在するので、存在状態を保持する変数にtrueを代入する
					shot.shotFlag = true;
				}
			}
			// 前フレームでショットボタンを押されていたかを保存する変数にtrue(おされていた)を代入
			prevshotFlag = true;
		
		}
		else
		{
			// ショットボタンが押されていなかった場合は
			// 前フレームでショットボタンが押されていたかを保存する変数にfalse(おされていない)を代入
			prevshotFlag = false;
		}

		// プレイヤーが画面左端からはみ出そうになっていたら画面内の座標に戻してあげる
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
	// プレイヤーを描画
	DrawGraph(sprite.pos.x, sprite.pos.y, sprite.graph, FALSE);
}
