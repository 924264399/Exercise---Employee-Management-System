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


	//2.文件存在 但是数据为空
	char ch;

	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}


	//3.文件存在 且有数据
	int num = this->get_EmpNum();
	cout << "职工的人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();

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
		this->m_FileIsEmpty = false;


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


//初始之 读取文件中的员工人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件 读文件

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) //ifs >> id  先读取一个整数到id  operator>>返回流引用，可用于链式调用  所以ifs >> name就是顺序往下读取一个string到name 又因为是while 所以每次如果返回成功 就是true
	{

		//统计人数
		num++;

	}

	return num;

}


//初始化 读取文件中的员工信息
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1) //普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);

		}

		else
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index] = worker;

		index++;
	}
	//关闭文件

	ifs.close();
}


//显示职工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空 或者 存在

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在 或者 记录为空" << endl;

	}

	else
	{
		for (int i = 0;i < m_EmpNum;i++)
		{

			//利用多态调用程序接口

			this->m_EmpArray[i]->showInfo();//这个数组的每个元素都是一个对象 别把存储文件中的排布当成数组的排布

		}
		//按任意键后清屏

		system("pause");
		system("cls");




	}


}






//删除职工
void WorkerManager::Del_emp()
{
	if (this->m_FileIsEmpty)
	{

		cout << "文件记录不存在或记录问空" << endl;

	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工编号：" << endl;
		int id = 0;

		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) //说明职工存在
		{
			//数据迁移  这种方式很耗的。。。 如果数据量很大 这要循环多少次。。。。

			for (int i = index;i < this->m_EmpNum - 1;i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum --;  //更新数组中记录人员的个数

			//同步更新到文件
			this->save();

			cout << "删除成功！" << endl;

		}
		else
		{
			cout << "删除失败,未找到该职工" << endl;

		}

	}

	//清屏
	system("pause");
	system("cls");

}

//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0;i < this->m_EmpNum;i++)
	{

		if (this->m_EmpArray[i]->m_id == id)
		{

			//找到职工
			index = i;

			break;

		}

	}

	return index;


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