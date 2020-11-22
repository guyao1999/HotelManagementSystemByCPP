#include "Manager.h"
#include "Customer.h"
#include "Room.h"
#include "Single_room.h"
#include "Double_room.h"
#include "Suite.h"
#include <fstream>
#include <iostream>
using namespace std;


/*������ס����*/
void Manager::check_in()
{  
    cout<<"ѡ�񷿼�����  1�����˼�   2��˫�˼�  3���׼�"<<endl;
	int select;
	do{
		cout<<"ѡ��";
		cin>>select;
	}while(select<1 || select>3);
	int room_num;
	char name[10];
	char id[19];
	int days;
	time_t date;
	bool search=false;
	streampos flag;  //�������λ��
	switch(select)
	{
	case 1:
		{
			cout<<"----------------------��ǰ���еĵ��˼�����------------------"<<endl;
			this->show_single_room(UNCHECK);                  //��ʾ���еĵ��˼���Ϣ
			cout<<"------------------------------------------------------------"<<endl;
			
			fstream file1("Single_room_info.txt",ios::in|ios::out);
			if(!file1)
			{
				cout<<"���˼����ݿ����ʧ��!";
				exit(0);
			}
			Single_room room;
			do{
				cout<<"���뷿��ţ�";
				cin>>room_num;
				file1.clear();           //���ļ���״̬��ʼ��
				file1.seekg(0L,ios::beg);//��ת���ļ���ͷ
			
				while(!file1.eof())
				{        
					flag=file1.tellg();                        //�õ��ļ�λ��ָ�룬�������ݵ��޸�
					file1.read((char*)&room,sizeof(room));      
					if(room.get_num()==room_num && room.get_is_check_in()==false) //���ҵ��÷����
					{
						search=true;
						break;
					}
				}

				if(!search)
				{
					cout<<"����Ŵ����÷������й˿���ס!��������뷿���"<<endl;
				}
			}while(!search);//��ÿ������ķ���Ž��м�飬���Ƿ���ںͿ���

			cout<<"����˿�������";
			cin>>name;
			cout<<"�������֤�ţ�";
			cin>>id;
			cout<<"������ס������";
			cin>>days;

			date=time(0);

			Customer customer;
			customer.info_set(name,id,room_num,days,date);
			
			room.set_days(days);
			room.set_is_check_in(true);
			room.set_cutomer(customer);
			room.set_date(date);

			fstream file2("Customer_info.txt",ios::in|ios::out|ios::app);
			if(!file2)
			{
				cout<<"������Ϣ���ݿ����ʧ��";
				exit(0);
			}
			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));          //����д�뷿����Ϣ
			file2.write((char*)&customer,sizeof(customer));  //д�������Ϣ

			file1.close();
			file2.close();
			cout<<"��ס����ɹ���"<<endl;
			break;
		}
	case 2: 
		{	
			cout<<"----------------------��ǰ���е�˫�˼�����------------------"<<endl;
			this->show_double_room(UNCHECK);
			cout<<"------------------------------------------------------------"<<endl;
			fstream file1("Double_room_info.txt",ios::in|ios::out);
			if(!file1)
			{
				cout<<"˫�˼����ݿ����ʧ��!";
				exit(0);
			}
			Double_room room;
			do{
				cout<<"���뷿��ţ�";
				cin>>room_num;
				file1.clear();           //���ļ���״̬��ʼ��
				file1.seekg(0L,ios::beg);//��ת���ļ���ͷ
			
				while(!file1.eof())
				{        
					flag=file1.tellg();                        //�õ��ļ�λ��ָ�룬�������ݵ��޸�
					file1.read((char*)&room,sizeof(room));      
					if(room.get_num()==room_num && room.get_is_check_in()==false) //���ҵ��÷����
					{
						search=true;
						break;
					}
				}
				if(!search)
				{
					cout<<"����Ŵ����÷������й˿���ס!��������뷿���"<<endl;
				}
			}while(!search);     //��ÿ������ķ���Ž��м�飬���Ƿ���ڻ����

			cout<<"����˿�1������";
			cin>>name;
			cout<<"����˿�1���֤�ţ�";
			cin>>id;
			cout<<"������ס������";
			cin>>days;
			date=time(0);
			Customer customer1;
			customer1.info_set(name,id,room_num,days,date);//�˿�1��Ϣ����

			cout<<"����˿�2������";
			cin>>name;
			cout<<"����˿�2���֤�ţ�";
			cin>>id;
			Customer customer2;
			customer2.info_set(name,id,room_num,days,date);//�˿�2��Ϣ����

		
			room.set_days(days);
			room.set_is_check_in(true);
			room.set_cutomer1(customer1);
			room.set_cutomer2(customer2);
			room.set_date(date);//������Ϣ����

			fstream file2("Customer_info.txt",ios::in|ios::out|ios::app);
			if(!file2)
			{
				cout<<"������Ϣ���ݿ����ʧ��";
				exit(0);
			}
			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));          //����д�뷿����Ϣ
			file2.write((char*)&customer1,sizeof(customer1));//д��˿�1��Ϣ
			file2.write((char*)&customer2,sizeof(customer2));//д��˿�2��Ϣ

			file1.close();
			file2.close();
			cout<<"��ס����ɹ���"<<endl;
			break;
		}
	case 3: 
		{
			cout<<"----------------------��ǰ���е��׼�����------------------"<<endl;
			this->show_suites(UNCHECK);
			cout<<"------------------------------------------------------------"<<endl;
			fstream file1("Suites.txt",ios::in|ios::out);
			if(!file1)
			{
				cout<<"�׼����ݿ����ʧ��!";
				exit(0);
			}
			Suite room;
			do{
				cout<<"���뷿��ţ�";
				cin>>room_num;
				file1.clear();           //���ļ���״̬��ʼ��
				file1.seekg(0L,ios::beg);//��ת���ļ���ͷ
			
				while(!file1.eof())
				{        
					flag=file1.tellg();                        //�õ��ļ�λ��ָ�룬�������ݵ��޸�
					file1.read((char*)&room,sizeof(room));      
					if(room.get_num()==room_num && room.get_is_check_in()==false) //���ҵ��÷����
					{
						search=true;
						break;
					}
				}

				if(!search)
				{
					cout<<"����Ŵ����÷������й˿���ס!��������뷿���"<<endl;
				}
			}while(!search);//��ÿ������ķ���Ž��м�飬���Ƿ���ںͿ���
			cout<<"����˿�1������";
			cin>>name;
			cout<<"����˿�1���֤�ţ�";
			cin>>id;
			cout<<"������ס������";
			cin>>days;
			date=time(0);
			Customer customer1;
			customer1.info_set(name,id,room_num,days,date);//�˿�1��Ϣ����

			cout<<"����˿�2������";
			cin>>name;
			cout<<"����˿�2���֤�ţ�";
			cin>>id;
			Customer customer2;
			customer2.info_set(name,id,room_num,days,date);//�˿�2��Ϣ����

			cout<<"����˿�3������";
			cin>>name;
			cout<<"����˿�3���֤�ţ�";
			cin>>id;
			Customer customer3;
			customer3.info_set(name,id,room_num,days,date);//�˿�3��Ϣ����

			room.set_days(days);
			room.set_is_check_in(true);
			room.set_cutomer1(customer1);
			room.set_cutomer1(customer2);
			room.set_cutomer3(customer3);
			room.set_date(date);//������Ϣ����
		

			fstream file2("Customer_info.txt",ios::in|ios::out|ios::app);
			if(!file2)
			{
				cout<<"������Ϣ���ݿ����ʧ��";
				exit(0);
			}
			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));          //����д�뷿����Ϣ
			file2.write((char*)&customer1,sizeof(customer1));//д�����1��Ϣ
			file2.write((char*)&customer2,sizeof(customer2));//д�����2��Ϣ
			file2.write((char*)&customer3,sizeof(customer3));//д�����3��Ϣ

			file1.close();
			file2.close();
			cout<<"��ס����ɹ���"<<endl;
			break;
		}
	}
}
/*�����˷�����*/
void Manager::check_out()
{
	fstream file1("Single_room_info.txt",ios::in|ios::out);
	if(!file1)
	{
		cout<<"���˼����ݿ����ʧ��";
		exit(0);
	}//�򿪵��˼����ݿ�

	fstream file2("Double_room_info.txt",ios::in|ios::out);
	if(!file2)
	{
		cout<<"˫�˼����ݿ����ʧ��";
		exit(0);
	}//��˫�˼����ݿ�

	fstream file3("Suites.txt",ios::in|ios::out);
	if(!file3)
	{
		cout<<"˫�˼����ݿ����ʧ��";
		exit(0);
	}//���׼����ݿ�

	int room_num;
	cout<<"���뷿��ţ�";
	cin>>room_num;
	bool search=false;
	streampos flag;
	while(!file1.eof())
	{
		Single_room room;
		flag=file1.tellg();
		file1.read((char*)&room,sizeof(room));
		if(room.get_num()==room_num && room.get_is_check_in()==true)
		{
			search=true;
			cout<<"---------------------������Ϣ------------------------"<<endl;
			room.room_info_print();
			cout<<"�踶���ã�"<<room.get_price() *room.get_days()<<"Ԫ"<<endl;

			room.set_is_check_in(false);
			room.set_days(0);

			del_customer_info(room.get_customer().get_name());
			//�˿���Ϣɾ��

			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));
			cout<<"�˷�����ɹ�!"<<endl;
			break;
		}
	}
	while(!file2.eof())
	{
		Double_room room;
		flag=file1.tellg();
		file2.read((char*)&room,sizeof(room));
		if(room.get_num()==room_num && room.get_is_check_in()==true)
		{
			search=true;
			cout<<"---------------------������Ϣ------------------------"<<endl;
			room.room_info_print();
			cout<<"�踶���ã�"<<room.get_price() *room.get_days()<<"Ԫ"<<endl;

			room.set_is_check_in(false);
			room.set_days(0);

			del_customer_info(room.get_customer1().get_name());
			del_customer_info(room.get_customer2().get_name());
			//�˿���Ϣɾ��



			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));
			cout<<"�˷�����ɹ�!"<<endl;
			break;
		}
	}
	while(!file3.eof())
	{
		Suite room;
		flag=file1.tellg();
		file3.read((char*)&room,sizeof(room));
		if(room.get_num()==room_num && room.get_is_check_in()==true)
		{
			search=true;
			cout<<"---------------------������Ϣ------------------------"<<endl;
			room.room_info_print();
			cout<<"�踶���ã�"<<room.get_price() *room.get_days()<<"Ԫ"<<endl;

			room.set_is_check_in(false);
			room.set_days(0);

			del_customer_info(room.get_customer1().get_name());
			del_customer_info(room.get_customer2().get_name());
			del_customer_info(room.get_customer3().get_name());
			//�˿���Ϣɾ��

			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));
			cout<<"�˷�����ɹ�!"<<endl;
			break;
		}
	}
	if(search==false)
	{
		cout<<"����Ŵ����÷���û������ס!"<<endl;
	}
	file1.close();
	file2.close();
	file3.close();
}

