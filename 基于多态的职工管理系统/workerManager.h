#pragma once           
#include <iostream>     
using namespace std;	
#include "worker.h"
#include "manager.h"
#include "boss.h"
#include "employee.h"

class WorkerManager
{
public:
	//构造
	WorkerManager(); 

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组的指针
	Worker ** m_EmpArray;

	//添加职工函数
	void Add_Emp();




	//析构
	~WorkerManager();


};

