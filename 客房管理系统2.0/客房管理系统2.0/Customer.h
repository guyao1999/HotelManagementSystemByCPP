#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <ctime>
class Customer
{
private:
	char name[10];
	char id[19];     //���֤��
	int room_num;    //��ס������
	int days;        //��ס����
	time_t date;     //��ס����

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