/*��ʾ���з�����Ϣ*/
void Manager::show_room_info()
{
	cout<<endl<<"-----------------------------���˼�------------------------"<<endl;
	this->show_single_room(false);
	this->show_single_room(true);

	cout<<endl<<"-----------------------------˫�˼�-------------------------"<<endl;
	this->show_double_room(false);
	this->show_double_room(true);

	cout<<endl<<"-----------------------------�׼�---------------------------"<<endl;
	this->show_suites(false);
	this->show_suites(true);
}	

/*��ʾ����δ��ס������Ϣ*/
void Manager::show_uncheck_room_info()
{
	cout<<"-------------------------------���з����ѯ-----------------------------------"<<endl;
    cout<<"ѡ��Ҫ��ѯ�ķ������ͣ�    1�����˼�   2��˫�˼�  3���׼�   4���������ͷ���"<<endl;
	int select;
	do
	{
		cout<<"ѡ��";
		cin>>select;
	}while(select<1 || select>4);
	switch(select)
	{
	case 1:
		{
			this->show_single_room(false);
			break;
		}
	case 2:
		{
			this->show_double_room(false);
		    break;
		}
	case 3:
		{
			this->show_suites(false);
			break;
		}
	case 4:
		{

			cout<<"----------------------------���˼�-------------------------"<<endl;
			this->show_single_room(false);
			cout<<"----------------------------˫�˼�-------------------------"<<endl;
			this->show_double_room(false);
			cout<<"----------------------------�׼�---------------------------"<<endl;
			this->show_suites(false);
			break;
		}
	}
}

