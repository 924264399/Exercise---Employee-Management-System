//�����ϰ��

#pragma once
#include <iostream>     
using namespace std;
#include <string>
#include "worker.h"


//�ϰ���
class Boss : public Worker
{

public:
	//����
	Boss(int id, string name, int dId);

	//��д������麯��
	//��ʾ������Ϣ 
	virtual void showInfo();

	//��ȡ��λ��Ϣ
	virtual string getDeptName();




};