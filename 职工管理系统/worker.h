#pragma once
#include<iostream>
#include<string>
using namespace std;

//����ְ����
class Worker
{
public:
	//��ʾ������Ϣ�Ĵ��麯��
	virtual void showInfo() = 0;
	//��ȡ��λ���ƵĴ��麯��
	virtual string getDeptName() = 0;

	int m_id; //ְ�����
	string m_name; //ְ������
	int m_deptId; //�������ű��
};
