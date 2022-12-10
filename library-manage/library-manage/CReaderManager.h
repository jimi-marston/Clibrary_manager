#pragma once
#include <vector>
#include <string>
#include "CReader.h"
using namespace std;
class CReaderManager
{
private:
	vector <CReader> rdarray;
public:
	CReaderManager();
	~CReaderManager();
	CReader getreader(int subscript);
	void addreader(CReader reader);          
	int findreader(string name); 
	int findreader(int code); 
	int findreader(CBook book); 
	void editreader(int subscript, CReader reader);
	void editreader(int subscript, string name); 
	void editreader(int subscript, int code); 
	void editreader(int subscript, CBook book); 
	void editreader(int subscript, bool Is_Borrowing); 
	void delreader(int subscript);          
	void listreaders();           
	void save(string filename = "readers.db"); 
	void load(string filename = "readers.db"); 
};