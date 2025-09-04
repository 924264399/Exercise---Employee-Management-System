#include"employee.h"

//子类普通员工的函数的实现

//构造
Employee::Employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

	///构造函数嘛~ 给子类的属性赋值

}

//重写父类的虚函数
//显示个人信息 
void Employee::showInfo()
{

	cout << "职工编号：" << this->m_id
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:做底层牛马" << endl;

}

//获取岗位信息
string  Employee::getDeptName()
{


	return "员工";


 }