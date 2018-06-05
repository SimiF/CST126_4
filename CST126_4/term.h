#include "stdafx.h"
#include "string"
#pragma once
/* according to https://en.wikipedia.org/wiki/Pragma_once pragma once does the same job as the include
directives but with advantages being that it's less code and potentially faster */

class term_data
{
public:
	term_data() { name = ""; definition = ""; year_used = 0; next = nullptr; };
	term_data(const std::string & n, const std::string & def, const int & year) { name = n; definition = def; year_used = year; };
	std::string get_name() { return name; };
	void print_term_data();
	void print_searched_term();
	bool search_term(const std::string & n);
	void update_next(term_data* ptr) { next = ptr; };
	term_data* get_next() { return next; };
private:
	std::string name;
	std::string definition;
	int year_used;
	term_data* next;
};

class linked_list
{
public:
	linked_list() { head = nullptr; };
	~linked_list();
	void print_linked_list();
	void add_node(const std::string & n, const std::string & def, const int & year);
	void find_node_and_print(const std::string & n);
	void search_node(linked_list* ptr);
private:
	term_data* head;
};