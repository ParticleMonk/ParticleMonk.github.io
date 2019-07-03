#pragma once
#include <string>
#include <queue>
#include "Date.h"


using namespace std;
class Book
{
public:
	Book(string title);
	~Book();
	string getBookName() { return bookName; };
	void setStartDate(Date startDate);
	void setCurrentDate(Date currentDate);
	Date getDate() { return endDate; };
	queue<string> getQue() { return priorityQue; };
	void setQue(string names);
	string popQue(); 
	void deleteQue();
	void setArchived(); 

private: 
	string bookName; 
	Date circulationDate;
	Date endDate; 
	queue<string> priorityQue; 
	bool archived; 
};

