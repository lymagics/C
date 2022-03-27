#include "linkedlist.h"
#include <stdio.h>

int main(int argc, char** argv[]) {
	//Initialize list.
	Node* head = create_list(1);

	//Push values to the list.
	push_list(head, 2);
	push_list(head, 3);
	push_list(head, 4);
	push_list(head, 5);
	push_list(head, 6);
	push_list(head, 7);
	push_list(head, 8);

	//Print list.
	print_list(head);

	//Delete node by index.
	head = delete_node_by_index(head, 7);
	print_list(head); 

	//Delete node by value.
	head = delete_node_by_value(head, 1);
	print_list(head);

	//Reverse list.
	head = reverse_list(head);
	print_list(head);

	//Delete list from heap.
	head = delete_list(head);
	print_list(head);

	return 0;
}
