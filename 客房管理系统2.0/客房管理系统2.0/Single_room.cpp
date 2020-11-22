#include "Single_room.h"


void Single_room::set_cutomer(Customer& customer)
{
	this->customer=customer;
}
Customer& Single_room::get_customer()
{
	return this->customer;
}
void Single_room::room_info_print()
{
	cout<<"房间号："<<this->num<<"\t";
	cout<<"价格："<<this->price<<"/天"<<"\t";
	switch(this->type)
	{
	case 0:
		cout<<"类型：经济间"<<"\t";
		break;
	case 1:
		cout<<"类型：标准间"<<"\t";
		break;
	case 2:
		cout<<"类型：豪华间"<<"\t";
		break;
	}
	if(is_check_in)
	{
		cout<<"状态：已入住"<<endl;
		cout<<"入住顾客："<<this->customer.get_name()<<"\t";
		cout<<"入住天数："<<this->days<<"\t";
		cout<<"入住日期："<<ctime(&(this->date));
	}
	else
	{
		cout<<"状态：空闲"<<"\t";
	}
	cout<<endl;
}
