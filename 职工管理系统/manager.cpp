#include"manager.h"

//构造函数
Manager::Manager(int id, string name, int dId)
{
	this->m_id = id; //员工编号
	this->m_name = name; //员工姓名
	this->m_deptId = dId; //部门编号
}

// 显示员工信息
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成公司行政事务管理工作" << endl;
}

// 获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}