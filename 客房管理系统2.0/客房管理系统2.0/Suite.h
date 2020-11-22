#include "Room.h"
#include "Customer.h"
class Suite:public Room
{
private:
	Customer customer1;
	Customer customer2;
	Customer customer3;
public :
	void set_cutomer1(Customer& customer1);
	void set_cutomer2(Customer& customer2);
	void set_cutomer3(Customer& customer3);
	Customer& get_customer1();
	Customer& get_customer2();
	Customer& get_customer3();
	//void room_info_set(int num,int price,bool is_check_in,int type);
	void room_info_print();
};
