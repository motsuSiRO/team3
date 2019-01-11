#include "light.h"

int torchLight::lightGh;
int torch::torchGh;
int torchLight::sum = 0;
bool torchLight::setFlg = false;

torch t1(vector2(30, 30)), t2(vector2(230, 230));
torchLight light1(&t1), light2(&t2);


torch::torch(vector2 pos) :pos(pos),torchAnimCnt(0),isAlive(false)
{

}

void torch::setTorch()
{
	if (!isAlive&&CheckHitKey(KEY_INPUT_L))
		isAlive = true;
}

void torch::drawTorch()
{
	torchAnimCnt++;
	DrawRectGraph(pos.x, pos.y, 100 * (torchAnimCnt/6%10), 0, 100, 100, torch::torchGh, true);
}

void torch::updateTorch()
{
	setTorch();
	//drawTorch();
}

torchLight::torchLight(torch *t)
{
	sway = vector2(0, 0);
	torchLight::sum++;
	number = sum;
	this->t = t;//&t���ƃo�O��̂͂Ȃ��H
	pos = t->pos;
	//pos = vector2(0, 400);
	isAlive = false;
}

void torchLight::initLight()
{
	if (!torchLight::setFlg)
	{
		//��ŏꏊ�ς���
		torchLight::lightGh = LoadGraph("resource/image/lightcircle.png", true);
		torchLight::setFlg = true;
		torch::torchGh = LoadGraph("resource/image/taimatu.png", true);
	}

	if (!isAlive&&t->isAlive)
	{
		//�_�΂���
		isAlive = true;
	}
}

void torchLight::moveLight()
{
	//��ŕς���
	t->updateTorch();
	if (isAlive)
	{
		//�`�悷��ʒu�擾
		pos = t->pos;

		//�f�o�b�O�p
		if (CheckHitKey(KEY_INPUT_RIGHT))
			t->pos.x++;
		if (CheckHitKey(KEY_INPUT_LEFT))
			t->pos.x--;
		if (CheckHitKey(KEY_INPUT_UP))
			t->pos.y--;
		if (CheckHitKey(KEY_INPUT_DOWN))
			t->pos.y++;
	}
}

void torchLight::drawLight()
{
	if (isAlive)
	{
		//�P�x�ݒ�
		SetDrawBright(255, 255, 255);
		//�f�o�b�O�p�`��͈͕\��
		DrawBox(t->pos.x - LIGHT_MARGINE_X, t->pos.y - LIGHT_MARGINE_Y, t->pos.x + 200 - LIGHT_MARGINE_X, t->pos.y + 200 - LIGHT_MARGINE_Y,GetColor(255,255,255),false);
		//�`��͈͎w��
		SetDrawArea(t->pos.x - LIGHT_MARGINE_X, t->pos.y - LIGHT_MARGINE_Y, t->pos.x + 200 - LIGHT_MARGINE_X, t->pos.y + 200 - LIGHT_MARGINE_Y);
		//�w�i�摜�̕`��//��ŕς���
		static int a = LoadGraph("resource/image/haikei.png", true);
		DrawGraph(0, 0, a, true);
		//�����`��
		t->drawTorch();
		//�~�`�摜��`��
		DrawGraph(t->pos.x - LIGHT_MARGINE_X+sway.x, t->pos.y - LIGHT_MARGINE_Y+sway.y, torchLight::lightGh, true);
		//�P�x�Đݒ�
		SetDrawBright(122, 122, 122);
		//�`��͈͐ݒ����
		SetDrawAreaFull();
	}
}

void torchLight::updateLight()
{
	initLight();
	moveLight();
	drawLight();
}

void torchLight::swayLight()
{
	//���̗h��//�J�N�J�N�Ȃ�
	sway.x = rand() % 8 - 4;
	sway.y = rand() % 8 - 4;
}

//template<typename T>
//void setLight(T temp, light *lig)
//{
//	lig->pos = temp.pos;
//	lig->updateLight();
//}

torchLight* getLightPointertes(int num)
{
	switch (num)
	{
	case 1:
		return &light1;
		break;
	case 2:
		return &light2;
		break;
	}
}