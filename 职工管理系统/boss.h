#pragma once
#include <string>
#include <iostream>
#include "worker.h"
using namespace std;

// Boss��
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dId);

	//��ʾ��Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};
