#include <stdio.h>
#include <stdlib.h>

#define LTYPE int

typedef struct Node {
	LTYPE data;
	struct Node* prev;
	struct Node* next;
}Node;

Node* new_list(LTYPE value);
Node* insert_to_head(Node* head, LTYPE value);
void print_list(Node* head);
void reverse_print(Node* head);
Node* insert_to_tail(Node* head, LTYPE value);
Node* delete_list(Node* head);

int main(int argc, char** argv[]) {
	Node* head = new_list(3);
	head = insert_to_head(head, 2);
	head = insert_to_head(head, 1);
	head = insert_to_tail(head, 4);
	head = insert_to_tail(head, 5);

	print_list(head);
	reverse_print(head);
	head = delete_list(head);
	print_list(head);
	return 0;
}

Node* new_list(LTYPE value) {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = value;
	head->prev = NULL;
	head->next = NULL;
	return head;
}

Node* insert_to_head(Node* head, LTYPE value) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->prev = NULL;
	temp->next = NULL;
	
	if(head == NULL) {
		head = temp;
		return head;
	}
	temp->next = head;
	head->prev = temp;
	head = temp;
	return head;
}

void print_list(Node* head) {
	if(head == NULL) {
		printf("[]");
		return;
	}
	printf("[");
	while(head->next != NULL) {
		printf("%d, ", head->data);
		head = head->next;
	}
	printf("%d]\n", head->data);
}

void reverse_print(Node* head) {
	if(head == NULL) {
		printf("[]");
		return;
	}
	while(head->next != NULL) {
		head = head->next;
	}
	printf("[");
	while(head->prev != NULL) {
		printf("%d, ", head->data);
		head = head->prev;
	}
	printf("%d]\n", head->data);
}

Node* insert_to_tail(Node* head, LTYPE value) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if(head == NULL) {
		head = new_node;
		return head;
	}

	Node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;

	return head;
}

Node* delete_list(Node* head) {
	if(head == NULL) {
		return NULL;
	}
	Node* current, *next, *prev;
	current = head;
	prev = NULL;

	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	return NULL;

}