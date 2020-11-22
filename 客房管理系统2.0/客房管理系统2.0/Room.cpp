#include "Room.h"
#include <fstream>

int Room::get_num()
{
	return this->num;
}
int Room::get_price()
{
	return this->price;
}
bool Room::get_is_check_in()
{
	return this->is_check_in;
}
int Room::get_days()
{
	return this->days;
}
void Room::set_num(int num)
{
	this->num=num;
}
void Room::set_price(int price)
{
	this->price=price;
}
void Room::set_type(int type)
{
	this->type=type;
}
void Room::set_days(int days)
{
	this->days=days;
}
void Room::set_is_check_in(bool check)
{
	this->is_check_in=check;
}
void Room::set_date(time_t& date)
{
	this->date=date;
}
time_t& Room::get_date()
{
	return this->date;
}
void Room::room_info_set(int num,int price,bool is_check_in,int type)
{
	this->num=num;
	this->price=price;
	this->is_check_in=is_check_in;
	this->type=type;
}