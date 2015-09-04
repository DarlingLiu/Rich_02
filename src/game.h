/**
*������Ϸ��
*/
#ifndef _GAME_H_
#define _GAME_H_

#include "map.h"
#include "player.h"
#include "command.h"
#include <vector>

const int MAX_PLAYER_NUM = 4;

class Game
{
private:
	Map *map;
	vector<Player> players;
	Command *command;
	int playerNum;

public:
	Game()
	{
		command = new Command();
		map = new Map();
		playerNum = 0;
	}

	~Game()
	{
		delete command;
		delete map;
		//playerNum = 0;
	}

	/*
	*������initPlayer()
	*����˵����
	*���ܣ���ʼ����ң�������ҵ��ʽ�λ��
	*����ֵ����
	*���ߣ�
	*/
	void initPlayer()
	{
		addPlayer(Player("wangfei", 1));
		addPlayer(Player("liuzi", 2));
		addPlayer(Player("xiaoqiang", 3));
		addPlayer(Player("leixiao", 4));
	}

	/*
	*������initGame()
	*����˵����
	*���ܣ���ʼ����ͼ�����
	*����ֵ����
	*���ߣ�
	*/
	void initGame()
	{
		initPlayer();
		map->initMap();
		map->printMap();
	}

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
	void addPlayer(Player player)
	{
		players.push_back(player);
		//�����Ŀ��1
		playerNum++;
	}

	/*
	*������deletePlayer()
	*����˵����
	*���ܣ�ɾ�����
	*����ֵ����
	*���ߣ�
	*/
	void deletePlayer(Player player)
	{
		vector<Player>::iterator it;
		for (it = players.begin(); it != players.end(); ++it)
		{
			if (player.getPlayerId() == it->getPlayerId())
			{
				players.erase(it);
				break;
			}
		}
	}

	//ִ����Ϸ
	void goGame()
	{
		initGame();
		while (playerNum > 1)
		{
			cout << "";
		}
	}
};

#endif