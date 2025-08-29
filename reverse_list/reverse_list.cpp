#include "linked_list.hpp"

int main() {
	linked_list ll = linked_list();

	ll.insert_back('1');
	ll.insert_back('2');
	ll.insert_back('3');
	ll.insert_back('4');

	ll.print_list();

	linked_list* ll2 = ll.reverse_list();

	ll2->print_list();

	return 0;
}
