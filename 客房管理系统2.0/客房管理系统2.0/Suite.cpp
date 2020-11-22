#include "Suite.h"

void Suite::set_cutomer1(Customer& customer1)
{
	this->customer1=customer1;
}
void Suite::set_cutomer2(Customer& customer2)
{
	this->customer2=customer2;
}
void Suite::set_cutomer3(Customer& customer3)
{
	this->customer2=customer3;
}
Customer& Suite::get_customer1()
{
	return this->customer1;
}
Customer& Suite::get_customer2()
{
	return this->customer2;
}
Customer& Suite::get_customer3()
{
	return this->customer3;
}


void Suite::room_info_print()
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
		cout<<"入住顾客3："<<this->customer3.get_name()<<"\t";
		cout<<"入住天数："<<this->days<<"\t";
		cout<<"入住日期："<<ctime(&(this->date));
	}
	else
	{
		cout<<"状态：空闲"<<"\t";
	}
	cout<<endl;
}
//void Suite::room_info_set(int num,int price,bool is_check_in,int type)
//{
//	this->num=num;
//	this->price=price;
//	this->is_check_in=is_check_in;
//	this->type=type;
//}