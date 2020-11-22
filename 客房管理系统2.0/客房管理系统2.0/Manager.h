#ifndef MANAGER_H
#define MANAGER_H
class Manager
{
public:
	void check_in();                  //客人入住办理
	void check_out();                 //客人退房办理
	void show_customer_info();        //展示所有顾客的信息
	void show_room_info();            //展示所有房间的信息
	void show_uncheck_room_info();    //展示空闲的房间的信息
	void show_check_room_info();      //展示所有已入住的房间的信息
	void search_room();               //输入房间号，查询房间号信息
	void search_customer();           //输入客人姓名，查询客人信息
	void modify_room_info();         //修改房间价格

	void del_customer_info(char* name);
	void show_single_room(bool check_in);  //显示单人间房间的信息
	void show_double_room(bool check_in);  //显示双人间房间的信息
	void show_suites(bool check_in);       //显示套间的房间信息
	void init_room_info();            //初始化(文件)数据库
};
#endif