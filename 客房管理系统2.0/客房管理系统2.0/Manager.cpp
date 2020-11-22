#include "Manager.h"
#include "Customer.h"
#include "Room.h"
#include "Single_room.h"
#include "Double_room.h"
#include "Suite.h"
#include <fstream>
#include <iostream>
using namespace std;


/*客人入住办理*/
void Manager::check_in()
{  
    cout<<"选择房间类型  1：单人间   2：双人间  3：套间"<<endl;
	int select;
	do{
		cout<<"选择：";
		cin>>select;
	}while(select<1 || select>3);
	int room_num;
	char name[10];
	char id[19];
	int days;
	time_t date;
	bool search=false;
	streampos flag;  //相对起点的位置
	switch(select)
	{
	case 1:
		{
			cout<<"----------------------当前空闲的单人间如下------------------"<<endl;
			this->show_single_room(UNCHECK);                  //显示空闲的单人间信息
			cout<<"------------------------------------------------------------"<<endl;
			
			fstream file1("Single_room_info.txt",ios::in|ios::out);
			if(!file1)
			{
				cout<<"单人间数据库访问失败!";
				exit(0);
			}
			Single_room room;
			do{
				cout<<"输入房间号：";
				cin>>room_num;
				file1.clear();           //将文件的状态初始化
				file1.seekg(0L,ios::beg);//跳转到文件开头
			
				while(!file1.eof())
				{        
					flag=file1.tellg();                        //得到文件位置指针，便于数据的修改
					file1.read((char*)&room,sizeof(room));      
					if(room.get_num()==room_num && room.get_is_check_in()==false) //查找到该房间号
					{
						search=true;
						break;
					}
				}

				if(!search)
				{
					cout<<"房间号错误或该房间已有顾客入住!请从新输入房间号"<<endl;
				}
			}while(!search);//对每次输入的房间号进行检查，看是否存在和空闲

			cout<<"输入顾客姓名：";
			cin>>name;
			cout<<"输入身份证号：";
			cin>>id;
			cout<<"输入入住天数：";
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
				cout<<"客人信息数据库访问失败";
				exit(0);
			}
			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));          //重新写入房间信息
			file2.write((char*)&customer,sizeof(customer));  //写入客人信息

			file1.close();
			file2.close();
			cout<<"入住办理成功！"<<endl;
			break;
		}
	case 2: 
		{	
			cout<<"----------------------当前空闲的双人间如下------------------"<<endl;
			this->show_double_room(UNCHECK);
			cout<<"------------------------------------------------------------"<<endl;
			fstream file1("Double_room_info.txt",ios::in|ios::out);
			if(!file1)
			{
				cout<<"双人间数据库访问失败!";
				exit(0);
			}
			Double_room room;
			do{
				cout<<"输入房间号：";
				cin>>room_num;
				file1.clear();           //将文件的状态初始化
				file1.seekg(0L,ios::beg);//跳转到文件开头
			
				while(!file1.eof())
				{        
					flag=file1.tellg();                        //得到文件位置指针，便于数据的修改
					file1.read((char*)&room,sizeof(room));      
					if(room.get_num()==room_num && room.get_is_check_in()==false) //查找到该房间号
					{
						search=true;
						break;
					}
				}
				if(!search)
				{
					cout<<"房间号错误或该房间已有顾客入住!请从新输入房间号"<<endl;
				}
			}while(!search);     //对每次输入的房间号进行检查，看是否存在或空闲

			cout<<"输入顾客1姓名：";
			cin>>name;
			cout<<"输入顾客1身份证号：";
			cin>>id;
			cout<<"输入入住天数：";
			cin>>days;
			date=time(0);
			Customer customer1;
			customer1.info_set(name,id,room_num,days,date);//顾客1信息设置

			cout<<"输入顾客2姓名：";
			cin>>name;
			cout<<"输入顾客2身份证号：";
			cin>>id;
			Customer customer2;
			customer2.info_set(name,id,room_num,days,date);//顾客2信息设置

		
			room.set_days(days);
			room.set_is_check_in(true);
			room.set_cutomer1(customer1);
			room.set_cutomer2(customer2);
			room.set_date(date);//房间信息设置

			fstream file2("Customer_info.txt",ios::in|ios::out|ios::app);
			if(!file2)
			{
				cout<<"客人信息数据库访问失败";
				exit(0);
			}
			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));          //重新写入房间信息
			file2.write((char*)&customer1,sizeof(customer1));//写入顾客1信息
			file2.write((char*)&customer2,sizeof(customer2));//写入顾客2信息

			file1.close();
			file2.close();
			cout<<"入住办理成功！"<<endl;
			break;
		}
	case 3: 
		{
			cout<<"----------------------当前空闲的套间如下------------------"<<endl;
			this->show_suites(UNCHECK);
			cout<<"------------------------------------------------------------"<<endl;
			fstream file1("Suites.txt",ios::in|ios::out);
			if(!file1)
			{
				cout<<"套间数据库访问失败!";
				exit(0);
			}
			Suite room;
			do{
				cout<<"输入房间号：";
				cin>>room_num;
				file1.clear();           //将文件的状态初始化
				file1.seekg(0L,ios::beg);//跳转到文件开头
			
				while(!file1.eof())
				{        
					flag=file1.tellg();                        //得到文件位置指针，便于数据的修改
					file1.read((char*)&room,sizeof(room));      
					if(room.get_num()==room_num && room.get_is_check_in()==false) //查找到该房间号
					{
						search=true;
						break;
					}
				}

				if(!search)
				{
					cout<<"房间号错误或该房间已有顾客入住!请从新输入房间号"<<endl;
				}
			}while(!search);//对每次输入的房间号进行检查，看是否存在和空闲
			cout<<"输入顾客1姓名：";
			cin>>name;
			cout<<"输入顾客1身份证号：";
			cin>>id;
			cout<<"输入入住天数：";
			cin>>days;
			date=time(0);
			Customer customer1;
			customer1.info_set(name,id,room_num,days,date);//顾客1信息设置

			cout<<"输入顾客2姓名：";
			cin>>name;
			cout<<"输入顾客2身份证号：";
			cin>>id;
			Customer customer2;
			customer2.info_set(name,id,room_num,days,date);//顾客2信息设置

			cout<<"输入顾客3姓名：";
			cin>>name;
			cout<<"输入顾客3身份证号：";
			cin>>id;
			Customer customer3;
			customer3.info_set(name,id,room_num,days,date);//顾客3信息设置

			room.set_days(days);
			room.set_is_check_in(true);
			room.set_cutomer1(customer1);
			room.set_cutomer1(customer2);
			room.set_cutomer3(customer3);
			room.set_date(date);//房间信息设置
		

			fstream file2("Customer_info.txt",ios::in|ios::out|ios::app);
			if(!file2)
			{
				cout<<"客人信息数据库访问失败";
				exit(0);
			}
			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));          //重新写入房间信息
			file2.write((char*)&customer1,sizeof(customer1));//写入客人1信息
			file2.write((char*)&customer2,sizeof(customer2));//写入客人2信息
			file2.write((char*)&customer3,sizeof(customer3));//写入客人3信息

			file1.close();
			file2.close();
			cout<<"入住办理成功！"<<endl;
			break;
		}
	}
}
/*客人退房办理*/
void Manager::check_out()
{
	fstream file1("Single_room_info.txt",ios::in|ios::out);
	if(!file1)
	{
		cout<<"单人间数据库访问失败";
		exit(0);
	}//打开单人间数据库

	fstream file2("Double_room_info.txt",ios::in|ios::out);
	if(!file2)
	{
		cout<<"双人间数据库访问失败";
		exit(0);
	}//打开双人间数据库

	fstream file3("Suites.txt",ios::in|ios::out);
	if(!file3)
	{
		cout<<"双人间数据库访问失败";
		exit(0);
	}//打开套间数据库

	int room_num;
	cout<<"输入房间号：";
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
			cout<<"---------------------房间信息------------------------"<<endl;
			room.room_info_print();
			cout<<"需付费用："<<room.get_price() *room.get_days()<<"元"<<endl;

			room.set_is_check_in(false);
			room.set_days(0);

			del_customer_info(room.get_customer().get_name());
			//顾客信息删除

			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));
			cout<<"退房办理成功!"<<endl;
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
			cout<<"---------------------房间信息------------------------"<<endl;
			room.room_info_print();
			cout<<"需付费用："<<room.get_price() *room.get_days()<<"元"<<endl;

			room.set_is_check_in(false);
			room.set_days(0);

			del_customer_info(room.get_customer1().get_name());
			del_customer_info(room.get_customer2().get_name());
			//顾客信息删除



			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));
			cout<<"退房办理成功!"<<endl;
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
			cout<<"---------------------房间信息------------------------"<<endl;
			room.room_info_print();
			cout<<"需付费用："<<room.get_price() *room.get_days()<<"元"<<endl;

			room.set_is_check_in(false);
			room.set_days(0);

			del_customer_info(room.get_customer1().get_name());
			del_customer_info(room.get_customer2().get_name());
			del_customer_info(room.get_customer3().get_name());
			//顾客信息删除

			file1.seekp(flag,ios::beg);
			file1.write((char*)&room,sizeof(room));
			cout<<"退房办理成功!"<<endl;
			break;
		}
	}
	if(search==false)
	{
		cout<<"房间号错误或该房间没有人入住!"<<endl;
	}
	file1.close();
	file2.close();
	file3.close();
}

