#ifndef _PLAYER_H_
#define _PLAYER_H_

/**
*���������
*/

#include <iostream>
#include <string>

using namespace std;

class Player {
private:
	string playerName;	//�������
	int playerId;		//���ID

	int assets;		//�ʲ�,Ĭ��10000����ʼΪ10000
					//	int fixedAssets;	//�̶��ʲ�
	int points;		//��ҿ��õ���

	unsigned int position;	//���λ��
	char playerSign;	//�����ʾ����
	unsigned short signColor;	//�����ʾ��ɫ

public:
	Player(string m_name, int m_id) :
		playerName(m_name), playerId(m_id) {
		assets = 0;
		points = 0;
		position = 0;
	}
	~Player() {}

	int getPlayerPos()
	{
		return position;
	}

	int getPlayerAssets()
	{
		return assets;
	}

	char getPlayerSign()
	{
		return playerSign;
	}
	unsigned short getPlayerSignColor()
	{
		return signColor;
	}

	int getPlayerId()
	{
		return playerId;
	}

	string getPlayerName()
	{
		return playerName;
	}

	int getPlayerPoints()
	{
		return points;
	}

	void setPlayerAssets(int m_assets)
	{
		assets = m_assets;
	}

	void setPlayerSign(char sign)
	{
		playerSign = sign;
	}

	void setPlayerName(string name)
	{
		playerName = name;
	}

	void setPlayerPos(int pos)
	{
		position = pos;
	}

	void setPlayerPoints(int po)
	{
		points = po;
	}

};

#endif