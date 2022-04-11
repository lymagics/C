#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#define LTYPE int

typedef struct Node {
	LTYPE data;
	struct Node* next;
}Node;

extern Node* create_list(LTYPE data);
extern void print_list(Node* head);
extern void push_list(Node* head, LTYPE data);
extern LTYPE pop_list(Node** head);
extern Node* insert_node(Node* head, LTYPE data, int index);
extern int get_element_by_value(Node* head, LTYPE value);
extern LTYPE get_element_by_index(Node* head, int index);
extern Node* delete_node_by_index(Node* head, int index);
extern Node* delete_node_by_value(Node* head, LTYPE value);
extern Node* delete_list(Node* head);
extern Node* reverse_list(Node* head);
extern void reverse_recursive(Node** head, Node* p);

#endif // __LINKED_LIST_H