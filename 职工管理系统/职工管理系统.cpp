#include<iostream>
#include"workerManager.h"
#include<string>
#include<fstream>
using namespace std;

int main()
{
	//ʵ����һ��WorkerManager����
	WorkerManager wm;

	int choice = 0; //�˵�ѡ��

	while(true)
	{
		//����չʾ�˵�����
		wm.Show_Menu();
		cout << "����������ѡ��";
		cin >> choice;//�����û������ѡ��

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.Exit_System();
			break;
		case 1: //���ְ��
			wm.Add_Emp();
			break;
		case 2: //��ʾְ��
			wm.Show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_Emp();
			break;
		case 6: //����ְ��
			wm.Sort_Emp();
			break;
		//case 7: //����ļ�
		//	wm.Clean_File();
		//	break;
		default:
			cout << "����������������룡" << endl;
			system("pause");
			system("cls"); //����
			break;
		}
	}

	system("pause");
	return 0;
}