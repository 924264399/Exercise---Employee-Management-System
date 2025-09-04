//这是普通职工的

#pragma once
#include <iostream>     
using namespace std;
#include <string>
#include "worker.h"

class Employee : public Worker
{

public:
	//构造
	Employee(int id,string name,int dId);

	//重写父类的虚函数
	//显示个人信息 
	virtual void showInfo();

	//获取岗位信息
	virtual string getDeptName();




};
