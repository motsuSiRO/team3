#pragma once
#include "DxLib.h"
#include "vector.h"

#define LIGHT_MARGINE_X 60
#define LIGHT_MARGINE_Y 55

class torch
{
public:
	vector2 pos;
	int torchAnimCnt;
	bool isAlive;
	static int torchGh;
	torch(vector2 pos);
	void drawTorch();
	void setTorch();
	void updateTorch();
};

class torchLight//�g�[�`�ɓ���light
{
public:
	vector2 pos;
	vector2 sway;
	//�g�[�`���g�̔ԍ�
	int number;
	bool isAlive;
	torch *t;
	//�S�̂̍��v�{��
	static int sum;
	static int lightGh;
	static bool setFlg;
	//�����t���R���X�g���N�^�őΏۂ̏������K��
	torchLight(torch *t);
	void initLight();
	void moveLight();
	void drawLight();
	void updateLight();
	void swayLight();
};

torchLight* getLightPointertes(int num);

//template <typename T>
//void setLight(T temp, light *lig)