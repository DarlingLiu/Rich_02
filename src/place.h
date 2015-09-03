#ifndef _PLACE_H_
#define _PLACE_H_

#include "player.h"
class Place 
{
private:
	char sign;	//�ؿ���ʾ�ַ�
	unsigned int type;	//�ؿ������
	int price;	//�ؿ�ļ۸�
	Player owner;	//�ؿ�ӵ����
	unsigned int x;	//�ؿ�x����
	unsigned int y;	//�ؿ�y����

public:

	/*
	*������ setPlaceType(Player player)
	*����˵����player:�ؿ�ӵ����
	*���ܣ����õؿ����ԣ�0���յأ�1��һ����2��������3������
	*����ֵ����
	*���ߣ�
	*/
	void setPlaceType(Player player);

	/*
	*������ getPlaceType()
	*����˵������
	*���ܣ���ȡ�ؿ�����
	*����ֵ��int: tyoe
	*���ߣ�
	*/
	int getPlaceType();
};
#endif

