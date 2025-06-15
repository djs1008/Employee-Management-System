#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
    //文件不存在
    ifstream ifs;
	ifs.open(FILENAME, ios::in); // 打开文件进行读取
    if (!ifs.is_open())
    {
        //初始化属性
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
		//初始化文件是否存在
		this->m_FileIsEmpty = true; // 文件为空
        ifs.close();
    }

	//文件存在为空
    char ch;
    ifs >> ch; // 读取第一个字符
    if (ifs.eof()) // 如果文件为空
    {
        //初始化属性
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        //初始化文件是否存在
        this->m_FileIsEmpty = true; // 文件为空
        ifs.close();
    }
	
	// 文件不为空
    int num = this->get_EmpNum();
	this->m_EmpNum = num; // 获取职工人数

    //开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum]; // 动态分配职工数组空间
	this->init_Emp(); // 初始化职工信息

}

void WorkerManager::Show_Menu()
{
	cout << "*******************************************" << endl;
	cout << "********** 欢迎使用职工管理系统 ***********" << endl;
	cout << "********** 1.添加职工信息 *****************" << endl;
	cout << "********** 2.显示职工信息 *****************" << endl;
	cout << "********** 3.删除职工信息 *****************" << endl;
	cout << "********** 4.修改职工信息 *****************" << endl;
	cout << "********** 5.查找职工信息 *****************" << endl;
	cout << "********** 6.排序职工信息 *****************" << endl;
	cout << "********** 7.清空职工信息 *****************" << endl;
	cout << "********** 0.退出职工管理系统 *************" << endl;
	cout << "*******************************************" << endl;

}

void WorkerManager::Exit_System()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); // 退出系统
}

void WorkerManager::Add_Emp()  
{  
    cout << "请输入添加职工的数量:" << endl;  
    int addNum = 0; // 添加职工的数量  
    cin >> addNum;  
    if (addNum > 0)  
    {  
        // 计算新空间大小  
        int newSize = this->m_EmpNum + addNum; // 新空间人数=原来人数+添加人数  

        // 开辟新空间  
        Worker** newSpace = new Worker*[newSize];  

        // 将原来空间的职工信息存入新空间  
        if (this->m_EmpArray != NULL)  
        {  
            for (int i = 0; i < this->m_EmpNum; i++)  
            {  
                newSpace[i] = this->m_EmpArray[i];  
            }  
        }  

        // 批量添加职工信息  
        for (int i = 0; i < addNum; i++)  
        {  
            int id; // 职工编号  
            string name; // 职工姓名  
            int dSelect; // 部门选择  

            cout << "请输入第" << i + 1 << "个新职工的编号:" << endl;  
            cin >> id;  
            cout << "请输入第" << i + 1 << "个新职工的姓名:" << endl;  
            cin >> name;  
            cout << "请选择该职工的部门:" << endl;  
            cout << "1.普通职工" << endl;  
            cout << "2.经理" << endl;  
            cout << "3.老板" << endl;  
            cin >> dSelect;  

            Worker* worker = NULL; // 创建一个职工对象指针  
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
                cout << "输入有误，请重新输入" << endl;  
                i--; // 让 i 回到当前职工  
                continue; // 跳过本次循环  
            }  

            // 检查边界条件，确保不会写入超出分配空间的内存  
            if (this->m_EmpNum + i < newSize)  
            {  
                newSpace[this->m_EmpNum + i] = worker;  
            }  
            else  
            {  
                cout << "发生错误: 超出分配空间的内存范围" << endl;  
                delete worker;  
                break;  
            }  
            
        }  

        // 释放原有空间  
        delete[] this->m_EmpArray;  

        // 更改新空间的指针  
        this->m_EmpArray = newSpace;  

        // 更新职工人数  
        this->m_EmpNum = newSize;  

        //成功添加后保存到文件中
        this->save();

		// 输出添加成功信息
        this->m_FileIsEmpty = false;
        cout << "成功添加" << addNum << "名新职工" << endl;  

        system("pause");
        system("cls");

    }  
    else  
    {  
        cout << "输入有误" << endl;  
    }  
    system("pause"); // 暂停屏幕
    system("cls"); // 清屏
}

void WorkerManager::save()
{
    ofstream ofs;
	ofs.open(FILENAME, ios::out);// 打开文件进行写入

	// 写入职工信息
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs<< this->m_EmpArray[i]->m_id << " "
            << this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_deptId << endl;
    }

	// 关闭文件
    ofs.close();
}

//统计职工人数
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
	ifs.open(FILENAME, ios::in); // 打开文件进行读取

    int id;
    string name;
    int dId;
    
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    return num; // 返回职工人数
}

