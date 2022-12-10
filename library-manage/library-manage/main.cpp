#include "CReader.h"
#include "CBook.h"
#include "CUser.h"
#include "CBookManager.h"
#include "CReaderManager.h"
#include <iostream>
CBookManager bookManager;
CReaderManager readerManager;
int landbook()
{
	string readerName, bookName;
	int readerSubscript, bookSubscript;
	cout << "�������������" << endl;
	cin >> readerName;
	readerSubscript = readerManager.findreader(readerName);
	if (readerSubscript == -1)
	{
		cout << "���߲�����" << endl;
		return 0;
	}
	cout << "�������鼮����" << endl;
	cin >> bookName;
	bookSubscript = bookManager.findbook(bookName);
	if (bookSubscript == -1)
	{
		cout << "�鼮������" << endl;
		return 0;
	}
	else if (bookSubscript == -2)
	{
		cout << "�鼮�ѽ��" << endl;
		return 0;
	}
	bookManager.editbook(bookSubscript, false);
	readerManager.editreader(readerSubscript, bookManager.getbook(bookSubscript));
	readerManager.editreader(readerSubscript, true);
	cout << "����ɹ�" << endl;
	return 0;
}
int returnbook()
{
	cout << "�������������" << endl;
	string readername;
	cin >> readername;
	int readersubscript = readerManager.findreader(readername);
	if (readersubscript == -1)
	{
		cout << "���߲�����" << endl;
		return 0;
	}
	CReader reader = readerManager.getreader(readersubscript);
	CBook book = reader.getbrbook();
	int booksubscript = bookManager.findbook(book.getname());
	if (booksubscript == -1)
	{
		cout << "�鲢���Ǳ��ݵ�" << endl;
		return 0;
	}
	bookManager.editbook(booksubscript, true);
	readerManager.editreader(readersubscript, false);
	return 0;
}

