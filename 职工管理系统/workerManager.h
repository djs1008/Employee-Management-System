#pragma once //防止头文件重复包含
#include <iostream> //包含输入输出流库
#include"worker.h" //包含职工类头文件
using namespace std; //使用标准命名空间

// 工作管理类
class WorkerManager
{
public:

	//构造函数
	WorkerManager();

	//显示菜单
	void Show_Menu();

	//退出系统
	void Exit_System();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//析构函数
	~WorkerManager();
};