//初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
	ifs.open(FILENAME, ios::in); // 打开文件进行读取

    int id;
    string name;
    int dId;
	int index = 0; // 用于记录职工数组的索引

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
		Worker* worker = NULL; // 创建一个职工对象指针
        switch (dId)
        {
        case 1: // 普通职工
            worker = new Employee(id, name, dId);
            break;
        case 2: // 经理
            worker = new Manager(id, name, dId);
            break;
        case 3: // 老板
            worker = new Boss(id, name, dId);
            break;
        default:
            cout << "输入有误，请重新输入" << endl;
            continue; // 跳过本次循环
		}
		this->m_EmpArray[index] = worker; // 将职工对象存入数组
        index++;
    }
	// 关闭文件
	ifs.close();

}

//显示职工信息
void WorkerManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
		cout << "文件不存在或文件为空" << endl;
    }
    else
    {
        for(int i=0;i< this->m_EmpNum; i++)
        {
			//利用多态调用虚函数
			this->m_EmpArray[i]->showInfo(); // 显示职工信息
		}
    }
	system("pause"); // 暂停屏幕
	system("cls"); // 清屏
}

//判断职工是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1; // 用于记录职工索引
    for (int i = 0; i < this->m_EmpNum; i++)  // 使用 m_EmpNum 作为循环次数
    {
        if (this->m_EmpArray[i] != nullptr && this->m_EmpArray[i]->m_id == id)
        {
            return i;  // 找到匹配 ID，返回索引
        }
    }
    return -1;
}

//删除职工信息
void WorkerManager::Del_Emp()
{
    if(m_FileIsEmpty)
    {
        cout << "文件不存在或文件为空，无法删除" << endl;
        return; // 直接返回，不需要继续执行
	}
    else
    {
        int id = 0;
        cout << "请输入要删除的职工编号:" << endl;
        cin >> id;
        int index = this->IsExist(id); // 判断职工是否存在
        if (index != -1)// 如果职工存在
        {
            // 删除职工信息
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1]; // 将后面的职工信息前移
            }
            this->m_EmpNum--; // 职工人数减一
            // 保存到文件中
            this->save();
            cout << "删除成功" << endl;
        }
        else // 如果职工不存在
        {
            cout << "职工不存在，删除失败" << endl;
		}
		system("pause"); // 暂停屏幕
		system("cls"); // 清屏
    }
}

//修改职工信息
void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
		cout << "文件不存在或文件为空，无法修改" << endl;
    }
    else
    {
		cout << "请输入要修改的职工编号:" << endl;
        int id = 0;
        cin >> id;
		int ret = this->IsExist(id); // 判断职工是否存在
        if (ret != -1)
        {
            int newId = 0; // 新职工编号
            string newName = ""; // 新职工姓名
            int newDeptId = 0; // 新部门编号
            cout << "查到职工信息如下:" << endl;
            this->m_EmpArray[ret]->showInfo(); // 显示原有职工信息
            delete this->m_EmpArray[ret]; // 释放原有职工对象的内存空间
            cout << "请输入新的职工编号:" << endl;
            cin >> newId;
            cout << "请输入新的职工姓名:" << endl;
            cin >> newName;
            cout << "请选择新的职工部门:" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> newDeptId;
            Worker* worker = NULL;
            switch (newDeptId)
            {
            case 1: // 普通职工
                worker = new Employee(newId, newName, newDeptId);
                break;
            case 2: // 经理
                worker = new Manager(newId, newName, newDeptId);
                break;
            case 3: // 老板
                worker = new Boss(newId, newName, newDeptId);
                break;
            default:
                break;
            }
            // 将新职工对象存入数组
			this->m_EmpArray[ret] = worker; // 更新职工信息
			cout << "修改成功" << endl;
			// 保存到文件中
            this->save();
        }
        else
            // 如果职工不存在
        {
            cout << "职工不存在，修改失败" << endl;
        }
    }
	system("pause"); // 暂停屏幕
	system("cls"); // 清屏
}

//查找职工信息
void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或文件为空，无法查找" << endl;
    }
    else
    {
		cout << "请输入查找方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
        if (select == 1) // 按职工编号查找
        {
            int id;
			cout << "请输入要查找的职工编号:" << endl;
            cin >> id;
			int ret = this->IsExist(id); // 判断职工是否存在
            if (ret != -1)
            {
                cout << "查找成功！" << endl;
                cout << "查找的职工信息如下:" << endl;
				this->m_EmpArray[ret]->showInfo(); // 显示职工信息
            }
            else
            {
				cout << "查找的职工不存在" << endl;
            }
        }

        else if (select == 2)
        {
            string name;
            cout<<"请输入要查找的职工姓名:" << endl;
            cin >> name;
			bool flag = false; // 用于标记是否找到职工
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL && this->m_EmpArray[i]->m_name == name)
                {
                    cout << "查找成功！" << endl;
					cout << "查找的职工信息如下:" << endl;
					this->m_EmpArray[i]->showInfo(); // 显示职工信息
					flag = true; // 找到职工
                }
            }
            if(!flag) // 如果没有找到职工
            {
                cout << "查找的职工不存在" << endl;
			}
        }

        else
        {
            cout << "输入有误，请重新输入" << endl;
			return; // 直接返回，不需要继续执行
        }
        system("pause"); // 暂停屏幕
        system("cls"); // 清屏

    }
}