/*��ʾ��������ס������Ϣ*/
void Manager::show_check_room_info()//չʾ��������ס�ķ���
{
	cout<<"-------------------------------����ס�����ѯ-----------------------------------"<<endl;
	cout<<"ѡ��Ҫ��ѯ��ʣ��ķ������ͣ�    1�����˼�   2��˫�˼�  3���׼�  4���������ͷ���"<<endl;
	int select;
	do
	{
		cout<<"ѡ��";
		cin>>select;
	}while(select<1 || select>4);
	switch(select)
	{
	case 1:
		{
			cout<<"----------------------------���˼�---------------------------------"<<endl;
			this->show_single_room(true);
			break;
		}
	case 2:
		{
			cout<<"----------------------------˫�˼�---------------------------------"<<endl;
			this->show_double_room(true);
		    break;
		}
	case 3:
		{
			this->show_suites(true);
			break;
		}
	case 4:
		{
			cout<<"----------------------------���˼�---------------------------------"<<endl;
			this->show_single_room(true);
			cout<<"----------------------------˫�˼�---------------------------------"<<endl;
			this->show_double_room(true);
			cout<<"----------------------------�׼�-----------------------------------"<<endl;
			this->show_suites(true);
			break;
		}
	}
}

/*��ʾ���п�����Ϣ*/
void Manager::show_customer_info()
{
	int num=0;
	cout<<"--------------------������ס������Ϣ����--------------------"<<endl;
	fstream file("Customer_info.txt",ios::in|ios::out);
	if(!file)
	{
		cout<<"�û���Ϣ���ݿ����ʧ��";
		exit(0);
	}
	Customer customer;
	file.clear();
	file.seekg(0,ios::beg);

	file.read((char*)&customer,sizeof(customer));
	while(!file.eof())
	{
		customer.info_print();
		cout<<endl;
		file.read((char*)&customer,sizeof(customer));
		num++;
	}
	if(num==0)
	{
		cout<<"����û�п�����ס"<<endl;
	}
	cout<<"---------------------------------------------------------------"<<endl;
	file.close();
}

