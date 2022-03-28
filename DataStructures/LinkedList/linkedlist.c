#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

Node* create_list(LTYPE data) {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = data;
	head->next = NULL;
	return head;
}

void print_list(Node* head) {
	if(head == NULL) {
		printf("[]\n");
		return;
	}
	printf("[");
	while(head->next != NULL) {
		printf("%d, ", head->data);
		head = head->next;
	}
	printf("%d]\n", head->data);
}

void push_list(Node* head, LTYPE data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;

	while(head->next != NULL) {
		head = head->next;
	}
	head->next = temp;
}

LTYPE pop_list(Node** head) {
	Node* element_to_del = (*head)->next;
	Node* before_del = (*head);

	if(element_to_del == NULL) { // In case of poping first element(which is the last also).
		LTYPE res = (*head)->data;
		*head = NULL;
		return res;
	}

	while(element_to_del->next != NULL) {
		element_to_del = element_to_del->next;
		before_del = before_del->next;
	}

	LTYPE res = element_to_del->data;
	before_del->next = NULL;
	free(element_to_del);
	return res;
}

Node* insert_node(Node* head, LTYPE data, int index) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;

	if(index == 0) {
		new_node->next = head;
		head = new_node;
		return head;
	}

	Node* temp = head;
	int i;
	for(i = 0; i<index-1; ++i) {
		assert(temp != NULL); // Check if index is out of range.
		temp = temp->next;
	}
	new_node->next = temp->next;
	temp->next = new_node;
	return head;
}

int get_element_by_value(Node* head, LTYPE value) {
	int i = 0;
	while(head != NULL) {
		if(head->data == value) {
			return i;
		}
		i++;
		head = head->next;
	}
	return -1;
}

LTYPE get_element_by_index(Node* head, int index) {
	int i = 0;
	while(head != NULL) {
		if(i == index) {
			return head->data;
		}
		i++;
		head = head->next;
	}
	return -1;
}

Node* delete_node_by_index(Node* head, int index) {
	Node* element_to_del = head->next;
	Node* before_del = head;

	if(index == 0) {
		head = element_to_del;
		return head;
	}

	int i;
	for(i = 0; i<index-1; ++i) {
		assert(element_to_del != NULL); 
		element_to_del = element_to_del->next;
		before_del = before_del->next;
	}
	before_del->next = element_to_del->next;
	free(element_to_del);
	return head;
}

Node* delete_node_by_value(Node* head, LTYPE value) {
	Node* element_to_del = head->next;
	Node* before_del = head;

	if(head->data == value) {
		head = head->next;
		free(before_del);
		return head;
	}

	while(element_to_del != NULL) {
		if(element_to_del->data == value) {
			before_del->next = element_to_del->next;
			free(element_to_del);
			return head;
		}
		element_to_del = element_to_del->next;
		before_del = before_del->next;
	}
	return head;
}

Node* delete_list(Node* head) {
	while(head != NULL) {
		Node* temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}

Node* reverse_list(Node* head) {
	Node* current, *prev, *next;
	current = head;
	prev = NULL;

	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

void reverse_recursive(Node** head, Node* p) {
	if(p == NULL) {
		return;
	}
	if(p->next == NULL) {
		*head = p;
		return;
	}
	reverse_recursive(head, p->next);
	p->next->next = p;
	p->next = NULL;
}