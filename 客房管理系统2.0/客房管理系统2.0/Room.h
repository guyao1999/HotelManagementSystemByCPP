#ifndef ROOM_H
#define ROOM_H
#include <iostream>
using namespace std;
#include "Customer.h"
enum{ECONOMY_ROOM,STANDARD_ROOM,DELUXE_ROOM};//房间的类型
#define UNCHECK false
#define CHECK true
class Room{    //父类
protected: 
	int num;              //房间编号
	int price;            //价格
	bool is_check_in;     //是否已有人入住
	int type;             //房间类型（经济间，标准间，豪华间)
	int days;             //入住天数
	time_t date;          //入住日期
public:
	int get_num();
	int get_price();
	bool get_is_check_in();
	int get_type();
	int get_days();
	time_t& get_date();

	void set_num(int num);
	void set_price(int price);
	void set_is_check_in(bool check);
	void set_type(int type);
	void set_days(int days);
	void set_date(time_t& date);

	void room_info_set(int num,int price,bool is_check_in,int type);  
};
#endif