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
	cout<<"����ţ�"<<this->num<<"\t";
	cout<<"�۸�"<<this->price<<"/��"<<"\t";
	switch(this->type)
	{
	case 0:
		cout<<"���ͣ����ü�"<<"\t";
		break;
	case 1:
		cout<<"���ͣ���׼��"<<"\t";
		break;
	case 2:
		cout<<"���ͣ�������"<<"\t";
		break;
	}
	if(is_check_in)
	{
		cout<<"״̬������ס"<<endl;
		cout<<"��ס�˿�1��"<<this->customer1.get_name()<<"\t";
		cout<<"��ס�˿�2��"<<this->customer2.get_name()<<"\t";
		cout<<"��ס�˿�3��"<<this->customer3.get_name()<<"\t";
		cout<<"��ס������"<<this->days<<"\t";
		cout<<"��ס���ڣ�"<<ctime(&(this->date));
	}
	else
	{
		cout<<"״̬������"<<"\t";
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