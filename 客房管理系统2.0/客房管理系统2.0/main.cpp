
#include "Menu.h"
#include "Manager.h"
#include "Customer.h"
#include <fstream>

int main()
{
	Menu myMenu;
	Manager manager;

	manager.init_room_info();
	while(1)
	{
		switch(myMenu.op_select())
		{
		case 1:
			manager.check_in();//������ס����
			system("pause");
			break;
		case 2:
			manager.check_out();//�����˷�����
			system("pause");
			break;
		case 3:
			manager.show_room_info();//��ʾ���з�����Ϣ
			system("pause");
			break;
		case 4:
			manager.show_uncheck_room_info();//��ʾδ��ס������Ϣ
			system("pause");
			break;
		case 5:
			manager.show_check_room_info();//��ʾ����ס������Ϣ
			system("pause");
			break;
		case 6:
			manager.show_customer_info();//��ʾ���п�����Ϣ
			system("pause");
			break;
		case 7:
			manager.search_room();//��ѯ������Ϣ
			system("pause");
			break;
		case 8:
			manager.search_customer();//��ѯ������Ϣ
			system("pause");
			break;
		case 9:
			manager.modify_room_info();//�޸ķ�����Ϣ
			system("pause");
			break;
		case 0:
			exit(0);
		}
	}
	return 0;
}