#pragma once //��ֹͷ�ļ��ظ�����
#include <iostream> //���������������
#include"worker.h" //����ְ����ͷ�ļ�
using namespace std; //ʹ�ñ�׼�����ռ�

// ����������
class WorkerManager
{
public:

	//���캯��
	WorkerManager();

	//��ʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void Exit_System();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//��������
	~WorkerManager();
};
