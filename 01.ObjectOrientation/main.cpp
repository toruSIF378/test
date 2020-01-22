//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include"Game.h"

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------


// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	
	Game* game = new Game();

	if (game->Initialize() == -1)
	{
		delete(game);
		return -1;
	}
	// グラフィックの描画先を裏画面にセット
	//SetDrawScreen(DX_SCREEN_BACK);
	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//制御.
		game->Update();
		//描画.
		game->Draw();
	}

	game->Finalize();
	delete(game);
	
	

	return 0;					// ソフトの終了
}