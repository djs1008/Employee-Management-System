#pragma once
#include <string>
#include <iostream>
#include "worker.h"
using namespace std;
//经理类
class Manager : public Worker
{
public:
	//构造函数
	Manager(int id, string name, int dId);

	//显示信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptName();
};

