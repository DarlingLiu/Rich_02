/**
*������Ϸ��
*/
#ifndef _GAME_H_
#define _GAME_H_

#include "map.h"
#include "player.h"
#include "command.h"

class Game
{
private:
	Map map;
	Player *player;
	Command command;
	int playerNum;

public:
	Game() {}
	~Game() {}

	/*
	*������initPlayer()
	*����˵����
	*���ܣ���ʼ����ң�������ҵ��ʽ�λ��
	*����ֵ����
	*���ߣ�
	*/
	void initPlayer();

	/*
	*������initGame()
	*����˵����
	*���ܣ���ʼ����ͼ�����
	*����ֵ����
	*���ߣ�
	*/
	void initGame();

	/*
	*������destroyPlayer()
	*����˵����
	*���ܣ����ٵ�ͼ
	*����ֵ����
	*���ߣ�
	*/
	void destroyGame();

	/*
	*������quitGame()
	*����˵����
	*���ܣ���ֹ��Ϸ
	*����ֵ����
	*���ߣ�
	*/
	void quitGame();

	/*
	*������addPlayer()
	*����˵����
	*���ܣ�������
	*����ֵ����
	*���ߣ�
	*/
	void addPlayer();

	/*
	*������deletePlayer()
	*����˵����
	*���ܣ�ɾ�����
	*����ֵ����
	*���ߣ�
	*/
	void deletePlayer();
};

#endif