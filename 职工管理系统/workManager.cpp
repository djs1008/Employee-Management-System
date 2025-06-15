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
	cout << "********** 6.����ְ����Ϣ *****************" << endl;
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

        system("pause");
        system("cls");

    }  
    else  
    {  
        cout << "��������" << endl;  
    }  
    system("pause"); // ��ͣ��Ļ
    system("cls"); // ����
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

//��ʾְ����Ϣ
void WorkerManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
    }
    else
    {
        for(int i=0;i< this->m_EmpNum; i++)
        {
			//���ö�̬�����麯��
			this->m_EmpArray[i]->showInfo(); // ��ʾְ����Ϣ
		}
    }
	system("pause"); // ��ͣ��Ļ
	system("cls"); // ����
}

//�ж�ְ���Ƿ����
int WorkerManager::IsExist(int id)
{
	int index = -1; // ���ڼ�¼ְ������
    for (int i = 0; i < this->m_EmpNum; i++)  // ʹ�� m_EmpNum ��Ϊѭ������
    {
        if (this->m_EmpArray[i] != nullptr && this->m_EmpArray[i]->m_id == id)
        {
            return i;  // �ҵ�ƥ�� ID����������
        }
    }
    return -1;
}

//ɾ��ְ����Ϣ
void WorkerManager::Del_Emp()
{
    if(m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��ļ�Ϊ�գ��޷�ɾ��" << endl;
        return; // ֱ�ӷ��أ�����Ҫ����ִ��
	}
    else
    {
        int id = 0;
        cout << "������Ҫɾ����ְ�����:" << endl;
        cin >> id;
        int index = this->IsExist(id); // �ж�ְ���Ƿ����
        if (index != -1)// ���ְ������
        {
            // ɾ��ְ����Ϣ
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1]; // �������ְ����Ϣǰ��
            }
            this->m_EmpNum--; // ְ��������һ
            // ���浽�ļ���
            this->save();
            cout << "ɾ���ɹ�" << endl;
        }
        else // ���ְ��������
        {
            cout << "ְ�������ڣ�ɾ��ʧ��" << endl;
		}
		system("pause"); // ��ͣ��Ļ
		system("cls"); // ����
    }
}

//�޸�ְ����Ϣ
void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
		cout << "�ļ������ڻ��ļ�Ϊ�գ��޷��޸�" << endl;
    }
    else
    {
		cout << "������Ҫ�޸ĵ�ְ�����:" << endl;
        int id = 0;
        cin >> id;
		int ret = this->IsExist(id); // �ж�ְ���Ƿ����
        if (ret != -1)
        {
            int newId = 0; // ��ְ�����
            string newName = ""; // ��ְ������
            int newDeptId = 0; // �²��ű��
            cout << "�鵽ְ����Ϣ����:" << endl;
            this->m_EmpArray[ret]->showInfo(); // ��ʾԭ��ְ����Ϣ
            delete this->m_EmpArray[ret]; // �ͷ�ԭ��ְ��������ڴ�ռ�
            cout << "�������µ�ְ�����:" << endl;
            cin >> newId;
            cout << "�������µ�ְ������:" << endl;
            cin >> newName;
            cout << "��ѡ���µ�ְ������:" << endl;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin >> newDeptId;
            Worker* worker = NULL;
            switch (newDeptId)
            {
            case 1: // ��ְͨ��
                worker = new Employee(newId, newName, newDeptId);
                break;
            case 2: // ����
                worker = new Manager(newId, newName, newDeptId);
                break;
            case 3: // �ϰ�
                worker = new Boss(newId, newName, newDeptId);
                break;
            default:
                break;
            }
            // ����ְ�������������
			this->m_EmpArray[ret] = worker; // ����ְ����Ϣ
			cout << "�޸ĳɹ�" << endl;
			// ���浽�ļ���
            this->save();
        }
        else
            // ���ְ��������
        {
            cout << "ְ�������ڣ��޸�ʧ��" << endl;
        }
    }
	system("pause"); // ��ͣ��Ļ
	system("cls"); // ����
}

//����ְ����Ϣ
void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��ļ�Ϊ�գ��޷�����" << endl;
    }
    else
    {
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;
		cin >> select;
        if (select == 1) // ��ְ����Ų���
        {
            int id;
			cout << "������Ҫ���ҵ�ְ�����:" << endl;
            cin >> id;
			int ret = this->IsExist(id); // �ж�ְ���Ƿ����
            if (ret != -1)
            {
                cout << "���ҳɹ���" << endl;
                cout << "���ҵ�ְ����Ϣ����:" << endl;
				this->m_EmpArray[ret]->showInfo(); // ��ʾְ����Ϣ
            }
            else
            {
				cout << "���ҵ�ְ��������" << endl;
            }
        }

        else if (select == 2)
        {
            string name;
            cout<<"������Ҫ���ҵ�ְ������:" << endl;
            cin >> name;
			bool flag = false; // ���ڱ���Ƿ��ҵ�ְ��
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL && this->m_EmpArray[i]->m_name == name)
                {
                    cout << "���ҳɹ���" << endl;
					cout << "���ҵ�ְ����Ϣ����:" << endl;
					this->m_EmpArray[i]->showInfo(); // ��ʾְ����Ϣ
					flag = true; // �ҵ�ְ��
                }
            }
            if(!flag) // ���û���ҵ�ְ��
            {
                cout << "���ҵ�ְ��������" << endl;
			}
        }

        else
        {
            cout << "������������������" << endl;
			return; // ֱ�ӷ��أ�����Ҫ����ִ��
        }
        system("pause"); // ��ͣ��Ļ
        system("cls"); // ����

    }
}

