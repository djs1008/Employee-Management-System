#include"boss.h"

// Boss��Ĺ��캯��
Boss::Boss(int id, string name, int dId)
{
	this->m_id = id; // ����Boss��ID
	this->m_name = name; // ����Boss������
	this->m_deptId = dId; // ����Boss���ڲ��ŵ�ID
}

//��ʾ��Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾����������" << endl;
}

//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ܲ�"); // ���ظ�λ����Ϊ"�ܲ�"
}