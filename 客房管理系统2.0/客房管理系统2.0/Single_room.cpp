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
		cout<<"��ס�˿ͣ�"<<this->customer.get_name()<<"\t";
		cout<<"��ס������"<<this->days<<"\t";
		cout<<"��ס���ڣ�"<<ctime(&(this->date));
	}
	else
	{
		cout<<"״̬������"<<"\t";
	}
	cout<<endl;
}
