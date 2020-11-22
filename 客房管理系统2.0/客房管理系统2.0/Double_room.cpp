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
		cout<<"��ס������"<<this->days<<"\t";
		cout<<"��ס���ڣ�"<<ctime(&(this->date));
	}
	else
	{
		cout<<"״̬������"<<"\t";
	}
	cout<<endl;
}
