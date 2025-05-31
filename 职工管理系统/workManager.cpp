#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
	// 初始化属性
	this->m_EmpArray = NULL;

	this->m_EmpNum = 0;

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
	cout << "********** 6.按照编号排序 *****************" << endl;
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

        cout << "成功添加" << addNum << "名新职工" << endl;  
    }  
    else  
    {  
        cout << "输入有误" << endl;  
    }  
}
WorkerManager::~WorkerManager()
{

}