int bookcreate()
{
	CBook book;
	int code;
	string name;
	cout << "���������" << endl;
	cin >> code;
	cout << "����������" << endl;
	cin >> name;
	book.setcode(code);
	book.setname(name);
	bookManager.addbook(book);
	return 0;
}
int bookdelete()
{
	cout << "����������" << endl;
	string bookname;
	cin >> bookname;
	int booksubscript = bookManager.findbook(bookname);
	if (booksubscript == -1)
	{
		cout << "û���Ȿ��" << endl;
		return 0;
	}
	bookManager.delbook(booksubscript);
	cout << "ɾ���ɹ�" << endl;
	return 0;
}
int bookedit()
{
	cout << "����������" << endl;
	string bookname;
	cin >> bookname;
	int booksubscript = bookManager.findbook(bookname);
	if (booksubscript == -1)
	{
		cout << "û���Ȿ��" << endl;
		return 0;
	}
	int newbookcode;
	string newbookname;
	cout << "������������" << endl;
	cin >> newbookname;
	bookManager.editbook(booksubscript, newbookname);
	cout << "�����������" << endl;
	cin >> newbookcode;
	bookManager.editbook(booksubscript, newbookcode);
	cout << "���ĳɹ�" << endl;
	return 0;
}
int bookfind()
{
	cout << "1.����������" << endl << "2.����Ų���" << "�����˳�" << endl;
	int command;
	cin >> command;
	int booksubscript = -1;
	if (command == 1)
	{
		cout << "����������" << endl;
		string bookname;
		cin >> bookname;
		booksubscript = bookManager.findbook(bookname);
	}
	else if (command == 2)
	{
		cout << "���������" << endl;
		int bookcode;
		cin >> bookcode;
		booksubscript = bookManager.findbook(bookcode);
	}
	else
	{
		return 0;
	}
	if (booksubscript == -1)
	{
		cout << "û���Ȿ��" << endl;
		return 0;
	}
	CBook book = bookManager.getbook(booksubscript);
	book.show();
	return 0;
}
int booklist()
{
	bookManager.listbooks();
	return 0;
}
int bookmanage()
{
	cout << "1.����ͼ��" << endl;
	cout << "2.ɾ��ͼ��" << endl;
	cout << "3.����ͼ��" << endl;
	cout << "4.����ͼ��" << endl;
	cout << "5.��ʾͼ��" << endl;
	int command;
	cout << "������ָ��" << endl;
	cin >> command;
	switch (command)
	{
	case 1:
		bookcreate();
		break;
	case 2:
		bookdelete();
		break;
	case 3:
		bookedit();
		break;
	case 4:
		bookfind();
		break;
	case 5:
		booklist();
	default:
		return 0;
	}
	return 0;
}
int readercreate()
{
	int code;
	string name;
	CReader reader;
	cout << "��������" << endl;
	cin >> code;
	cout << "����������" << endl;
	cin >> name;
	reader.setcode(code);
	reader.setname(name);
	readerManager.addreader(reader);
	return 0;
}
int readerdelete()
{
	cout << "�������������" << endl;
	string readername;
	cin >> readername;
	int  readersubscript = readerManager.findreader(readername);
	if (readersubscript == -1)
	{
		cout << "û����λ����" << endl;
		return 0;
	}
	readerManager.delreader(readersubscript);
	cout << "ɾ���ɹ�" << endl;
	return 0;
}
int readeredit()
{
	cout << "�������������" << endl;
	string readername;
	cin >> readername;
	int readersubscript = readerManager.findreader(readername);
	if (readersubscript == -1)
	{
		cout << "û����λ����" << endl;
		return 0;
	}
	int newreadercode;
	string newreadername;
	cout << "�������¶�������" << endl;
	cin >> newreadername;
	readerManager.editreader(readersubscript, newreadername);
	cout << "�������¶��߱��" << endl;
	cin >> newreadercode;
	readerManager.editreader(readersubscript, newreadercode);
	cout << "���ĳɹ�" << endl;
	return 0;
}
int readerfind()
{
	cout << "1.����������" << endl << "2.����Ų���" << "�����˳�" << endl;
	int command;
	cin >> command;
	int readersubscript = -1;
	if (command == 1)
	{
		cout << "����������" << endl;
		string readername;
		cin >> readername;
		readersubscript = readerManager.findreader(readername);
	}
	else if (command == 2)
	{
		cout << "���������" << endl;
		int readercode;
		cin >> readercode;
		readersubscript = readerManager.findreader(readercode);
	}
	else
	{
		return 0;
	}
	if (readersubscript == -1)
	{
		cout << "û���Ȿ��" << endl;
		return 0;
	}
	CReader reader = readerManager.getreader(readersubscript);
	reader.show();
	return 0;
}
int readerlist()
{
	readerManager.listreaders();
	return 0;
}
int readermanage()
{
	cout << "1.���Ӷ���" << endl;
	cout << "2.ɾ������" << endl;
	cout << "3.���Ķ���" << endl;
	cout << "4.���Ҷ���" << endl;
	cout << "5.��ʾ����" << endl;
	int command;
	cout << "������ָ��" << endl;
	cin >> command;
	switch (command)
	{
	case 1:
		readercreate();
		break;
	case 2:
		readerdelete();
		break;
	case 3:
		readeredit();
		break;
	case 4:
		readerfind();
	case 5:
		readerlist();
		break;
	default:
		return 0;
	}
	return 0;
}
int filemanage()
{
	cout << "1.�ļ��洢" << endl << "2.�ļ���ȡ" << endl;
	int command;
	cin >> command;
	if (command == 1)
	{
		readerManager.save();
		bookManager.save();
		cout << "�Ѵ洢��books.db��readers.db��" << endl;
		return 0;
	}
	else if (command == 2)
	{
		readerManager.load();
		bookManager.load();
		cout << "�ļ��Ѷ�ȡ" << endl;
		bookManager.listbooks();
		cout << endl;
		readerManager.listreaders();
		return 0;
	}
	else
	{
		cout << "�ļ�δ����" << endl;
		return 1;
	}
	return 0;
}
int main()
{
	cout << "********************��ӭʹ��ͼ��ݹ���ϵͳ********************" << endl;
	bool flag = true;
	while (flag)
	{
		cout << "********************1.����********************" << endl;
		cout << "********************2.����********************" << endl;
		cout << "********************3.ͼ�����****************" << endl;
		cout << "********************4.���߹���****************" << endl;
		cout << "********************5.�ļ��洢****************" << endl;
		cout << "********************�����˳�******************" << endl;
		int command;
		cout << "������ָ��" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
			landbook();
			break;
		case 2:
			returnbook();
			break;
		case 3:
			bookmanage();
			break;
		case 4:
			readermanage();
			break;
		case 5:
			filemanage();
			break;
		default:
			flag = false;
		}
	}
	bookManager.save();
	readerManager.save();
	return 0;
}