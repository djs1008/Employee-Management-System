#include"employee.h"

// Ա����Ĺ��캯��
Employee:: Employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}

// ��ʾԱ����Ϣ
void Employee:: showInfo()
{
	cout<< "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɹ�˾ָ���Ĺ�������" << endl;
}

// ��ȡ��λ����
string Employee:: getDeptName()
{
	return string("��ͨԱ��");
}