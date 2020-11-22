#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <ctime>
class Customer
{
private:
	char name[10];
	char id[19];     //身份证号
	int room_num;    //入住房间编号
	int days;        //入住天数
	time_t date;     //入住日期

public:
	char* get_name();
	char* get_id();
	int get_room_num();
	int get_days();
	time_t get_date();

	void set_name(char* name);
	void set_id(char* id);
	void set_room_num(int room_num);
	void set_days(int days);
	void set_date(time_t &date);

	void info_print();
	void info_set(char *name,char *id,int room_num,int days,time_t& date);
};
#endif
