#pragma once           
#include <iostream>     
using namespace std;
#include <string>

class Worker
{
public:

	//��ʾ������Ϣ ��Ϊ���麯�� ��Ҫ����������д �Ҹ����Ϊ������ �޷�ʵ����
	virtual void showInfo() = 0;

	//��ȡ��λ��Ϣ
	virtual string getDeptName() = 0;




	//ְ�����
	int m_id;

	//ְ������
	string m_Name;

	//���ű��
	int m_DeptId;


};
////����ȫ�Ǹ�������  ����ʵ�ֶ���Ҫд
