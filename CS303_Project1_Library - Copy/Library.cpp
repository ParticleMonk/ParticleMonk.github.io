#include "Library.h"
#include <vector>
#include <iostream>
using namespace std;

Library::Library(){}
Library::~Library(){}

void Library::addEmployee(string name){
	Employee newEmployee(name);
	employeeList.push_back(newEmployee); 
}
void Library::addEmployee(string name, int wait, int retain){ //created for testing sort function
	Employee newEmployee(name, wait, retain);
	employeeList.push_back(newEmployee); 
}
void Library::addBook(string title){
	Book newBook(title);
	bookList.push_back(newBook); 
}
void Library::selection_sortVector(vector<Employee>& employeeList) { //code modified from class slides, original author unknown 
	for (int i = 0; i < employeeList.size(); ++i) {
		int pos_max = i;
		for (int next = i + 1; next < employeeList.size(); ++next) {
			if (employeeList.at(next).getEmployeePriority() > employeeList.at(pos_max).getEmployeePriority())
				pos_max = next;
		}
		if (employeeList.at(i).getEmployeePriority() != employeeList.at(pos_max).getEmployeePriority()) {
			Employee temp = employeeList.at(pos_max);
			employeeList.at(pos_max) = employeeList.at(i);
			employeeList.at(i) = temp;
		}
	}
}


void Library::circulateBook(string title, Date startDate){

	selection_sortVector(employeeList); // sorts the employeees based on highest priority
	for (int i = 0; i < bookList.size(); ++i) { //iterates through the bookList, a library class vector
		if (bookList.at(i).getBookName() == title) { 
			bookList.at(i).setStartDate(startDate); 
			for (int j = 0; j < employeeList.size(); ++j) { //at this point the employees have been sorted on highest priority
				bookList.at(i).setQue(employeeList.at(j).getEmployeeName()); //a queue gets created for the book class 
			}
		}
	}
}

void Library::passOn(string title, Date passDate){
	int days = 0; 
	string front; 

	for (int i = 0; i < bookList.size(); ++i) { //iterates through vector, checks if there is a matching title
		if (bookList.at(i).getBookName() == title) {
			days = passDate - bookList.at(i).getDate(); //find how many days have passed
			bookList.at(i).setCurrentDate(passDate); //to keep track of the book objects current date 
			break;                                   // the next time the passOn method is called 
		}
	}
	for (int i = 0; i < bookList.size(); ++i) { //itereates through vector, checks if there is a matching title
		if (bookList.at(i).getBookName() == title) {
			if (bookList.at(i).getQue().empty()) { //in case an incorrect title was entered
				return;
			}
			front = bookList.at(i).popQue(); //popQue returns the name of the person in the front of the queue 
			if (bookList.at(i).getQue().empty()) { //when the que is empty the book will be archived
				bookList.at(i).setArchived(); //
				archiveList.push_back(bookList.at(i)); //adds to a list of archived book titles
				bookList.erase(bookList.begin() + i);
			}
			for (int j = 0; j < employeeList.size(); ++j) {
				if (employeeList.at(j).getEmployeeName() == front) {
					employeeList.at(j).addRetain(days);
					employeeList.at(j).addHistory(title);
				}
				else {
					bool already_read = false;
					for (int k = 0; k < employeeList.at(j).getHistory().size(); ++k) {
						if (employeeList.at(j).getHistory().at(k) == title) {
							already_read = true;
							break;
						}
					}
					if (!already_read) {
						employeeList.at(j).addWait(days);
					}
				}
			}
		}
	}
	for (int i = 0; i < bookList.size(); ++i) { //for resetting the que after each priority update
		if (bookList.at(i).getBookName() != title && ((bookList.at(i).getDate() - passDate) > 0)) {
			selection_sortVector(employeeList);
			bookList.at(i).deleteQue(); 
			for (int j = 0; j < employeeList.size(); ++j) {
				bookList.at(i).setQue(employeeList.at(j).getEmployeeName());
			}
		}
	}
}


