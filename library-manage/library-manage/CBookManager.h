#pragma once
#include <vector>
#include <string>
#include "CBook.h"
using namespace std;
class CBookManager
{
private:
	vector <CBook> bkarray;  //�洢ͼ����Ϣ
public:
	CBookManager();
	~CBookManager();
	void addbook(CBook book);    //���ͼ��
	int findbook(string name);  //����ͼ��
	int findbook(int code);  //����ͼ��
	CBook getbook(int subscript);
	void editbook(int subscript, CBook book);//�༭ͼ��
	void editbook(int subscript, int code);//�༭ͼ��
	void editbook(int subscript, string name);//�༭ͼ��
	void editbook(int subscript, bool Is_Stock);//�༭ͼ��
	void delbook(int subscript);   //ɾ��ͼ��
	void listbooks();  //��ʾȫ��ͼ��
	void save(string filename = "books.db"); // ���浽�ļ�
	void load(string filename = "books.db"); // ���ļ���ȡ
};