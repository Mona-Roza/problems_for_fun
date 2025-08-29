
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class node {
   public:
	char val;
	node* next;

	node();

	node(char val);
};

class linked_list {
	node* head;

   public:
	linked_list();

	linked_list(node* head);

	void insert_at_head(char val);

	void insert_back(char val);

	linked_list* reverse_list();

	void print_list();
};

#endif