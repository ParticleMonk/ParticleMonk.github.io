#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>

using namespace std;

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
	void set_priority(int newpriority) { priority = newpriority; };
	void set_start(date startDate) { start = startDate; };
	void set_book(string newBook) { book = newBook; };
	int get_priority() { return priority; };
	int get_retainer() { return retain_time; };
	int get_wait() { return wait_time; };
	date get_start_date() { return start; };
	string get_book() { return book; };
	string get_name() { return name; };




private:
	string name;
	date start;
	int wait_time, retain_time, priority;
	string book;
};
