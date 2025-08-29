#include "linked_list.hpp"

#include <cstdio>

// ======== NODE ========
node::node() {
	this->val  = 0;
	this->next = NULL;
}

node::node(char val) {
	this->val  = val;
	this->next = NULL;
}

// ======== LINKED LIST ========

linked_list::linked_list() {
	this->head = NULL;
}

linked_list::linked_list(node* head) {
	this->head = head;
}

void linked_list::insert_at_head(char val) {
	if (head == NULL) {
		head	   = new node(val);
		head->next = NULL;
		return;
	}

	node* new_node = new node(val);

	new_node->next = head;
	head		   = new_node;
}

void linked_list::insert_back(char val) {
	if (head == NULL) {
		head	   = new node(val);
		head->next = NULL;
		return;
	}

	node* _node = head;
	while (_node != NULL) {
		if (_node->next == NULL) {
			// create new node

			node* new_node = new node(val);
			_node->next	   = new_node;
			break;
		}

		_node = _node->next;
	}
}

linked_list* linked_list::reverse_list() {
	node* it = this->head;

	linked_list* ll = new linked_list();

	while (it != NULL) {
		ll->insert_at_head(it->val);
		it = it->next;
	}

	return ll;
}

void linked_list::print_list() {
	node* it = this->head;

	while (it != NULL) {
		printf("%c ", it->val);
		it = it->next;
	}

	printf("\n");
}