//����ְ����Ϣ
void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
		cout << "�ļ������ڻ�Ϊ�գ��޷�����" << endl;
		system("pause"); // ��ͣ��Ļ
        system("cls"); // ����
    }
    else
    {
		cout << "��ѡ������ʽ:" << endl;
		cout << "1.��ְ���������" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;
        cin >> select;
        if (select == 1) //����ְ���������
        {
			cout << "��ѡ������ʽ:" << endl;
			cout << "1.����" << endl;
			cout << "2.����" << endl;
			int order = 0;
			cin >> order;

            for (int i = 0; i < this->m_EmpNum; i++)
            {
				int minOrMax = i; // ��¼��С�����ֵ������
                for (int j = i + 1; j < this ->m_EmpNum; j++)
                {
                    if (order == 1)
                    {
                        if(this->m_EmpArray[j]->m_id < this->m_EmpArray[minOrMax]->m_id)
                        {
                            minOrMax = j; // �ҵ���С��ְ�����
						}
                    }
                    else
                    {
                        if (this->m_EmpArray[j]->m_id > this->m_EmpArray[minOrMax]->m_id)
                        {
                            minOrMax = j; // �ҵ������ְ�����
                        }
                    }
                }
                if (minOrMax != i)
                {
					Worker* temp = this->m_EmpArray[i]; // ����ְ����Ϣ
                    this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
					this->m_EmpArray[minOrMax] = temp;
                }
            }
			cout << "ְ����Ϣ����ְ���������ɹ�" << endl;
			this->save(); // ���浽�ļ���
            system("pause"); // ��ͣ��Ļ
            system("cls"); // ����
        }
        else if (select == 2) // ����ְ����������
        {
            cout << "��ѡ������ʽ:" << endl;
            cout << "1.����" << endl;
            cout << "2.����" << endl;
            int order = 0;
            cin >> order;
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                int minOrMax = i; // ��¼��С�����ֵ������
                for (int j = i + 1; j < this ->m_EmpNum; j++)
                {
                    if (order == 1)
                    {
                        if (this->m_EmpArray[j]->m_name < this->m_EmpArray[minOrMax]->m_name)
                        {
                            minOrMax = j; // �ҵ���С��ְ�����
                        }
                    }
                    else
                    {
                        if (this->m_EmpArray[j]->m_name > this->m_EmpArray[minOrMax]->m_name)
                        {
                            minOrMax = j; // �ҵ������ְ�����
                        }
                    }
                }
                if (minOrMax != i)
                {
                    Worker* temp = this->m_EmpArray[i]; // ����ְ����Ϣ
                    this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                    this->m_EmpArray[minOrMax] = temp;
                }
            }
			cout << "ְ����Ϣ����ְ����������ɹ�" << endl;
            this->save(); // ���浽�ļ���
            system("pause"); // ��ͣ��Ļ
            system("cls"); // ����
        }
    }
}

//���ְ����Ϣ
void WorkerManager::Clean_File()
{
	cout << "ȷ���������ְ����Ϣ��" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int select = 0;
	cin >> select;
    if (select == 1)
    {
        //����ļ�
		ofstream ofs(FILENAME, ios::trunc);// ����ļ������´���
		ofs.close(); // �ر��ļ�
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i]; // �ͷ�ÿ��ְ��������ڴ�ռ�
                    this->m_EmpArray[i] = NULL; // ��������ָ��
                }
            }
            delete[] m_EmpArray; // �ͷ�ְ������ռ�
            this->m_EmpArray = NULL; // ��������ָ��
			this->m_EmpNum = 0; // ְ����������
            this->m_FileIsEmpty = true; // �ļ�Ϊ��
            cout << "��ճɹ�" << endl;
        }
        else
        {
			cout << "�ļ������" << endl;
        }
    }
    else if (select == 2)
    {
		cout << "ȡ����ղ���" << endl;
    }
    system("pause"); // ��ͣ��Ļ
    system("cls"); // ����
}

//��������
WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        for(int i=0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i] != NULL)
            {
                delete this->m_EmpArray[i]; // �ͷ�ÿ��ְ��������ڴ�ռ�
                this->m_EmpArray[i] = NULL; // ��������ָ��
            }
		}
        delete[] m_EmpArray; // �ͷ�ְ������ռ�
		this->m_EmpArray = NULL; // ��������ָ��
    }
}


