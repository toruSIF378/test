#pragma once
#include"DxLib.h"

// スプライト(2D画像)構造体
struct Sprite
{
	VECTOR pos;
	int		w;
	int		h;
	int		graph;		// ロードしたテクスチャのハンドル
};