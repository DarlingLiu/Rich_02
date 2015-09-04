#ifndef _PLACE_H_
#define _PLACE_H_

#include "player.h"

class Place
{
private:
	char placeSign;	//�ؿ���ʾ�ַ�
	unsigned int placeType;	//�ؿ������
	int placePrice;	//�ؿ�ļ۸�

	Player placeOwner;	//�ؿ�ӵ����
	unsigned int x_place;	//�ؿ�x����
	unsigned int y_place;	//�ؿ�y����

public:

	/*
	*������ setPlaceType(Player player)
	*����˵����player:�ؿ�ӵ����
	*���ܣ����õؿ����ԣ�0���յأ�1��һ����2��������3������
	*����ֵ����
	*���ߣ�
	*/
	void setPlaceType(int type);
	//void setPlaceOwner(Player player);
	void setPlaceSign(char sign);
	/*
	*������ getPlaceType()
	*����˵������
	*���ܣ���ȡ�ؿ�����
	*����ֵ��int: tyoe
	*���ߣ�
	*/
	int getPlaceType();

	int getPlacePrice();

	unsigned int getPlaceX();
	unsigned int getPlaceY();
	char getPlaceSign();
	//string getPlaceOwnerName();
	//�ؿ��շ�
	void charge(int money);

};
#endif
