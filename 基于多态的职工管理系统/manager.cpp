#include"manager.h"

//子类经理函数的实现

//构造
Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

	///构造函数嘛~ 给子类的属性赋值

}

//重写父类的虚函数
//显示个人信息 
void Manager::showInfo()
{

	cout << "职工编号：" << this->m_id
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:协调员工完成上级要求的工作内容" << endl;

}

//获取岗位信息
string  Manager::getDeptName()
{


	return string("经理");

}