/*显示所有房间信息*/
void Manager::show_room_info()
{
	cout<<endl<<"-----------------------------单人间------------------------"<<endl;
	this->show_single_room(false);
	this->show_single_room(true);

	cout<<endl<<"-----------------------------双人间-------------------------"<<endl;
	this->show_double_room(false);
	this->show_double_room(true);

	cout<<endl<<"-----------------------------套间---------------------------"<<endl;
	this->show_suites(false);
	this->show_suites(true);
}	

/*显示所有未入住房间信息*/
void Manager::show_uncheck_room_info()
{
	cout<<"-------------------------------空闲房间查询-----------------------------------"<<endl;
    cout<<"选择要查询的房间类型！    1：单人间   2：双人间  3：套间   4：所有类型房间"<<endl;
	int select;
	do
	{
		cout<<"选择：";
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

			cout<<"----------------------------单人间-------------------------"<<endl;
			this->show_single_room(false);
			cout<<"----------------------------双人间-------------------------"<<endl;
			this->show_double_room(false);
			cout<<"----------------------------套间---------------------------"<<endl;
			this->show_suites(false);
			break;
		}
	}
}

/*显示所有已入住房间信息*/
void Manager::show_check_room_info()//展示所有已入住的房间
{
	cout<<"-------------------------------已入住房间查询-----------------------------------"<<endl;
	cout<<"选择要查询的剩余的房间类型！    1：单人间   2：双人间  3：套间  4：所有类型房间"<<endl;
	int select;
	do
	{
		cout<<"选择：";
		cin>>select;
	}while(select<1 || select>4);
	switch(select)
	{
	case 1:
		{
			cout<<"----------------------------单人间---------------------------------"<<endl;
			this->show_single_room(true);
			break;
		}
	case 2:
		{
			cout<<"----------------------------双人间---------------------------------"<<endl;
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
			cout<<"----------------------------单人间---------------------------------"<<endl;
			this->show_single_room(true);
			cout<<"----------------------------双人间---------------------------------"<<endl;
			this->show_double_room(true);
			cout<<"----------------------------套间-----------------------------------"<<endl;
			this->show_suites(true);
			break;
		}
	}
}

