#pragma once
#include <string>
using namespace std;
class CBook
{
private:
	int code;              //ͼ����
	string name;     //ͼ������
	bool Is_Stock;          //trueΪ�ڼܣ�falseΪ���
	bool Is_Existing;       //trueΪ����, falseΪɾ��
public:
	CBook(); //Ĭ�Ϲ��캯��
	CBook(int co, string na);    //���캯������ʼ��ͼ����Ϣ
	void setcode(int n);   //����ͼ����
	int getcode();    //��ȡͼ����
	void setname(string na);    //����ͼ������
	string getname();  //��ȡͼ������
	bool  get_Stock();  //��ȡͼ���Ƿ��ڿ���Ϣ
	void set_Stock(bool is);// ����ͼ���Ƿ��ڿ���Ϣ
	bool  get_Existing();//��ȡ���ڱ�־
	void set_Existing(bool is);//���ô��ڱ�־
	void show();
};