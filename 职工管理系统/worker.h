#pragma once
#include<iostream>
#include<string>
using namespace std;

//抽象职工类
class Worker
{
public:
	//显示个人信息的纯虚函数
	virtual void showInfo() = 0;
	//获取岗位名称的纯虚函数
	virtual string getDeptName() = 0;

	int m_id; //职工编号
	string m_name; //职工姓名
	int m_deptId; //所属部门编号
};
