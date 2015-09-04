#ifndef _PLACE_H_
#define _PLACE_H_

#include "player.h"

class Place
{
private:
	char placeSign;	//�ؿ���ʾ�ַ�
	unsigned int level; //�ؿ鼶��
	unsigned int placeType;	//�ؿ������
	int placePrice;	//�ؿ�ļ۸�

	Player *placeOwner;	//�ؿ�ӵ����
	unsigned int x_place;	//�ؿ�x����
	unsigned int y_place;	//�ؿ�y����

public:
	Place() {}
	~Place() {}
	
	void setPlaceX(unsigned int x);
	void setPlaceY(unsigned int y);
	void setPlaceType(int type);
	void setPlaceOwner(Player* player);
	void setPlaceSign(char sign);
	void setPlaceLevel(int m_level);
	void setPlacePrice(int price);
	/*
	*������ getPlaceType()
	*����˵������
	*���ܣ���ȡ�ؿ�����
	*����ֵ��int: tyoe
	*���ߣ�
	*/
	int getPlaceType();

	int getPlacePrice();
	int getPlaceLevel();

	unsigned int getPlaceX();
	unsigned int getPlaceY();
	char getPlaceSign();
	string getPlaceOwnerName();

	/**
	*����:charge(int money)
	*����˵����int:�շ�Ǯ��
	*�������ܣ��ؿ��շ�
	*����ֵ����
	*���ߣ�����
	*/
	void charge(int money);

};
#endif
