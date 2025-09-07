#include "workerManager.h"


//WorkerManager类的构造函数的实现 目前是空的
WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //只读文件

	if(!ifs.is_open())
	{
		cout << "文件不存在"<<endl;

		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//初始化实现
	/*this->m_EmpNum = 0;

	this->m_EmpArray = NULL;*/

}


//展示菜单
void WorkerManager::Show_Menu()
{
	cout <<"***********************************" << endl;
	cout << "*********欢迎使用职工管理系统********" << endl;
	cout << "*********0.退出管理程序*************" << endl;
	cout << "*********1.增加职工信息*************" << endl;
	cout << "*********2.显示职工信息*************" << endl;
	cout << "*********3.删除离职职工*************" << endl;
	cout << "*********4.修改职工信息*************" << endl;
	cout << "*********5.查找职工信息*************" << endl;
	cout << "*********6.按照编号排序*************" << endl;
	cout << "*********7.清空所有文档*************" << endl;
	cout << "**********************************" << endl;

	cout << endl;

}

//退出系统
void WorkerManager::ExitSystem()
{

	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);    //退出程序的函数 来自C标准库


}


//增加职工
void WorkerManager::Add_Emp()
{
	
	cout << "请输入添加职工的数量:" << endl;
	int addNum = 0; //保存用户输入数量

	cin >> addNum;

	if (addNum > 0)
	{

		//添加
		//计算添加的空间大小
		int newSzie = this->m_EmpNum + addNum; //新空间大小 = 原来的人数 + 新增人数

		Worker ** newSpace = new Worker* [newSzie]; //正因为这个数组大小是要在运行阶段确定 即无法在编译前确定这个内存的大小 所以必须要在堆区进行创建

		// 将原来空间下的数据，拷贝到新空间    这个很难理解吗  相当于先填充旧的数据
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];

			}

		}

		//添加新数据
		for (int i=0;i < addNum;i++)
		{

			int id;//职工编号
			string name; //职工姓名
			int dSelect; //部门选择

			cout << "请输入第" <<i+1<<"个新职工编号：" <<endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			cin >> dSelect;

			Worker* worker = NULL;   //多态哈
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);   
				break;
			case 2:
				worker = new Manager(id, name, 2);   
				break;

			case 3:
				worker = new Boss(id, name, 3);  
				break;

			default:
				break;


			}
			//将创建职工的职责 保存到数组中

			newSpace[this->m_EmpNum + i] = worker;  //之前的加新的 就是index


		}

		///释放内存哈
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSzie;


		//成功添加后  保存到文件中





		//提示
		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存数据到文件中
		this->save();

	}
	else
	{

		cout << "输入有误" << endl;

	}
	//////按任意键后清屏 回到上级目录

	system("pause");

	system("cls");


}



//保存文件 主要用的是这个fstream这个库的东西
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出的方式打开文件 -- 写文件  ios::out 写入模式（默认覆盖）  FILENAME是定义的一个宏  定义文件名 

	//将每个人数据写入到文件中
	for(int i = 0;i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;

	}

	//关闭文件
	ofs.close();



}



//WorkerManager类的析构函数的实现 目前是空的
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;

	}///释放堆区的数据
}