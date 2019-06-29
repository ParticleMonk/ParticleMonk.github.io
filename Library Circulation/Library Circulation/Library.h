#pragma once
#include "Header.h"

class Library {
private:
	vector<employee> PQ;
	list<employee> has_books;
	list<book> book_in_circ;
	list<book> archives;
	int num_employees;


public:
	void add_employee(employee employee);//Adds a new employee to PQ in the right priority location
	void circulate_book(string bookIncoming, date start_date);//adds a new book to the list book_in_circ and gives it to the top employee in PQ and removes that employee to has_books - sets start for employee - sets wait for employee
	void pass_on(string bookPass, string newEmployee, date current_date);//updates retainer(employee.start-book.current_date) for current holding employee - sets prioirty for ncurrent holding employee - update book with current date - removes next employee from PQ, adds this employee to has_book and sets that emlpoyees wait(current_date- book.start_date) - returns the previous holding employee to PQ - increment use on book
	void archive_book(book bookChecked);// checks to see if book needs to be archives and if so move the book from list book_in_circ and put it in list archives
	void remove_employee(employee employeeBye); // Removes employee from the has_books list. 
};
