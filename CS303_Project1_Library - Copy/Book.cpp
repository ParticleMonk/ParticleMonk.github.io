#include "Book.h"
using namespace std;


Book::Book(string title)
{
	this->bookName = title; 
	archived = false; 
}


Book::~Book()
{
}

void Book::setStartDate(Date startDate)
{
	circulationDate = startDate;
	endDate = startDate; 
}

void Book::setCurrentDate(Date passDate)
{
	endDate = passDate;
}

void Book::setQue(string names)
{
		priorityQue.push(names); 
}

string Book::popQue()
{
	string firstInLine = priorityQue.front(); 
	priorityQue.pop(); 
	return firstInLine; 
}

void Book::deleteQue()
{
	while (!priorityQue.empty()) {
		priorityQue.pop(); 
	}
}

void Book::setArchived()
{
	this->archived = true; 
}


