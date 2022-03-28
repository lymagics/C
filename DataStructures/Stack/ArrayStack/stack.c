//Stack - Array based implementation.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_DEPTH 1001
#define STYPE int

typedef struct Stack {
	STYPE array[STACK_DEPTH];
	int top;
}Stack;

Stack* new_stack();
STYPE get_top(Stack* stack);
bool is_empty(Stack* stack);
void push(Stack* stack, STYPE value);
STYPE pop(Stack* stack);

int main(int argc, char** argv[]) {
	Stack* stack = new_stack();
	printf("%d\n", is_empty(stack));
	printf("%d\n", get_top(stack));

	push(stack, 10);
	printf("%d\n", get_top(stack));

	push(stack, 2);
	printf("%d\n", get_top(stack));

	push(stack, 5);
	printf("%d\n", get_top(stack));

	int x;
	x = pop(stack);
	printf("%d\n", get_top(stack));

	x = pop(stack);
	printf("%d\n", get_top(stack));

	x = pop(stack);
	printf("%d\n", get_top(stack));

	return 0;
}

Stack* new_stack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	return stack;
}

bool is_empty(Stack* stack) {
	if(stack == NULL || stack->top == -1) {
		return true;
	}
	return false;
}

STYPE get_top(Stack* stack) {
	if(!is_empty(stack)) {
		return stack->array[stack->top];
	}
	return -1;
}

void push(Stack* stack, STYPE value) {
	if(stack->top+1 >= STACK_DEPTH) {
		printf("Error: Stack overflow.");
		return;
	}
	stack->array[++stack->top] = value;
}

STYPE pop(Stack* stack) {
	if(is_empty(stack)) {
		return -1;
	}
	return stack->array[stack->top--];
}