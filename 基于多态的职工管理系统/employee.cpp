#include"employee.h"

//������ͨԱ���ĺ�����ʵ��

//����
Employee::Employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

	///���캯����~ ����������Ը�ֵ

}

//��д������麯��
//��ʾ������Ϣ 
void Employee::showInfo()
{

	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:���ײ�ţ��" << endl;

}

//��ȡ��λ��Ϣ
string  Employee::getDeptName()
{


	return "Ա��";


 }