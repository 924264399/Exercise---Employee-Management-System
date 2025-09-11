#pragma once           
#include <iostream>     
using namespace std;	
#include "worker.h"
#include "manager.h"
#include "boss.h"
#include "employee.h"

#include <fstream>   //���ڲ����ļ�
#define FILENAME "empFile.txt"



class WorkerManager
{
public:
	//����
	WorkerManager(); 

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ�������ָ��
	Worker ** m_EmpArray;

	//���ְ������
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();


	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_emp();

	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();


	//����
	~WorkerManager();


};

