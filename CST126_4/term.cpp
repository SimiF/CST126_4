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

bool term_data::search_term(std::string n)
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
	std::cout << "Deleting..." << std::endl;

	term_data* temp;
	temp = head;

	while (temp != nullptr)
	{
		temp = temp->get_next();
		delete head;
		head = temp;
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

void linked_list::add_node(std::string n, std::string def, int year)
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

void linked_list::find_node(std::string n)
{
	term_data* temp;
	temp = head;

	bool found = false;

	while (temp != nullptr && found == false)
	{
		found = temp->search_term(n);
		if (found)
		{
			temp->print_searched_term();
		}
		else
		{
			temp = temp->get_next();
		}
	}
}