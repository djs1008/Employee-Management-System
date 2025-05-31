#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
	// ��ʼ������
	this->m_EmpArray = NULL;

	this->m_EmpNum = 0;

}

void WorkerManager::Show_Menu()
{
	cout << "*******************************************" << endl;
	cout << "********** ��ӭʹ��ְ������ϵͳ ***********" << endl;
	cout << "********** 1.���ְ����Ϣ *****************" << endl;
	cout << "********** 2.��ʾְ����Ϣ *****************" << endl;
	cout << "********** 3.ɾ��ְ����Ϣ *****************" << endl;
	cout << "********** 4.�޸�ְ����Ϣ *****************" << endl;
	cout << "********** 5.����ְ����Ϣ *****************" << endl;
	cout << "********** 6.���ձ������ *****************" << endl;
	cout << "********** 7.���ְ����Ϣ *****************" << endl;
	cout << "********** 0.�˳�ְ������ϵͳ *************" << endl;
	cout << "*******************************************" << endl;

}

void WorkerManager::Exit_System()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); // �˳�ϵͳ
}

void WorkerManager::Add_Emp()  
{  
    cout << "���������ְ��������:" << endl;  
    int addNum = 0; // ���ְ��������  
    cin >> addNum;  
    if (addNum > 0)  
    {  
        // �����¿ռ��С  
        int newSize = this->m_EmpNum + addNum; // �¿ռ�����=ԭ������+�������  

        // �����¿ռ�  
        Worker** newSpace = new Worker*[newSize];  

        // ��ԭ���ռ��ְ����Ϣ�����¿ռ�  
        if (this->m_EmpArray != NULL)  
        {  
            for (int i = 0; i < this->m_EmpNum; i++)  
            {  
                newSpace[i] = this->m_EmpArray[i];  
            }  
        }  

        // �������ְ����Ϣ  
        for (int i = 0; i < addNum; i++)  
        {  
            int id; // ְ�����  
            string name; // ְ������  
            int dSelect; // ����ѡ��  

            cout << "�������" << i + 1 << "����ְ���ı��:" << endl;  
            cin >> id;  
            cout << "�������" << i + 1 << "����ְ��������:" << endl;  
            cin >> name;  
            cout << "��ѡ���ְ���Ĳ���:" << endl;  
            cout << "1.��ְͨ��" << endl;  
            cout << "2.����" << endl;  
            cout << "3.�ϰ�" << endl;  
            cin >> dSelect;  

            Worker* worker = NULL; // ����һ��ְ������ָ��  
            switch (dSelect)  
            {  
            case 1:  
                worker = new Employee(id, name, 1);  
                break;  
            case 2:  
                worker = new Manager(id, name, 2);  
                break;  
            case 3:  
                worker = new Boss(id, name, 3);  
                break;  
            default:  
                cout << "������������������" << endl;  
                i--; // �� i �ص���ǰְ��  
                continue; // ��������ѭ��  
            }  

            // ���߽�������ȷ������д�볬������ռ���ڴ�  
            if (this->m_EmpNum + i < newSize)  
            {  
                newSpace[this->m_EmpNum + i] = worker;  
            }  
            else  
            {  
                cout << "��������: ��������ռ���ڴ淶Χ" << endl;  
                delete worker;  
                break;  
            }  
        }  

        // �ͷ�ԭ�пռ�  
        delete[] this->m_EmpArray;  

        // �����¿ռ��ָ��  
        this->m_EmpArray = newSpace;  

        // ����ְ������  
        this->m_EmpNum = newSize;  

        cout << "�ɹ����" << addNum << "����ְ��" << endl;  
    }  
    else  
    {  
        cout << "��������" << endl;  
    }  
}
WorkerManager::~WorkerManager()
{

}