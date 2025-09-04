#pragma once           
#include <iostream>     
using namespace std;
#include <string>

class Worker
{
public:

	//显示个人信息 此为纯虚函数 需要在子类中重写 且父类变为抽象类 无法实例化
	virtual void showInfo() = 0;

	//获取岗位信息
	virtual string getDeptName() = 0;




	//职工编号
	int m_id;

	//职工姓名
	string m_Name;

	//部门编号
	int m_DeptId;


};
////这完全是个抽象类  所以实现都不要写
