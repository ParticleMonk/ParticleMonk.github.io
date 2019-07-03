#include "Library.h"
#include <vector>
#include <iostream>
using namespace std;

Library::Library(){}
Library::~Library(){}

//adds an employee to the vector employeeList
void Library::addEmployee(string name){
	Employee newEmployee(name);//calls the employee class to create a new instance of Employee passing name
	employeeList.push_back(newEmployee); //adds newely created employee ot the employeeList vector
}

/*
void Library::addEmployee(string name, int wait, int retain){ //created for testing sort function
	Employee newEmployee(name, wait, retain);
	employeeList.push_back(newEmployee); 
}
*/

// adds book to the bookList
void Library::addBook(string title){
	Book newBook(title); //calls the book class to create a new instance of Book passing title
	bookList.push_back(newBook); //adds newely created book to bookList vector
}
void Library::selection_sortVector(vector<Employee>& employeeList) { //code modified from class slides, original author unknown, overall complexity n^2
	for (int i = 0; i < employeeList.size(); ++i) { //iterates over the length of employeeList
		int pos_max = i;
		for (int next = i + 1; next < employeeList.size(); ++next) { //iteratres through to check the positions of each value
			if (employeeList.at(next).getEmployeePriority() > employeeList.at(pos_max).getEmployeePriority())
				pos_max = next;
		}
		if (employeeList.at(i).getEmployeePriority() != employeeList.at(pos_max).getEmployeePriority()) { //checks to see if value is in right position
			Employee temp = employeeList.at(pos_max); //creates a temporary instance of Employee at max
			employeeList.at(pos_max) = employeeList.at(i); //sets value at max equal to the currrent position
			employeeList.at(i) = temp; //sets value at i equal to the temp copy of pos_max
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
				bookList.at(i).setArchived(); //labels the book as archived
				archiveList.push_back(bookList.at(i)); //adds to a list of archived book titles
				bookList.erase(bookList.begin() + i); //removes the book from the bookList
			}
			for (int j = 0; j < employeeList.size(); ++j) {
				if (employeeList.at(j).getEmployeeName() == front) {
					employeeList.at(j).addRetain(days); //adds to the retain time for the employee
					employeeList.at(j).addHistory(title); //adds to the history of the book in regards of reatin time
				}
				else {
					bool already_read = false;
					for (int k = 0; k < employeeList.at(j).getHistory().size(); ++k) {
						if (employeeList.at(j).getHistory().at(k) == title) {
							already_read = true; //changes the status of employee has read or not to true
							break;
						}
					}
					if (!already_read) {
						employeeList.at(j).addWait(days); //adds the wait time for the next book
					}
				}
			}
		}
	}
	for (int i = 0; i < bookList.size(); ++i) { //for resetting the que after each priority update
		if (bookList.at(i).getBookName() != title && ((bookList.at(i).getDate() - passDate) > 0)) {
			selection_sortVector(employeeList); //sorts the PQ
			bookList.at(i).deleteQue();  //removes a book from the queue
			for (int j = 0; j < employeeList.size(); ++j) {
				bookList.at(i).setQue(employeeList.at(j).getEmployeeName()); //adds an employee to the queue
			}
		}
	}
}


