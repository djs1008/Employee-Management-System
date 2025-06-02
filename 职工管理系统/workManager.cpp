#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
    //�ļ�������
    ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ����ж�ȡ
    if (!ifs.is_open())
    {
        //��ʼ������
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ����
		this->m_FileIsEmpty = true; // �ļ�Ϊ��
        ifs.close();
		return; // ֱ�ӷ��أ�����Ҫ����ִ��
    }

	//�ļ�����Ϊ��
    char ch;
    ifs >> ch; // ��ȡ��һ���ַ�
    if (ifs.eof()) // ����ļ�Ϊ��
    {
        //��ʼ������
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        //��ʼ���ļ��Ƿ����
        this->m_FileIsEmpty = true; // �ļ�Ϊ��
        ifs.close();
        return; // ֱ�ӷ��أ�����Ҫ����ִ��
    }
	
	// �ļ���Ϊ��
    int num = this->get_EmpNum();
	this->m_EmpNum = num; // ��ȡְ������

    //���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum]; // ��̬����ְ������ռ�
	this->init_Emp(); // ��ʼ��ְ����Ϣ

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

        //�ɹ���Ӻ󱣴浽�ļ���
        this->save();

		// �����ӳɹ���Ϣ
        this->m_FileIsEmpty = false;
        cout << "�ɹ����" << addNum << "����ְ��" << endl;  



    }  
    else  
    {  
        cout << "��������" << endl;  
    }  
}

void WorkerManager::save()
{
    ofstream ofs;
	ofs.open(FILENAME, ios::out);// ���ļ�����д��

	// д��ְ����Ϣ
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs<< this->m_EmpArray[i]->m_id << " "
            << this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_deptId << endl;
    }

	// �ر��ļ�
    ofs.close();
}

//ͳ��ְ������
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ����ж�ȡ

    int id;
    string name;
    int dId;
    
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    return num; // ����ְ������
}

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
    ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ����ж�ȡ

    int id;
    string name;
    int dId;
	int index = 0; // ���ڼ�¼ְ�����������

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
		Worker* worker = NULL; // ����һ��ְ������ָ��
        switch (dId)
        {
        case 1: // ��ְͨ��
            worker = new Employee(id, name, dId);
            break;
        case 2: // ����
            worker = new Manager(id, name, dId);
            break;
        case 3: // �ϰ�
            worker = new Boss(id, name, dId);
            break;
        default:
            cout << "������������������" << endl;
            continue; // ��������ѭ��
		}
		this->m_EmpArray[index] = worker; // ��ְ�������������
        index++;
    }
	// �ر��ļ�
	ifs.close();

}

//��������
WorkerManager::~WorkerManager()
{
    if (m_EmpArray != NULL)
    {
        delete[] m_EmpArray; // �ͷ�ְ������ռ�
		this->m_EmpArray = NULL; // ��������ָ��
    }
}