/*���뷿��Ż�۸񣬲�ѯ���ϵķ�����Ϣ*/
void Manager::search_room()
{
	int select;	
	do
	{
		cout<<"ѡ���ѯģʽ  1��������Ų�ѯ   2�����۸������ѯ"<<endl;
		cout<<"ѡ��";
		cin>>select;

	}while(select<1 || select>2);

	fstream file1("Single_room_info.txt",ios::in|ios::out);
	if(!file1)
	{
		cout<<"���˼����ݿ����ʧ��";
		exit(0);
	}//�򿪵��˼����ݿ�

	fstream file2("Double_room_info.txt",ios::in|ios::out);
	if(!file2)
	{
		cout<<"˫�˼����ݿ����ʧ��";
		exit(0);
	}//��˫�˼����ݿ�

	fstream file3("Suites.txt",ios::in|ios::out);
	if(!file3)
	{
		cout<<"˫�˼����ݿ����ʧ��";
		exit(0);
	}//���׼����ݿ�

	switch(select)
	{
	case 1://������Ų�ѯ
		{
			int room_num;
			cout<<"���뷿��ţ�";
			cin>>room_num;
			while(!file1.eof())
			{
				Single_room room;
				file1.read((char*)&room,sizeof(room));
				if(room.get_num()==room_num)
				{
					room.room_info_print();
					break;
				}
			}
			while(!file2.eof())
			{
				Double_room room;
				file2.read((char*)&room,sizeof(room));
				if(room.get_num()==room_num)
				{
					room.room_info_print();
					break;
				}
			}
			while(!file3.eof())
			{
				Suite room;
				file3.read((char*)&room,sizeof(room));
				if(room.get_num()==room_num)
				{
					room.room_info_print();
					break;
				}
			}
			break;
		}

	case 2://���۸������ѯ
		{
			int low_price;
			int heigh_price;
			cout<<"����۸����䣺"<<endl;
			cout<<"��ͼۣ�";
			cin>>low_price;
			cout<<"��߼ۣ�";
			cin>>heigh_price;

			while(!file1.eof())
			{
				Single_room room;
				file1.read((char*)&room,sizeof(room));
				if(low_price<room.get_price() && room.get_price()<heigh_price)
				{
					room.room_info_print();
				}
			}

			while(!file2.eof())
			{
				Double_room room;
				file2.read((char*)&room,sizeof(room));
				if(low_price<room.get_price() && room.get_price()<heigh_price)
				{
					room.room_info_print();
				}
			}
			while(!file3.eof())
			{
				Suite room;
				file3.read((char*)&room,sizeof(room));
				if(low_price<room.get_price() && room.get_price()<heigh_price)
				{
					room.room_info_print();
				}
			}
			break;
		}
	}
	file1.close();
	file2.close();
	file3.close();
}

