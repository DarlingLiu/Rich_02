#include "command.h"
#include <ctime>
#include <cstdlib>

void Command::roll(Player player, Map map, PlayerAction pAction)
{
	srand((unsigned)time(NULL));
	int step = (1 + rand() % 6);
	pAction.resetPlayerPos(player, map, step);
}

 void Command::help()
{
	string help_string = "\n\
***********************************��ͼ����***********************************\n\
��ͼ��Χ����Ϊ��ߣ�������־����λ�ã�A-10��B-20��D-40��E-50,F-60\n\
0:�յ�; $:���; S:���0;  P:����49; \n\
***********************************�������***********************************\n\
*********************���������س�����ִ����������������������***********\n\
roll    ���������\n\
sell n  ���۵�ͼ��nλ���ϵķ���\n\
query   ��ѯ��ǰ����ʲ���Ϣ��\n\
help    ������\n\
exit    ����˳���Ϸ\n\
quit    ������Ϸ��\n\
************************����<help>������ٴ���ʾ�ð�����Ϣ********************\n";
	cout << help_string;
}

 bool Command::sell(Player player, Place place, int position)
 {
	 if (player.getPlayerName() != place.getPlaceOwnerName())
	 {
		 cout << "�˵ؿ鲻��������أ��벻Ҫ����Ц���𡣡�" << endl;
		 return false;
	 }
	
	 string choice;
	 //���ؿ������
	 int inCome = place.getPlacePrice() * place.getPlaceLevel() * 2;
	 cout << "�㽫���۸õؿ飬��������������棺" << inCome << endl;
	 cout << "y or n" << endl;
	 cin >> choice;
	 if (choice == "y")
	 {
		 player.setPlayerAssets(player.getPlayerAssets() + inCome);
		// place.setPlaceOwner(NULL);
	 }
	 return true;
 }

 //����
 void Command::query(Player player)
 {
	 cout << "����ʲ���Ϣ����";
 }

 //void Command::exit();