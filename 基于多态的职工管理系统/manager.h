//���Ǿ����

#pragma once
#include <iostream>     
using namespace std;
#include <string>
#include "worker.h"


//������
class Manager : public Worker
{

public:
	//����
	Manager(int id, string name, int dId);

	//��д������麯��
	//��ʾ������Ϣ 
	virtual void showInfo();

	//��ȡ��λ��Ϣ
	virtual string getDeptName();




};