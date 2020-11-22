
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
			manager.check_in();//客人入住办理
			system("pause");
			break;
		case 2:
			manager.check_out();//客人退房办理
			system("pause");
			break;
		case 3:
			manager.show_room_info();//显示所有房间信息
			system("pause");
			break;
		case 4:
			manager.show_uncheck_room_info();//显示未入住房间信息
			system("pause");
			break;
		case 5:
			manager.show_check_room_info();//显示已入住房间信息
			system("pause");
			break;
		case 6:
			manager.show_customer_info();//显示所有客人信息
			system("pause");
			break;
		case 7:
			manager.search_room();//查询房间信息
			system("pause");
			break;
		case 8:
			manager.search_customer();//查询客人信息
			system("pause");
			break;
		case 9:
			manager.modify_room_info();//修改房间信息
			system("pause");
			break;
		case 0:
			exit(0);
		}
	}
	return 0;
}