//Stack - LinkedList based implementation.
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

#define STYPE int

typedef struct Node {
	STYPE data;
	struct Node* next;
}Node;

bool is_empty(Node* stack);
Node* push(Node* stack, STYPE data);
STYPE pop(Node** stack);
STYPE get_top(Node* stack);

int main(int argc, char** argv[]) {
	Node* stack = NULL;
	stack = push(stack, 10);
	printf("%d\n", get_top(stack));

	stack = push(stack, 5);
	printf("%d\n", get_top(stack));

	stack = push(stack, 0);
	printf("%d\n", get_top(stack));

	int x;
	x = pop(&stack);
	printf("%d\n", get_top(stack));

	x = pop(&stack);
	printf("%d\n", get_top(stack));

	x = pop(&stack);
	printf("%d\n", get_top(stack));

	printf("%d", is_empty(stack));
	return 0;
}

bool is_empty(Node* stack) {
	return stack == NULL;
}

Node* push(Node* stack, STYPE data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;

	if(is_empty(stack)) {
		stack = new_node;
		return stack;
	}

	new_node->next = stack;
	stack = new_node;
	return new_node;
}

STYPE get_top(Node* stack) {
	if(is_empty(stack)) {
		return -1;
	}
	return stack->data;
}

STYPE pop(Node** stack) {
	if(is_empty(*stack)) {
		return -1;
	}
	STYPE res = (*stack)->data;
	Node* temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	return res;
}