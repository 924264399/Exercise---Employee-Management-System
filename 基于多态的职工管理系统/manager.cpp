#include"manager.h"

//���ྭ������ʵ��

//����
Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

	///���캯����~ ����������Ը�ֵ

}

//��д������麯��
//��ʾ������Ϣ 
void Manager::showInfo()
{

	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:Э��Ա������ϼ�Ҫ��Ĺ�������" << endl;

}

//��ȡ��λ��Ϣ
string  Manager::getDeptName()
{


	return string("����");

}