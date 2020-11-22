#ifndef MANAGER_H
#define MANAGER_H
class Manager
{
public:
	void check_in();                  //������ס����
	void check_out();                 //�����˷�����
	void show_customer_info();        //չʾ���й˿͵���Ϣ
	void show_room_info();            //չʾ���з������Ϣ
	void show_uncheck_room_info();    //չʾ���еķ������Ϣ
	void show_check_room_info();      //չʾ��������ס�ķ������Ϣ
	void search_room();               //���뷿��ţ���ѯ�������Ϣ
	void search_customer();           //���������������ѯ������Ϣ
	void modify_room_info();         //�޸ķ���۸�

	void del_customer_info(char* name);
	void show_single_room(bool check_in);  //��ʾ���˼䷿�����Ϣ
	void show_double_room(bool check_in);  //��ʾ˫�˼䷿�����Ϣ
	void show_suites(bool check_in);       //��ʾ�׼�ķ�����Ϣ
	void init_room_info();            //��ʼ��(�ļ�)���ݿ�
};
#endif