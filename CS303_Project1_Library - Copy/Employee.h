#pragma once
#include <string>
#include <vector>
using namespace std;
class Employee
{
public:
	Employee() { name = "none", waitTime = 0, retainTime = 0, read = false; };
	~Employee();
	Employee(string name);
	Employee(string name, int wait, int retain) { this->name = name, this->waitTime = wait, this->retainTime = retain, read = false; };
	string getEmployeeName() { return name; };
	int getEmployeePriority() { return waitTime - retainTime; };
	int getEmployeeWaitTime() { return waitTime; };
	int getEmployeeRetainTime() { return retainTime; };
	void addWait(int days); 
	void addRetain(int days);
	bool hasRead() { return read; }; 
	void readBook(); 
	void addHistory(string title); 
	vector<string> getHistory() { return bookHistory; };

private:
	string name;
	int waitTime;
	int retainTime;
	bool read; 
	vector<string> bookHistory; 

};

