#ifndef _PLAYER_ACTION_H_
#define _PLAYER_ACTION_H_

#include "player.h"
#include "place.h"
#include "map.h"

class PlayerAction
{

public:

	/*
	*������goStep(int step)
	*����˵����step��������ӻ�õĵ����������߲���
	*���ܣ���Ұ���������
	*����ֵ��int:��ǰλ��
	*���ߣ�
	*/
	int goStep(Player player, Map map, int step);

	/*
	*������resetPlayerPos(int step)
	*����˵����step��������ӻ�õĵ����������߲���
	*���ܣ����������û�λ��
	*����ֵ��int:���λ��
	*���ߣ�
	*/
	void resetPlayerPos(Player player, Map map, int step);

	/*
	*������buyLand(Place place)
	*����˵����place����Ҫ����ĵؿ�
	*���ܣ�����յ�
	*����ֵ����
	*���ߣ�
	*/
	bool buyLand(Player player, Place place);

	/*
	*������ payForStay(Place place, Player player)
	*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
	*���ܣ�ͣ�����˹���ؿ�֮�ϣ�ִ��֧��Ǯ�Ƶ���Ϊ
	*����ֵ����
	*���ߣ�
	*/
	bool payForStay(Place place, Player player);

	/*
	*������ stayInDiffPlace(Place place, Player player)
	*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
	*���ܣ�ͣ���ڲ�ͬ�ؿ�֮�ϣ�ִ�й���֧��Ǯ�Ƶ���Ϊ
	*����ֵ����
	*���ߣ�
	*/
	void stayInDiffPlace(Place place, Player player);



	/*
	*������ uppdatePlate(Place place)
	*����˵����place:�ؿ�
	*���ܣ������ؿ飬�������3��
	*����ֵ����
	*���ߣ�
	*/
	bool uppdatePlate(Player player, Place place);

};

#endif