/* ����������������֤�ţ���ѯ������Ϣ*/
void Manager::search_customer()
{
	int select;	
	char name[10];
	char id[19];
	do
	{
		cout<<"ѡ���ѯģʽ     1����������ѯ   2�������֤�Ų�ѯ"<<endl;
		cout<<"ѡ��";
		cin>>select;

	}while(select<1 || select>2);
	if(select==1)
	{
		cout<<"�������������";
	cin>>name;

	}
	else
	{
		cout<<"�������֤�ţ�";
		cin>>id;
	}
	fstream file("Customer_info.txt",ios::in|ios::out);
	if(!file)
	{
		cout<<"������Ϣ���ݿ����ʧ��"<<endl;
		exit(0);
	}
	bool flag=false;//����Ƿ��ѯ��
	file.clear();
	file.seekg(0,ios::beg);
	while(!file.eof())
	{
		Customer customer;
		file.read((char *)&customer,sizeof(customer));
		if(strcmp(name,customer.get_name())==0  || strcmp(id,customer.get_id())==0)
		{
			customer.info_print();
			flag=true;
			break;
		}
	}
	if(!flag)
	{
		cout<<"û�в�ѯ���ÿ��˵���Ϣ��"<<endl;
	}
	file.close();
}

void Manager::del_customer_info(char *name)
{
	fstream file1("Customer_info.txt",ios::in|ios::out);
	if(!file1)
	{
		cout<<"������Ϣ���ݿ����ʧ��";
		exit(0);
	}
	fstream file2("temp.txt",ios::out);//�ļ������ڻ��Զ�����
	if(!file2)
	{
		cout<<"��ʱ�ļ�����ʧ�ܣ�";
		exit(0);
	}

	file1.clear();
	file1.seekg(0,ios::beg);
	Customer customer;
	file1.read((char*)&customer,sizeof(customer));
	while(!file1.eof())
	{
		if(strcmp(customer.get_name(),name)!=0)
		{
			file2.write((char*)&customer,sizeof(customer));
		}
		file1.read((char*)&customer,sizeof(customer));
	}
	file1.close();
	file2.close();
	remove("Customer_info.txt");
	rename("temp.txt","Customer_info.txt");

}
/*�޸ķ�����Ϣ*/
void Manager::modify_room_info()
{
	int room_num;
	cout<<"���뷿��Ŷ�����Ϣ�����޸ģ�";
	cin>>room_num;

	fstream file1("Single_room_info.txt",ios::in|ios::out);
	if(!file1) 
	{
		cout<<"���˼����ݿ����ʧ��";
		exit(0);
	}//�򿪵��˼����ݿ�

	fstream file2("Double_room_info.txt",ios::in|ios::out);
	if(!file2)
	{
		cout<<"˫�˼����ݿ����ʧ��";
		exit(0);
	}//��˫�˼����ݿ�

	fstream file3("Suites.txt",ios::in|ios::out);
	if(!file3)
	{
		cout<<"�׼����ݿ����ʧ��";
		exit(0);
	}//���׼����ݿ�

	/*fstream file4("Customer_info.txt",ios::in|ios::out);
	if(!file4)
	{
		cout<<"�˿���Ϣ���ݿ����ʧ��";
		exit(0);
	}*/

	streampos flag1,flag2,flag3;   //���ڱ�������ļ��ж������ϵķ�����Ϣ��λ��
	int room_type=0;               //���ڱ������ķ��������ʲô���͵ķ��䣬
	Single_room room1;
	Double_room room2;
	Suite room3;
	while(!file1.eof())
	{
		flag1=file1.tellg();
		file1.read((char*)&room1,sizeof(room1));
		if(room1.get_num()==room_num && room1.get_is_check_in()==false)
		{
			room_type=1;
			cout<<"--------------------�÷�����Ϣ--------------------"<<endl;
			room1.room_info_print();
			cout<<"----------------------------------------------------"<<endl;
			break;
		}
	}
	while(!file2.eof())
	{
		flag2=file2.tellg();
		file2.read((char*)&room2,sizeof(room2));
		if(room2.get_num()==room_num  && room1.get_is_check_in()==false)
		{
			room_type=2;
			cout<<"--------------------�÷�����Ϣ--------------------"<<endl;
			room2.room_info_print();
			cout<<"----------------------------------------------------"<<endl;
			break;
		}
	}
	while(!file3.eof())
	{
		flag3=file2.tellg();
		file3.read((char*)&room3,sizeof(room3));
		if(room3.get_num()==room_num  && room1.get_is_check_in()==false)
		{
			room_type=3;
			cout<<"--------------------�÷�����Ϣ--------------------"<<endl;
			room3.room_info_print();
			cout<<"----------------------------------------------------"<<endl;
			break;
		}
	}
	if(room_type==0)
	{
		cout<<"û�в��ҵ��÷������Ϣ����˶������Ƿ���ȷ"<<endl;
		return;
	}

	cout<<"ѡ��Ҫ�޸ĵķ�����Ϣ.   1�������    2������۸�    3����������  "<<endl;
	
	int select;             //Ҫ�޸ĵ�����
	int num;                //�޸ĺ�ķ����
	int type;               //�޸ĺ������
	int price;              //�޸ĺ�ļ۸�
	do
	{
		cout<<"ѡ��";
		cin>>select;
	}while(select<1 || select>3);
	switch(select)
	{
	case 1:
		{
			cout<<"�����޸ĺ�ķ���ţ�";
			cin>>num;
			if(room_type==1)
			{
				room1.set_num(num);
				file1.seekp(flag1,ios::beg);
				file1.write((char*)&room1,sizeof(room1));
			}
			if(room_type==2)
			{
				room2.set_num(num);
				file2.seekp(flag2,ios::beg);
				file2.write((char*)&room2,sizeof(room2));
			}
			if(room_type==3)
			{
				room3.set_num(num);
				file3.seekp(flag3,ios::beg);
				file3.write((char*)&room3,sizeof(room3));
			}
			cout<<"�޸ĳɹ���"<<endl;
		    break;
		}
	case 2:
		{
			cout<<"�����޸ĺ�ķ���۸�";
			cin>>price;
			if(room_type==1)
			{
				room1.set_price(price);
				file1.seekp(flag1,ios::beg);
				file1.write((char*)&room1,sizeof(room1));
			}
			if(room_type==2)
			{
				room2.set_price(price);
				file2.seekp(flag2,ios::beg);
				file2.write((char*)&room2,sizeof(room2));
			}
			if(room_type==3)
			{
				room3.set_price(price);
				file3.seekp(flag3,ios::beg);
				file3.write((char*)&room3,sizeof(room3));
			}
		    break;
		}
	case 3:
		{
			cout<<"�����޸ĺ�ķ������ͣ�  0�����ü�  1����׼��   2��������" ;
			cin>>type;
			if(room_type==1 && type>=0 && type<=2)
			{
				room1.set_type(type);
				file1.seekp(flag1,ios::beg);
				file1.write((char*)&room1,sizeof(room1));
			}
			if(room_type==2 && type>=0 && type<=2)
			{
				room2.set_type(type);
				file2.seekp(flag2,ios::beg);
				file2.write((char*)&room2,sizeof(room2));
			}
			if(room_type==3 && type>=0 && type<=2)
			{
				room3.set_type(type);
				file3.seekp(flag3,ios::beg);
				file3.write((char*)&room3,sizeof(room3));
			}
			break;
		}
	}

	file1.close();
	file2.close();
	file3.close();	
	//file4.close();
}

