#include "Employee.h"
using namespace std;


Employee::Employee(string name) {
	this->name = name;
	waitTime = 0; 
	retainTime = 0;
	read = false; 
}
Employee::~Employee()
{
}


void Employee::addWait(int days)
{
	waitTime += days; 
}

void Employee::addRetain(int days)
{
	retainTime += days; 
}

void Employee::readBook()
{
	read = true; 
}

void Employee::addHistory(string title)
{
	bookHistory.push_back(title);
}

