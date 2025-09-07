//这是经理的

#pragma once
#include <iostream>     
using namespace std;
#include <string>
#include "worker.h"


//经理类
class Manager : public Worker
{

public:
	//构造
	Manager(int id, string name, int dId);

	//重写父类的虚函数
	//显示个人信息 
	virtual void showInfo();

	//获取岗位信息
	virtual string getDeptName();




};