/*��ʼ��������Ϣ*/
void Manager::init_room_info()
{
	remove("Customer_info.txt");                //ɾ���ɵ��û���Ϣ�ļ�
	fstream file("Customer_info.txt",ios::out); //�����µĿհ��û���Ϣ�ļ�
	if(!file)
	{
		cout<<"���������ļ�����ʧ��";
		exit(0);
	}
	fstream file1("Single_room_info.txt",ios::in|ios::out);
	fstream file2("Double_room_info.txt",ios::in | ios::out);
	fstream file3("Suites.txt",ios::in|ios::out);
	if(!file1 || !file2 || !file3)
	{
		cout<<"������Ϣ��ʼ��ʧ��";
		exit(0);
	}

	Single_room room1;
	int num=100;
	int price=150;
	for(int i=1;i<=3;i++)
	{
		room1.room_info_set(num+i,price,UNCHECK,ECONOMY_ROOM);//
		file1.write((char*)&room1,sizeof(room1));
	}//���˼䣬���ü�

	num=200;
	price=220;
	for(int i=1;i<=3;i++)
	{
		room1.room_info_set(num+i,price,UNCHECK,STANDARD_ROOM);//
		file1.write((char*)&room1,sizeof(room1));
	}//���˼䣬��׼��

	num=300;
	price=300;
	for(int i=1;i<=3;i++)
	{
		room1.room_info_set(num+i,price,UNCHECK,DELUXE_ROOM);//
		file1.write((char*)&room1,sizeof(room1));
	}//���˼䣬������


	Double_room room2;
	num=400;
	price=200;
	for(int i=1;i<=3;i++)
	{
		room2.room_info_set(num+i,price,UNCHECK,ECONOMY_ROOM);
		file2.write((char*)&room2,sizeof(room2));
	}//˫�˼䣬���ü�

	num=500;
	price=250;
	for(int i=1;i<=3;i++)
	{
		room2.room_info_set(num+i,price,UNCHECK,STANDARD_ROOM);
		file2.write((char*)&room2,sizeof(room2));
	}//˫�˼䣬��׼��

	num=600;
	price=350;
	for(int i=1;i<=3;i++)
	{
		room2.room_info_set(num+i,price,UNCHECK,DELUXE_ROOM);
		file2.write((char*)&room2,sizeof(room2));
	}//˫�˼䣬������

	Suite room3;
	num=700;
	price=300;
	for(int i=1;i<=3;i++)
	{
		room3.room_info_set(num+i,price,UNCHECK,ECONOMY_ROOM);
		file3.write((char*)&room3,sizeof(room3));
	}//�׼䣬���ü�

	num=800;
	price=350;
	for(int i=1;i<=3;i++)
	{
		room3.room_info_set(num+i,price,UNCHECK,STANDARD_ROOM);
		file3.write((char*)&room3,sizeof(room3));
	}//�׼䣬��׼��

	num=900;
	price=400;
	for(int i=1;i<=3;i++)
	{
		room3.room_info_set(num+i,price,UNCHECK,DELUXE_ROOM);
		file3.write((char*)&room3,sizeof(room3));
	}//�׼䣬������

	file1.close();
	file2.close();
	file3.close();
}

