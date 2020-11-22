#include "Double_room.h"

void Double_room::set_cutomer1(Customer& customer1)
{
	this->customer1=customer1;
}
void Double_room::set_cutomer2(Customer& customer2)
{
	this->customer2=customer2;
}
Customer& Double_room::get_customer1()
{
	return this->customer1;
}
Customer& Double_room::get_customer2()
{
	return this->customer2;
}
void Double_room::room_info_print()
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
		cout<<"入住顾客1："<<this->customer1.get_name()<<"\t";
		cout<<"入住顾客2："<<this->customer2.get_name()<<"\t";
		cout<<"入住天数："<<this->days<<"\t";
		cout<<"入住日期："<<ctime(&(this->date));
	}
	else
	{
		cout<<"状态：空闲"<<"\t";
	}
	cout<<endl;
}
