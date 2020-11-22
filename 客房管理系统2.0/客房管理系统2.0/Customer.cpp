#include "Customer.h"
#include <iostream>
using namespace std;

char* Customer::get_name()
{
	return this->name;
}
char* Customer::get_id()
{
	return this->id;
}
int Customer::get_room_num()
{
	return this->room_num;
}
int Customer::get_days()
{
	return this->days;
}
time_t Customer::get_date()
{
	return this->date;
}
void Customer::set_name(char *name)
{
	strcpy(this->name,name);
}
void Customer::set_id(char *id)
{
	strcpy(this->id,id);
}
void Customer::set_days(int days)
{
	this->days=days;
}
void Customer::set_room_num(int room_num)
{
	this->room_num=room_num;
}
void Customer::set_date(time_t &date)
{
	this->date=date;
}
void Customer::info_set(char *name,char *id,int room_num,int days,time_t& date)
{
	strcpy(this->name,name);
	strcpy(this->id,id);
	this->room_num=room_num;
	this->days=days;
	this->date=date;
}
void Customer::info_print()
{
	cout<<"�˿�������"<<this->name<<endl;
	cout<<"���֤�ţ�"<<this->id<<endl;
	cout<<"�����  ��"<<this->room_num<<endl;
	cout<<"��ס���ڣ�"<<ctime(&(this->date));
	cout<<"��ס������"<<this->days<<endl;
}