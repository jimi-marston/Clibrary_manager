#pragma once
#include "CBook.h"
#include "CUser.h"
using namespace std;
class CReader : public CUser
{
private:
	bool Is_Existing;  //true���ڣ�falseɾ��
	bool Is_Borrowing;  //true����飬falseû�н���
	CBook brbook;     //��ʾ���������ͼ��
public:
	CReader();               //Ĭ�ϵĹ��캯��
	CReader(int id, string na);   //���캯������ʼ��������Ϣ
	bool get_Existing();        //������ȡɾ����־
	void set_Existing(bool);     //��������ɾ����־
	bool get_Borrowing();      //������ȡ���߽������
	void set_Borrowing(bool);   //�������ö��߽������
	void setbrbook(CBook bt);  //������¼���߽�����Ϣ
	CBook getbrbook();		//������ȡ���߽�����Ϣ
	void show();			//��д�����Ա����ʾ���ߵĻ�����Ϣ����ͽ������
};