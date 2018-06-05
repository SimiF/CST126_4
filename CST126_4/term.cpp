#include "stdafx.h"
#include "term.h"
#include "iostream"
#include "iomanip"

void term_data::print_term_data()
{
	std::cout << std::right << std::setw(21) << name << ":" << std::left 
		      << "  " << definition << std::endl;
}

void term_data::print_searched_term()
{
	std::cout << name << ":  " << definition << "  First used in " << year_used << std::endl;
}

bool term_data::search_term(const std::string & n)
{
	if (name == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

linked_list::~linked_list()
{
	std::cout << "Deleting list." << std::endl;

	term_data* temp;

	while (head != nullptr)
	{
		temp = head;
		head = head->get_next();
		delete temp;
	}
}

void linked_list::print_linked_list()
{
	term_data* temp;
	temp = head;

	while (temp != nullptr)
	{
		temp->print_term_data();
		temp = temp->get_next();
	}
}

void linked_list::add_node(const std::string & n, const std::string & def, const int & year)
{
	term_data* temp = new term_data(n, def, year);

	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		if (n < head->get_name())
		{
			temp->update_next(head);
			head = temp;
		}
		else
		{
			term_data* temp2 = head;
			term_data* prev = nullptr;

			while (temp2 != nullptr && (n > temp2->get_name()))
			{
				prev = temp2;
				temp2 = temp2->get_next();
			}

			prev->update_next(temp);
			temp->update_next(temp2);
		}
	}
}

void linked_list::find_node_and_print(const std::string & n)
{
	term_data* temp;
	temp = head;
	bool found{ false };

	while (temp != nullptr && found == false)
	{
		if(temp->search_term(n))
		{
			temp->print_searched_term();
			found = true;
		}
		else
		{
			temp = temp->get_next();
		}
	}

	if (found == false)
	{
		std::cout << "Your term has not been found." << std::endl;
	}
}

void linked_list::search_node(linked_list* ptr)
{
	bool loop{ true };
	while (loop)
	{
		std::cout << std::endl;
		std::string term;
		std::cout << "What term do you want? ";
		std::cin >> term;

		ptr->find_node_and_print(term);

		std::cout << std::endl;
		std::cout << std::endl;

		char answer;
		std::cout << "Do you want to continue? ";
		std::cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			loop = true;
		}
		else if (answer == 'n' || answer == 'N')
		{
			loop = false;
		}
	}
}