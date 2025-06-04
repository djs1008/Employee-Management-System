#include<iostream>
#include"workerManager.h"
#include<string>
#include<fstream>
using namespace std;

int main()
{
	//实例化一个WorkerManager对象
	WorkerManager wm;

	int choice = 0; //菜单选项

	while(true)
	{
		//调用展示菜单函数
		wm.Show_Menu();
		cout << "请输入您的选择：";
		cin >> choice;//接受用户输入的选项

		switch (choice)
		{
		case 0: //退出系统
			wm.Exit_System();
			break;
		case 1: //添加职工
			wm.Add_Emp();
			break;
		case 2: //显示职工
			wm.Show_Emp();
			break;
		case 3: //删除职工
			wm.Del_Emp();
			break;
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: //排序职工
			wm.Sort_Emp();
			break;
		//case 7: //清空文件
		//	wm.Clean_File();
		//	break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls"); //清屏
			break;
		}
	}

	system("pause");
	return 0;
}