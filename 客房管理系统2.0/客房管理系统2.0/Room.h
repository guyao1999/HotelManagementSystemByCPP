#ifndef ROOM_H
#define ROOM_H
#include <iostream>
using namespace std;
#include "Customer.h"
enum{ECONOMY_ROOM,STANDARD_ROOM,DELUXE_ROOM};//���������
#define UNCHECK false
#define CHECK true
class Room{    //����
protected: 
	int num;              //������
	int price;            //�۸�
	bool is_check_in;     //�Ƿ���������ס
	int type;             //�������ͣ����ü䣬��׼�䣬������)
	int days;             //��ס����
	time_t date;          //��ס����
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