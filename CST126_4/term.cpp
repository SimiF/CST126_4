#include "stdafx.h"
#include "term.h"
#include "iostream"
#include "iomanip"

void term_data::print_term_data()
{
	std::cout << std::right << std::setw(11) << name << ":" << std::left 
		      << std::setw(2) << definition << std::endl;
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
		delete head;
		temp = temp->get_next();
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
			temp->print_term_data();
		}
		else
		{
			temp = temp->get_next();
		}
	}
}