#include <iostream>     //包含输入输出流文件
using namespace std;	//使用标准命名空间
#include "workerManager.h"


int main()
{
	//实例化管理对象
	WorkerManager wm;

	int choice = 0; //用来存储用户的选项

	while (true)
	{
		//调用成员函数
		wm.Show_Menu();

		cout << "请输入您的选择：" << endl;
		cin >> choice; //接受用户的选项


		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;

		case 1: //增加职工
			break;

		case 2: //显示职工
			break;

		case 3: //删除职工
			break;

		case 4: //修改职工
			break;

		case 5: //查找职工
			break;

		case 6: //排序职工
			break;

		case 7: //清空文档
			break;

		default:  //如果用户输入的和上面不匹配
			system("cls");  //清屏操作
			break;

		}


	}





	system("pause");

	return 0;

}