/* The methods regarding inserting, deleting, and arranging the list have been created utilizing 
FlowersHandsOn.cpp as a guide */
#include "stdafx.h"
#include "term.h"

int main()
{
	{
		linked_list* list = new linked_list();
		list->add_node("Continous-Integration", "Merging code changes into a shared repository several times a day.", 1993);
		list->add_node("Burndown-Chart", "Chart that tracks amount of output a team has completed across a project.", 2000);
		list->add_node("Customer-Development", "Four-step scientific approach to validate assumptions about your business.", 2005);
		list->add_node("Business-Agility", "Ability of an organization to sense changes and act efficiently and accordingly.", 1991);
		list->add_node("Epic", "Large user story.", 2004);
		list->add_node("INVEST", "Acronym for criteria used to assess quality of a user story.", 2003);
		list->add_node("Kanban", "Method used to manage flow for knowledge work.", 2004);
		list->add_node("Personas", "Synthetic biographies of fictious users.", 1999);
		list->add_node("Refactoring", "Improving the internal structure of a program while preserving its external behavior.", 1984);
		list->add_node("Scrum", "Process framework used to manage product development.", 1986);

		list->print_linked_list();
		list->search_node(list);

		delete list;
		list = nullptr;
	}

    return 0;
}
