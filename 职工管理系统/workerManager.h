#pragma once //��ֹͷ�ļ��ظ�����
#include <iostream> //���������������
#include"worker.h" //����ְ����ͷ�ļ�
#include<fstream> //�����ļ�����
using namespace std; //ʹ�ñ�׼�����ռ�
#define FILENAME "empFile.txt" //�����ļ�������

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

	//����ְ����Ϣ
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ�����
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//��ʾְ����Ϣ
	void Show_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ����Ϣ
	void Mod_Emp();

	//����ְ����Ϣ
	void Find_Emp();

	//����ְ����Ϣ
	void Sort_Emp();

	//���ְ����Ϣ
	void Clean_File();

	//��������
	~WorkerManager();
};