/*显示所有客人信息*/
void Manager::show_customer_info()
{
	int num=0;
	cout<<"--------------------所有入住客人信息如下--------------------"<<endl;
	fstream file("Customer_info.txt",ios::in|ios::out);
	if(!file)
	{
		cout<<"用户信息数据库访问失败";
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
		cout<<"暂且没有客人入住"<<endl;
	}
	cout<<"---------------------------------------------------------------"<<endl;
	file.close();
}

/*输入房间号或价格，查询符合的房间信息*/
void Manager::search_room()
{
	int select;	
	do
	{
		cout<<"选择查询模式  1：按房间号查询   2：按价格区间查询"<<endl;
		cout<<"选择：";
		cin>>select;

	}while(select<1 || select>2);

	fstream file1("Single_room_info.txt",ios::in|ios::out);
	if(!file1)
	{
		cout<<"单人间数据库访问失败";
		exit(0);
	}//打开单人间数据库

	fstream file2("Double_room_info.txt",ios::in|ios::out);
	if(!file2)
	{
		cout<<"双人间数据库访问失败";
		exit(0);
	}//打开双人间数据库

	fstream file3("Suites.txt",ios::in|ios::out);
	if(!file3)
	{
		cout<<"双人间数据库访问失败";
		exit(0);
	}//打开套间数据库

	switch(select)
	{
	case 1://按房间号查询
		{
			int room_num;
			cout<<"输入房间号：";
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

	case 2://按价格区间查询
		{
			int low_price;
			int heigh_price;
			cout<<"输入价格区间："<<endl;
			cout<<"最低价：";
			cin>>low_price;
			cout<<"最高价：";
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

/* 输入客人姓名或身份证号，查询客人信息*/
void Manager::search_customer()
{
	int select;	
	char name[10];
	char id[19];
	do
	{
		cout<<"选择查询模式     1：按姓名查询   2：按身份证号查询"<<endl;
		cout<<"选择：";
		cin>>select;

	}while(select<1 || select>2);
	if(select==1)
	{
		cout<<"输入客人姓名：";
	cin>>name;

	}
	else
	{
		cout<<"输入身份证号：";
		cin>>id;
	}
	fstream file("Customer_info.txt",ios::in|ios::out);
	if(!file)
	{
		cout<<"客人信息数据库访问失败"<<endl;
		exit(0);
	}
	bool flag=false;//标记是否查询到
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
		cout<<"没有查询到该客人的信息！"<<endl;
	}
	file.close();
}

void Manager::del_customer_info(char *name)
{
	fstream file1("Customer_info.txt",ios::in|ios::out);
	if(!file1)
	{
		cout<<"客人信息数据库访问失败";
		exit(0);
	}
	fstream file2("temp.txt",ios::out);//文件不存在会自动生成
	if(!file2)
	{
		cout<<"临时文件生成失败！";
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
/*修改房间信息*/
void Manager::modify_room_info()
{
	int room_num;
	cout<<"输入房间号对其信息进行修改：";
	cin>>room_num;

	fstream file1("Single_room_info.txt",ios::in|ios::out);
	if(!file1) 
	{
		cout<<"单人间数据库访问失败";
		exit(0);
	}//打开单人间数据库

	fstream file2("Double_room_info.txt",ios::in|ios::out);
	if(!file2)
	{
		cout<<"双人间数据库访问失败";
		exit(0);
	}//打开双人间数据库

	fstream file3("Suites.txt",ios::in|ios::out);
	if(!file3)
	{
		cout<<"套间数据库访问失败";
		exit(0);
	}//打开套间数据库

	/*fstream file4("Customer_info.txt",ios::in|ios::out);
	if(!file4)
	{
		cout<<"顾客信息数据库访问失败";
		exit(0);
	}*/

	streampos flag1,flag2,flag3;   //用于标记三个文件中读到符合的房间信息的位置
	int room_type=0;               //用于标记输入的房间号属于什么类型的房间，
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
			cout<<"--------------------该房间信息--------------------"<<endl;
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
			cout<<"--------------------该房间信息--------------------"<<endl;
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
			cout<<"--------------------该房间信息--------------------"<<endl;
			room3.room_info_print();
			cout<<"----------------------------------------------------"<<endl;
			break;
		}
	}
	if(room_type==0)
	{
		cout<<"没有查找到该房间的信息，请核对输入是否正确"<<endl;
		return;
	}

	cout<<"选择要修改的房间信息.   1：房间号    2：房间价格    3：房间类型  "<<endl;
	
	int select;             //要修改的内容
	int num;                //修改后的房间号
	int type;               //修改后的类型
	int price;              //修改后的价格
	do
	{
		cout<<"选择：";
		cin>>select;
	}while(select<1 || select>3);
	switch(select)
	{
	case 1:
		{
			cout<<"输入修改后的房间号：";
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
			cout<<"修改成功！"<<endl;
		    break;
		}
	case 2:
		{
			cout<<"输入修改后的房间价格：";
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
			cout<<"输入修改后的房间类型：  0：经济间  1：标准间   2：豪华间" ;
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

/*初始化房间信息*/
void Manager::init_room_info()
{
	remove("Customer_info.txt");                //删除旧的用户信息文件
	fstream file("Customer_info.txt",ios::out); //创建新的空白用户信息文件
	if(!file)
	{
		cout<<"客人数据文件创建失败";
		exit(0);
	}
	fstream file1("Single_room_info.txt",ios::in|ios::out);
	fstream file2("Double_room_info.txt",ios::in | ios::out);
	fstream file3("Suites.txt",ios::in|ios::out);
	if(!file1 || !file2 || !file3)
	{
		cout<<"房间信息初始化失败";
		exit(0);
	}

	Single_room room1;
	int num=100;
	int price=150;
	for(int i=1;i<=3;i++)
	{
		room1.room_info_set(num+i,price,UNCHECK,ECONOMY_ROOM);//
		file1.write((char*)&room1,sizeof(room1));
	}//单人间，经济间

	num=200;
	price=220;
	for(int i=1;i<=3;i++)
	{
		room1.room_info_set(num+i,price,UNCHECK,STANDARD_ROOM);//
		file1.write((char*)&room1,sizeof(room1));
	}//单人间，标准间

	num=300;
	price=300;
	for(int i=1;i<=3;i++)
	{
		room1.room_info_set(num+i,price,UNCHECK,DELUXE_ROOM);//
		file1.write((char*)&room1,sizeof(room1));
	}//单人间，豪华间


	Double_room room2;
	num=400;
	price=200;
	for(int i=1;i<=3;i++)
	{
		room2.room_info_set(num+i,price,UNCHECK,ECONOMY_ROOM);
		file2.write((char*)&room2,sizeof(room2));
	}//双人间，经济间

	num=500;
	price=250;
	for(int i=1;i<=3;i++)
	{
		room2.room_info_set(num+i,price,UNCHECK,STANDARD_ROOM);
		file2.write((char*)&room2,sizeof(room2));
	}//双人间，标准间

	num=600;
	price=350;
	for(int i=1;i<=3;i++)
	{
		room2.room_info_set(num+i,price,UNCHECK,DELUXE_ROOM);
		file2.write((char*)&room2,sizeof(room2));
	}//双人间，豪华间

	Suite room3;
	num=700;
	price=300;
	for(int i=1;i<=3;i++)
	{
		room3.room_info_set(num+i,price,UNCHECK,ECONOMY_ROOM);
		file3.write((char*)&room3,sizeof(room3));
	}//套间，经济间

	num=800;
	price=350;
	for(int i=1;i<=3;i++)
	{
		room3.room_info_set(num+i,price,UNCHECK,STANDARD_ROOM);
		file3.write((char*)&room3,sizeof(room3));
	}//套间，标准间

	num=900;
	price=400;
	for(int i=1;i<=3;i++)
	{
		room3.room_info_set(num+i,price,UNCHECK,DELUXE_ROOM);
		file3.write((char*)&room3,sizeof(room3));
	}//套间，豪华间

	file1.close();
	file2.close();
	file3.close();
}

//按照房间的类型和状态列出符合的房间信息
void Manager::show_single_room(bool check_in)
{
	Single_room room1;
	fstream file1("Single_room_info.txt",ios::in|ios::out);
	if(!file1)
	{
		cout<<"单人间数据库访问失败!";
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
		cout<<"双人间数据库访问失败！";
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
		cout<<"套间数据库访问失败！";
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