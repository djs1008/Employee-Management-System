#include"boss.h"

// Boss类的构造函数
Boss::Boss(int id, string name, int dId)
{
	this->m_id = id; // 设置Boss的ID
	this->m_name = name; // 设置Boss的姓名
	this->m_deptId = dId; // 设置Boss所在部门的ID
}

//显示信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：管理公司的所有事务" << endl;
}

//获取岗位名称
string Boss::getDeptName()
{
	return string("总裁"); // 返回岗位名称为"总裁"
}