#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>

using namespace std;



class date {
public:
	date();
	string compare(string date);//comparing two different date instances and returns "greater", "less" or "equal" MAKE SURE TO COMPARE LARGER OF SECTION OF TIME FIRST
	void set_date(string date_s);//will take a date "02/28/2019" and fill in the appropriate attributes 
	date get_date();//return date in a string formate "XX/XX/XXXX"
	int get_difference(date incoming_date);//Returns the difference between passed date and selfdate
	string get_S_date();
private:
	int year, month, day;
};

date CreateDate(string date_incoming);

class employee {

public:
	employee(string employeeName) { name = employeeName, wait_time = 0, retain_time = 0, priority = 0; };
	//string compare();// Takes another employee and compares it to the current employee and returns "greater", "less" or "equal"	void set_retainer(int retainer) {retain_time = retainer ; };
	//unsure how to implement this yet, need to know how we plan on passing in employees to compare
	// my guess is that we need to pass in the employees name, pull their priority and then retun the name with the higher priority
	// vector<string> compare(list<employee> employeeList) {
		//iterate through the list
		// sort based on higest priority
		// return sorted vector, could also be a sorted list
	void set_wait(int newwait) { wait_time = newwait; };
	void set_retainer(int retainer) { retain_time = retainer; }
	void set_priority(int newpriority) { priority = newpriority; };
	void set_start(date startDate) { start.set_date(startDate.get_S_date()); };
	void set_book(string newBook) { book = newBook; };
	int get_priority() { return priority; };
	int get_retainer() { return retain_time; };
	int get_wait() { return wait_time; };
	date get_start_date() { return start; };
	string get_book() { return book; };
	string get_name() { return name; };
	bool has_read(string bookTitle); //Should search read vector and return true if book name is in it.
	void add_book_to_history(string bookTitle);




private:
	string name;
	date start;
	int wait_time, retain_time, priority;
	string book;
	vector<string> read;
};

employee NewEmployee(string newName);

class book {
public:
	book(string name, date dateIncoming);
	void use();//increments times_used
	void update_current(date newdate);//updates current date
	date get_current_date();//Returns the current date
	date get_start_date(); //Returns the start date
	string get_name();
	int get_usage();//returns usage

private:
	string name;
	date start_date, current_date;
	int times_used;
};

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
	void pass_on(string bookPass, date current_date);//updates retainer(employee.start-book.current_date) for current holding employee - sets prioirty for ncurrent holding employee - update book with current date - removes next employee from PQ, adds this employee to has_book and sets that emlpoyees wait(current_date- book.start_date) - returns the previous holding employee to PQ - increment use on book
	void archive_book(book bookChecked);// checks to see if book needs to be archives and if so move the book from list book_in_circ and put it in list archives
	void remove_employee(employee employeeBye); // Removes employee from the has_books list. 
};