//���շ�������ͺ�״̬�г����ϵķ�����Ϣ
void Manager::show_single_room(bool check_in)
{
	Single_room room1;
	fstream file1("Single_room_info.txt",ios::in|ios::out);
	if(!file1)
	{
		cout<<"���˼����ݿ����ʧ��!";
		exit(0);
	}
	file1.read((char*)&room1,sizeof(room1));
	while(!file1.eof())
	{
		if(room1.get_is_check_in()==check_in)
		{	
			room1.room_info_print();
		}
		file1.read((char*)&room1,sizeof(room1));//
	}
	file1.close();
}

void Manager::show_double_room(bool check_in)
{
	Double_room room2;
	fstream file2("Double_room_info.txt",ios::in|ios::out);
	if(!file2)
	{
		cout<<"˫�˼����ݿ����ʧ�ܣ�";
		exit(0);
	}
	file2.read((char*)&room2,sizeof(room2));
	while(!file2.eof())
	{
		if(room2.get_is_check_in()==check_in)
		{
			room2.room_info_print();
		}
		file2.read((char*)&room2,sizeof(room2));
	}
	file2.close();
}
void Manager::show_suites(bool check_in)
{
	Suite room3;
	fstream file3("Suites.txt",ios::in|ios::out);
	if(!file3)
	{
		cout<<"�׼����ݿ����ʧ�ܣ�";
		exit(0);
	}
	file3.read((char *)&room3,sizeof(room3));
	while(!file3.eof())
	{
		if(room3.get_is_check_in()==check_in)
		{
			room3.room_info_print();
		}
		file3.read((char *)&room3,sizeof(room3));
	}
	file3.close();
}