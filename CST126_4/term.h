#include "stdafx.h"
#include "string"
#pragma once
/* according to https://en.wikipedia.org/wiki/Pragma_once pragma once does the same job as the include
directives but with advantages being that it's less code and potentially faster */

class term_data
{
public:
	term_data() { name = ""; definition = ""; year_used = 0; next = nullptr; };
	term_data(std::string n, std::string def, int year) { name = n; definition = def; year_used = year; };
	std::string get_name() { return name; };
	void print_term_data();
	void print_searched_term();
	bool search_term(std::string n);
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
	void add_node(std::string n, std::string def, int year);
	void find_node_and_print(std::string n);
	void search_and_destroy(linked_list* ptr);
private:
	term_data* head;
};