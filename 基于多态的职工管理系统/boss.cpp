#include"boss.h"

//���ྭ������ʵ��

//����
Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

	///���캯����~ ����������Ը�ֵ

}

//��д������麯��
//��ʾ������Ϣ 
void Boss::showInfo()
{

	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:�ƶ���ҵ��չս���쵼��ҵ" << endl;

}

//��ȡ��λ��Ϣ
string  Boss::getDeptName()
{


	return string("Boss");

}