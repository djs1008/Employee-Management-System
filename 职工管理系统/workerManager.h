#pragma once //防止头文件重复包含
#include <iostream> //包含输入输出流库
#include"worker.h" //包含职工类头文件
#include<fstream> //包含文件流库
using namespace std; //使用标准命名空间
#define FILENAME "empFile.txt" //定义文件名常量

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

	//保存职工信息
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件人数
	int get_EmpNum();

	//初始化职工
	void init_Emp();

	//显示职工信息
	void Show_Emp();

	//判断职工是否存在
	int IsExist(int id);

	//删除职工
	void Del_Emp();

	//修改职工信息
	void Mod_Emp();

	//查找职工信息
	void Find_Emp();

	//排序职工信息
	void Sort_Emp();

	//清空职工信息
	void Clean_File();

	//析构函数
	~WorkerManager();
};
