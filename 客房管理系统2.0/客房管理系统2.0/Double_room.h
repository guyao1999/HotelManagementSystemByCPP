#include "Room.h"
class Double_room:public Room
{
private:
	Customer customer1;    //��ס�˿�1
	Customer customer2;    //��ס�˿�2
public:
	void set_cutomer1(Customer& customer1);
	void set_cutomer2(Customer& customer2);
	Customer& get_customer1();
	Customer& get_customer2();
	//void room_info_set(int num,int price,bool is_check_in,int type);
	void room_info_print();
}; 