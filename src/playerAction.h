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
	*���ߣ�����
	*/
	int goStep(Player player, Map map, int step)
	{
		int currentPos = player.getPlayerPos();
		//���ѭ������
		currentPos = (currentPos + step) % (map.getPlaceNum());
		//�˴����õ�ͼ��ʾ����

		return currentPos;
	}

	/*
	*������resetPlayerPos(int step)
	*����˵����step��������ӻ�õĵ����������߲���
	*���ܣ����������û�λ��
	*����ֵ��int:���λ��
	*���ߣ�����
	*/
	void resetPlayerPos(Player player, Map map, int step)
	{
		//��ȡ�������֮���λ��
		int position = goStep(player, map, step);
		//�����������λ��
		player.setPlayerPos(position);
	}

	/*
	*������buyLand(Place place)
	*����˵����place����Ҫ����ĵؿ�
	*���ܣ�����յ�
	*����ֵ��bool
	*���ߣ�����
	*/
	bool buyLand(Player player, Place place)
	{
		//����ʲ����ڵؼۣ���������
		if (player.getPlayerAssets() > place.getPlacePrice())
		{
			cout << endl;
			cout << "�㽫���� " << place.getPlacePrice() << "��ȥ�õ�" << endl;
			cout << "���պøõص�ַ��(" << place.getPlaceX() << ", " << place.getPlaceY() << ")";

			int currentAssets = player.getPlayerAssets() - place.getPlacePrice();
			//������������ʲ�
			player.setPlayerAssets(currentAssets);
			//�յ�����ӵ����
			place.setPlaceOwner(&player);
			//�ؿ���������----------------����ע�����ó���
			place.setPlaceType(1);
			//�ؿ���ʾ�õؿ鼶�����
			place.setPlaceSign('0');
			place.setPlaceLevel(0);

			return true;
		}

		return false;
	}

	/*
	*������ payForStay(Place place, Player player)
	*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
	*���ܣ�ͣ�����˹���ؿ�֮�ϣ�ִ��֧��Ǯ�Ƶ���Ϊ
	*����ֵ��bool
	*���ߣ�����
	*/
	bool payForStay(Player player, Place place)
	{
		int placeLevel = 0;
		
		//ͣ�����˵ؿ����
		int stayCost = (place.getPlacePrice() * (place.getPlaceLevel() + 1)) / 2;

		if (player.getPlayerAssets() > stayCost)
		{
			cout << endl;
				cout << "����˵ؿ�ӵ���ߣ�" << place.getPlaceOwnerName() <<
				"�������·��ã�" << stayCost << endl;

			int currAssets = player.getPlayerAssets() - stayCost;
			//�������òƲ�
			player.setPlayerAssets(currAssets);
			//�ؿ��շ�
			place.charge(stayCost);
			return true;
		}
		return false;
	}


	/*
	*������ uppdatePlate(Place place)
	*����˵����place:�ؿ�
	*���ܣ������ؿ飬�������3��
	*����ֵ��bool
	*���ߣ�����
	*/
	bool uppdatePlate(Player player, Place place)
	{
		//�˴����Է���������ж�
		if (place.getPlaceLevel() > 3)
		{
			cout << "�˵ؿ��Ѵﵽ��߼��𣬲���������" << endl;
			return false;
		}
		if (player.getPlayerAssets() > place.getPlacePrice())
		{
			int currLevel = place.getPlaceLevel();
			cout << "��ǰ��ĵؿ鼶��Ϊ��" << currLevel << endl;
			cout << "�㽫���ѣ�" << place.getPlacePrice() << "���еؿ�����" << endl;

			//������������ʲ�
			int currAssets = player.getPlayerAssets() - place.getPlacePrice();
			player.setPlayerAssets(currAssets);

			//�ؿ�����
			currLevel += 1;
			place.setPlaceLevel(currLevel);

			return true;
		}
		return false;
	}

	/*
	*������addPoints(Player player, int points)
	*����˵����player,��ң�points�˴���صĵ���
	*���ܣ�ͣ����أ����ӵ���
	*����ֵ����
	*���ߣ�����
	*/
	void addPoints(Player player, int points)
	{
		int currPoints = player.getPlayerPoints();
		player.setPlayerPoints(currPoints + points);
	}

	/*
	*������ stayInDiffPlace(Player player, Place place)
	*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
	*���ܣ�ͣ���ڲ�ͬ�ؿ�֮�ϣ�ִ�й���֧��Ǯ�Ƶ���Ϊ
	*����ֵ����
	*���ߣ�����
	*/
	void stayInDiffPlace(Player player, Place place)
	{
		//��ȡ�ؿ����
		int placeType = place.getPlaceType();
		//��ȡ�ؿ鼶��
		int placeLevel = place.getPlaceLevel();

		char *choice;
		
		switch (placeType)
		{
		//�յ�
		case 0:
				buyLand(player, place);
				break;
		case 1:
			//���ڱ��˵ؿ�,����
			if (player.getPlayerName() != place.getPlaceOwnerName())
			{
				payForStay(player, place);
			}
			//�����Լ��ؿ飬��ѡ������
			else
			{
				cout << "�˴����㱾�˵ؿ飬��ѡ���Ƿ�����, y or n:" << endl;
				cin >> choice;
				if(strcmp(choice, "y") == 0)
				{ 
					uppdatePlate(player, place);
				}
		        
			}
			break;
		//���ڿ��
		case 2:
			addPoints(player, place.getPlacePrice());
			break;
		//���ڼ���
		case 3:
			break;
		default:
			break;
		}
	}

};

#endif