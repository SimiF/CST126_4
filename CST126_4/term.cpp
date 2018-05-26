#include "stdafx.h"
#include "term.h"
#include "iostream"
#include "iomanip"

void term_data::print_term_data()
{
	std::cout << std::right << std::setw(11) << name << ":" << std::left 
		      << std::setw(2) << definition << std::endl;
}

void term_data::search_term(std::string n)
{
	for (int i{ 10 }; i <= 10; i++)
	{

	}
}