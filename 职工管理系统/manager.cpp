#include"manager.h"

//���캯��
Manager::Manager(int id, string name, int dId)
{
	this->m_id = id; //Ա�����
	this->m_name = name; //Ա������
	this->m_deptId = dId; //���ű��
}

// ��ʾԱ����Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɹ�˾�������������" << endl;
}

// ��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}