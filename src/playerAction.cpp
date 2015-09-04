#include "playerAction.h"


/*
*������goStep(int step)
*����˵����step��������ӻ�õĵ����������߲���
*���ܣ���Ұ���������
*����ֵ��int:��ǰλ��
*���ߣ�
*/
int PlayerAction::goStep(Player player, Map map, int step)
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
*���ߣ�
*/
void PlayerAction::resetPlayerPos(Player player, Map map, int step)
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
*����ֵ����
*���ߣ�
*/
bool PlayerAction::buyLand(Player player, Place place)
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
//		place.setPlaceOwner(player);
		//�ؿ���������----------------����ע�����ó���
		place.setPlaceType(1);
		//�ؿ���ʾ����ҷ���
		place.setPlaceSign(player.getPlayerSign());

		return true;
	}

	return false;
}

/*
*������ payForStay(Place place, Player player)
*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
*���ܣ�ͣ�����˹���ؿ�֮�ϣ�ִ��֧��Ǯ�Ƶ���Ϊ
*����ֵ����
*���ߣ�����
*/
bool PlayerAction::payForStay(Place place, Player player) 
{
	//ͣ�����˵ؿ����
	int stayCost = (place.getPlacePrice() * place.getPlaceType()) / 2;

	if (player.getPlayerAssets() > stayCost)
	{
		cout << endl;
	//	cout << "����˵ؿ�ӵ���ߣ�" << place.getPlaceOwnerName() <<
		//	"�������·��ã�" << stayCost << endl;

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
*����ֵ����
*���ߣ�����
*/
bool PlayerAction::uppdatePlate(Player player, Place place)
{
	//�˴����Է���������ж�
	if (place.getPlaceType() > 3) return false;
	if (player.getPlayerAssets() > place.getPlacePrice())
	{
		int currType = place.getPlaceType();
		cout << "��ǰ��ĵؿ鼶��Ϊ��" << currType << endl;
		cout << "�㽫���ѣ�" << place.getPlacePrice() << "���еؿ�����" << endl;

		//������������ʲ�
		int currAssets = player.getPlayerAssets() - place.getPlacePrice();
		player.setPlayerAssets(currAssets);

		//�ؿ�����
		currType += 1;
		place.setPlaceType(currType);

		return true;
	}
	return false;
}


/*
*������ stayInDiffPlace(Place place, Player player)
*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
*���ܣ�ͣ���ڲ�ͬ�ؿ�֮�ϣ�ִ�й���֧��Ǯ�Ƶ���Ϊ
*����ֵ����
*���ߣ�
*/
void stayInDiffPlace(Place place, Player player);