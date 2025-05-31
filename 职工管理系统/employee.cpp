#include"employee.h"

// 员工类的构造函数
Employee:: Employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}

// 显示员工信息
void Employee:: showInfo()
{
	cout<< "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成公司指定的工作任务" << endl;
}

// 获取岗位名称
string Employee:: getDeptName()
{
	return string("普通员工");
}