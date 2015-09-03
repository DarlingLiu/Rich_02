#ifndef _PLAYER_H_
#define _PLAYER_H_

/**
*���������
*/

#include <iostream>
#include <string>
#include "place.h"
class Place;
using namespace std;


class Player {
private:
	string name;	//�������
	int id;		//���ID

	int assets;		//�ʲ�,Ĭ��10000����ʼΪ10000
					//	int fixedAssets;	//�̶��ʲ�
	int points;		//��ҿ��õ���

	unsigned int position;	//���λ��
	char playerSign;	//�����ʾ����
	unsigned short signColor;	//�����ʾ��ɫ

public:
	Player(string m_name, int m_id) :
		name(m_name), id(m_id) {
		assets = 0;
		points = 0;
		position = 0;
	}
	~Player() {}


	/*
	*������getPlayerPos()
	*����˵������
	*���ܣ����ص�ǰ��ҵ�λ��
	*����ֵ��int:position
	*���ߣ�
	*/
	int getPlayerPos();

	/*
	*������goStep(int step)
	*����˵����step��������ӻ�õĵ����������߲���
	*���ܣ���Ұ���������
	*����ֵ��int:��ǰλ��
	*���ߣ�
	*/
	int goStep(int step);

	/*
	*������resetPlayerPos(int step)
	*����˵����step��������ӻ�õĵ����������߲���
	*���ܣ����������û�λ��
	*����ֵ��int:���λ��
	*���ߣ�
	*/
	int resetPlayerPos(int step);

	/*
	*������buyLand(Place place)
	*����˵����place����Ҫ����ĵؿ�
	*���ܣ�����յ�
	*����ֵ����
	*���ߣ�
	*/
	void buyLand(Place place);

	/*
	*������ stayInDiffPlace(Place place, Player player)
	*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
	*���ܣ�ͣ���ڲ�ͬ�ؿ�֮�ϣ�ִ�й���֧��Ǯ�Ƶ���Ϊ
	*����ֵ����
	*���ߣ�
	*/
	void stayInDiffPlace(Place place, Player player);

	/*
	*������ payForStay(Place place, Player player)
	*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
	*���ܣ�ͣ�����˹���ؿ�֮�ϣ�ִ��֧��Ǯ�Ƶ���Ϊ
	*����ֵ����
	*���ߣ�
	*/
	void payForStay(Place place, Player player);

	/*
	*������ uppdatePlate(Place place)
	*����˵����place:�ؿ�
	*���ܣ������ؿ飬�������3��
	*����ֵ����
	*���ߣ�
	*/
	void uppdatePlate(Place place);
};

#endif