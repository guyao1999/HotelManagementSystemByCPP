#ifndef SINGLE_ROOM_H
#define SINGLE_ROOM_H
#include "Room.h"
class Single_room:public Room//≈……˙¿‡
{
private:
	Customer customer;
public:
	void set_cutomer(Customer& customer);
	Customer& get_customer();
    //void room_info_set(int num,int price,bool is_check_in,int type);  
	void room_info_print();//
};
#endif