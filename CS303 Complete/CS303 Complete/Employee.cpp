#include "Employee.h"
using namespace std;

//employee constructor, sets name, waitTime, retainTime, and bool read
Employee::Employee(string name) {
	this->name = name;
	waitTime = 0; 
	retainTime = 0;
	read = false; 
}

//employee deconstructor
Employee::~Employee()
{
}

//adds to wait time based off of days passed in, what is passed is the retain time of the previous reader
void Employee::addWait(int days)
{
	waitTime += days; 
}

//adds to retain time based on days passed in, what is passed is how long the employee had the book
void Employee::addRetain(int days)
{
	retainTime += days; 
}

//sets read to true, sets to add to employees history
void Employee::readBook()
{
	read = true; 
}

//adds read books to employee history
void Employee::addHistory(string title)
{
	bookHistory.push_back(title);
}