//排序职工信息
void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
		cout << "文件不存在或为空，无法排序" << endl;
		system("pause"); // 暂停屏幕
        system("cls"); // 清屏
    }
    else
    {
		cout << "请选择排序方式:" << endl;
		cout << "1.按职工编号排序" << endl;
		cout << "2.按职工姓名排序" << endl;
		int select = 0;
        cin >> select;
        if (select == 1) //按照职工编号排序
        {
			cout << "请选择排序方式:" << endl;
			cout << "1.升序" << endl;
			cout << "2.降序" << endl;
			int order = 0;
			cin >> order;

            for (int i = 0; i < this->m_EmpNum; i++)
            {
				int minOrMax = i; // 记录最小或最大值的索引
                for (int j = i + 1; j < this ->m_EmpNum; j++)
                {
                    if (order == 1)
                    {
                        if(this->m_EmpArray[j]->m_id < this->m_EmpArray[minOrMax]->m_id)
                        {
                            minOrMax = j; // 找到更小的职工编号
						}
                    }
                    else
                    {
                        if (this->m_EmpArray[j]->m_id > this->m_EmpArray[minOrMax]->m_id)
                        {
                            minOrMax = j; // 找到更大的职工编号
                        }
                    }
                }
                if (minOrMax != i)
                {
					Worker* temp = this->m_EmpArray[i]; // 交换职工信息
                    this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
					this->m_EmpArray[minOrMax] = temp;
                }
            }
			cout << "职工信息按照职工编号排序成功" << endl;
			this->save(); // 保存到文件中
            system("pause"); // 暂停屏幕
            system("cls"); // 清屏
        }
        else if (select == 2) // 按照职工姓名排序
        {
            cout << "请选择排序方式:" << endl;
            cout << "1.升序" << endl;
            cout << "2.降序" << endl;
            int order = 0;
            cin >> order;
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                int minOrMax = i; // 记录最小或最大值的索引
                for (int j = i + 1; j < this ->m_EmpNum; j++)
                {
                    if (order == 1)
                    {
                        if (this->m_EmpArray[j]->m_name < this->m_EmpArray[minOrMax]->m_name)
                        {
                            minOrMax = j; // 找到更小的职工编号
                        }
                    }
                    else
                    {
                        if (this->m_EmpArray[j]->m_name > this->m_EmpArray[minOrMax]->m_name)
                        {
                            minOrMax = j; // 找到更大的职工编号
                        }
                    }
                }
                if (minOrMax != i)
                {
                    Worker* temp = this->m_EmpArray[i]; // 交换职工信息
                    this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                    this->m_EmpArray[minOrMax] = temp;
                }
            }
			cout << "职工信息按照职工姓名排序成功" << endl;
            this->save(); // 保存到文件中
            system("pause"); // 暂停屏幕
            system("cls"); // 清屏
        }
    }
}

//清空职工信息
void WorkerManager::Clean_File()
{
	cout << "确认清空所有职工信息吗？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	int select = 0;
	cin >> select;
    if (select == 1)
    {
        //清空文件
		ofstream ofs(FILENAME, ios::trunc);// 清除文件后重新创建
		ofs.close(); // 关闭文件
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i]; // 释放每个职工对象的内存空间
                    this->m_EmpArray[i] = NULL; // 避免悬空指针
                }
            }
            delete[] m_EmpArray; // 释放职工数组空间
            this->m_EmpArray = NULL; // 避免悬空指针
			this->m_EmpNum = 0; // 职工人数归零
            this->m_FileIsEmpty = true; // 文件为空
            cout << "清空成功" << endl;
        }
        else
        {
			cout << "文件已清空" << endl;
        }
    }
    else if (select == 2)
    {
		cout << "取消清空操作" << endl;
    }
    system("pause"); // 暂停屏幕
    system("cls"); // 清屏
}

//析构函数
WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        for(int i=0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i] != NULL)
            {
                delete this->m_EmpArray[i]; // 释放每个职工对象的内存空间
                this->m_EmpArray[i] = NULL; // 避免悬空指针
            }
		}
        delete[] m_EmpArray; // 释放职工数组空间
		this->m_EmpArray = NULL; // 避免悬空指针
    }
}


