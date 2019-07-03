#include "Book.h"
using namespace std;

//creates a new instance of book (constructor)
Book::Book(string title)
{
	this->bookName = title; 
	archived = false; 
}

//book deconstructor
Book::~Book()
{
}

//creates the start date for the book 
void Book::setStartDate(Date startDate)
{
	circulationDate = startDate;
	endDate = startDate; 
}

//creates an end date for the book
void Book::setCurrentDate(Date passDate)
{
	endDate = passDate;
}

//adds teh book to the queue
void Book::setQue(string names)
{
		priorityQue.push(names); 
}

//removes a book from the queue and passes it out
string Book::popQue()
{
	string firstInLine = priorityQue.front(); 
	priorityQue.pop(); 
	return firstInLine; 
}

//removes all books from the queue
void Book::deleteQue()
{
	while (!priorityQue.empty()) {
		priorityQue.pop(); 
	}
}

//sets a book to be archived
void Book::setArchived()
{
	this->archived = true; 
}


