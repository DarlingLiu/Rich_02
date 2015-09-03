#ifndef _MAP_H_
#define _MAP_H_

#include "place.h"
//��ͼ���
const int WIDTH = 29;
const int HEIGHT = 8;
class Map
{
private:
	Place places[70];
	char mapGraph[HEIGHT][WIDTH];	//�洢��ͼ����

public:

	Map();
	~Map();

	/*
	*������initMap()
	*����˵������
	*���ܣ���ʼ����ͼ
	*����ֵ����
	*���ߣ�
	*/
	void initMap();


	/*
	*������init0()
	*����˵������
	*���ܣ�����ͼ�����еĵ㶼��ʼ��Ϊ�յ�
	*����ֵ����
	*���ߣ�
	*/
	void init0();


	/*
	*������setMapHereSign(int x, int y, char sign)
	*����˵����x,y����λ�ã�sign���õ�ͼ��ʾ����
	*���ܣ���������Ϊx,y�ĵ�ͼλ����ʾΪ�ƶ��ַ�
	*����ֵ����
	*���ߣ�
	*/
	void setMapHereSign(int x, int y, char sign);

	/*
	*������getMapHereSign(int x, in y)
	*����˵����x,y����λ��
	*���ܣ���ȡx,y�����µ��ַ�
	*����ֵ��char:��ʾ�ַ�
	*���ߣ�
	*/
	char getMapHereSign(int x, int y);

	/*
	*������ printMap()
	*����˵������
	*���ܣ���ӡ��ͼ
	*����ֵ����
	*���ߣ�
	*/
	void printMap();
};
#endif

