
#include "Header.h"

void Library::add_employee(employee employee)
{

	for (int i = 0; i < PQ.size(); i++)
	{
		
		if ((PQ.at(i).get_priority() >= employee.get_priority()) && ((i + 1) == PQ.size())) //For the case in which employee is the lowest priority
		{
			PQ.push_back(employee);//Add element to the back of the list.
			break;
		}
		if ((PQ.at(i).get_priority() <= employee.get_priority()) && (i == 0))//For the case in which employee is the highest priority
		{
			PQ.insert(PQ.begin(), employee);//add element to the front of the list.
			break;
		}
		if ((PQ.at(i).get_priority() <= employee.get_priority()) && (PQ.at(i + 1).get_priority() >= employee.get_priority()))//For the case in which employee is in the middle somewhere.
		{
			PQ.insert(PQ.begin() + i - 1, employee);//Looking for a way to insert items into a vector or list.
			break;
		}


	
	}
	num_employees = PQ.size() + has_books.size();
}

void Library::circulate_book(string bookIncoming, date start_date)
{
	book newBook(bookIncoming, start_date);//Creates BOOK
	book_in_circ.push_back(newBook);//Adds book to the circulation list

	//Next block of code selects the employee in the front of the que and intializes their wait, start date, and book name
	PQ.at(0).set_wait(newBook.get_start_date().get_difference(newBook.get_current_date()));
	PQ.at(0).set_start(start_date);
	PQ.at(0).set_book(bookIncoming);


	has_books.push_back(PQ.at(0));//Pushes the employee who now has a book onto the list. 
	PQ.erase(PQ.begin());//This may erase the entire vector POSSIBLE ERROR
}

void Library::pass_on(string bookPass, date current_date)
{
	for (employee employeeHB : has_books)
	{
		if (employeeHB.get_book() == bookPass)//Finds the employee who has the book needing to pass on.
		{
			for (book book : book_in_circ)
			{
				if (book.get_name() == bookPass)//Finds the book in the circ list that needs to be passed.
				{
					//Next block updates the attributes of the employee

					book.update_current(current_date);
					employeeHB.set_retainer(employeeHB.get_start_date().get_difference(book.get_current_date()));
					employeeHB.set_priority(employeeHB.get_wait() - employeeHB.get_retainer());

					//Next block updates the attributes of the book
					
					book.use();

					//Moves the employee from has_books to PQ
					this->add_employee(employeeHB);
					this->remove_employee(employeeHB);

					int i = 0;
					for (employee PQemployee : PQ)
					{
						if (!PQ.at(i).has_read(bookPass))
						{
							//Updates attributes for the employee next in line 
							PQ.at(i).set_wait(book.get_start_date().get_difference(book.get_current_date()));
							PQ.at(i).set_book(bookPass);
							PQ.at(i).add_book_to_history(bookPass);

						}
						i++;
					}
				
				
					//Moves the new employee from the line into the has_books list
					has_books.push_back(PQ.at(i));
					PQ.erase(PQ.begin()+i);

					//Checks to see if the book needs to now be archived
					this->archive_book(book);
					break;
				}
			}
			break;
			
		}
	}
	
}

void Library::archive_book(book bookChecked)
{
	if (bookChecked.get_usage() == num_employees) //Determines if the book has been passed to all employees.
	{
		list<book>::iterator shelfIt;
		shelfIt = book_in_circ.begin();
		for (book shelfBook : book_in_circ)
		{
			if (shelfBook.get_name() == bookChecked.get_name())//Goes through the circ books looking for the book to be archived
			{
				//Adds the book to archive and removes it from the shelf
				archives.push_back(shelfBook);
				book_in_circ.erase(shelfIt);
				break;
			}
			shelfIt++;
		}
	}
}

void Library::remove_employee(employee employeeBye)
{
	list<employee>::iterator currentEmployeeIT;
	currentEmployeeIT = has_books.begin();
	for (employee currentEmployee : has_books)
	{
		if (currentEmployee.get_name() == employeeBye.get_name())//Finds employee within has__books and removes them.
		{
			has_books.erase(currentEmployeeIT);
			break;
		}
		currentEmployeeIT++;
	}
}
