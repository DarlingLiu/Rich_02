#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "player.h"
#include "map.h"
#include "playerAction.h"

/**
*����������
*/

class Command
{
public:

	/*
	*������help()
	*����˵����
	*���ܣ�����˵�������ʹ��
	*����ֵ����
	*���ߣ�
	*/
	void help();

	/*
	*������quit()
	*����˵����
	*���ܣ���ֹ��Ϸ
	*����ֵ����
	*���ߣ�
	*/
	void quit();

	/*
	*������roll()
	*����˵����
	*���ܣ�������
	*����ֵ����
	*���ߣ�
	*/
	void roll(Player player, Map map, PlayerAction pAction);

	/*
	*������sell()
	*����˵����
	*���ܣ�������ҵķ���
	*����ֵ����
	*���ߣ�
	*/
	bool sell(Player player, Place place, int position);

	/*
	*������query()
	*����˵������
	*���ܣ���ѯ����ʲ���Ϣ
	*����ֵ����
	*���ߣ�
	*/
	void query(Player player);

	void exit(Player player, Map map);
	void quit();
};
#endif