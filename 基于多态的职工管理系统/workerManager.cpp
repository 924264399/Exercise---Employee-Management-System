#include "workerManager.h"


//WorkerManager��Ĺ��캯����ʵ�� Ŀǰ�ǿյ�
WorkerManager::WorkerManager()
{


}


//չʾ�˵�
void WorkerManager::Show_Menu()
{
	cout <<"***********************************" << endl;
	cout << "*********��ӭʹ��ְ������ϵͳ********" << endl;
	cout << "*********0.�˳��������*************" << endl;
	cout << "*********1.����ְ����Ϣ*************" << endl;
	cout << "*********2.��ʾְ����Ϣ*************" << endl;
	cout << "*********3.ɾ����ְְ��*************" << endl;
	cout << "*********4.�޸�ְ����Ϣ*************" << endl;
	cout << "*********5.����ְ����Ϣ*************" << endl;
	cout << "*********6.���ձ������*************" << endl;
	cout << "*********7.��������ĵ�*************" << endl;
	cout << "**********************************" << endl;

	cout << endl;

}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{

	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);    //�˳�����ĺ��� ����C��׼��


}


//WorkerManager�������������ʵ�� Ŀǰ�ǿյ�
WorkerManager::~WorkerManager()
{


}