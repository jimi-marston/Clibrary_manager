#pragma once
#include <string>
using namespace std;
class CUser
{
protected:
	int code;      //��ʾ�û���ţ�
	string name;  //��ʾ�û�����
public:
	CUser();   // Ĭ�Ϲ��캯��
	CUser(int id, string na);   //���캯������ʼ���û���Ϣ
	void setcode(int n);      //���������û����
	int getcode();          //������ȡ�û����
	void setname(string na);  //���������û�����
	string  getname();        //������ȡ�û�����
	void show();           //������ʾ�û��Ļ�����Ϣ
};