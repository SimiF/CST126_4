#include "stdafx.h"
#include "string"
#pragma once
/* according to https://en.wikipedia.org/wiki/Pragma_once pragma once does the same job as the include
directives but with advantages being that it's less code and potentially faster */

class term_data
{
public:
	term_data() { name = ""; definition = ""; year_used = 0; };
	term_data(std::string n, std::string def, int year) { name = n; definition = def; year_used = year; };
	void print_term_data();
	void search_term(std::string n);
private:
	std::string name;
	std::string definition;
	int year_used;
	term_data* next;
};

class node
{
public:
	void add_term();
	void print_term_info();
	void search_term();
};