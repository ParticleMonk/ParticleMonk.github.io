#pragma once
#include <vector>
#include <list>
#include "Employee.h"
#include "Book.h"

using namespace std;
class Library
{
public:
	Library();
	~Library();
	void addEmployee(string name);
	void addEmployee(string name, int wait, int retain); 
	void addBook(string title); 
	void selection_sortVector(vector<Employee>& employeeList);
	void circulateBook(string title, Date startDate);
	void passOn(string title, Date passDate); 

private:
	vector<Employee> employeeList;
	vector<Book> bookList;
	list <Book> archiveList;

};

