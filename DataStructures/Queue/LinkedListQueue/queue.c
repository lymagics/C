//Queue - LinkedList based implementation.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QTYPE int

typedef struct Node {
	QTYPE data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
}Queue;

Queue* new_queue();
bool is_empty(Queue* queue);
Queue* enqueue(Queue* queue, QTYPE value);
QTYPE dequeue(Queue** queue);
QTYPE front(Queue* queue);

int main(int argc, char** argv[]) {
	Queue* queue = new_queue();
	printf("%d\n", is_empty(queue));

	int x;
	queue = enqueue(queue, 1);
	x = front(queue);
	printf("%d\n", x);
	printf("%d\n", is_empty(queue));

	queue = enqueue(queue, 2);
	x = front(queue);
	printf("%d\n", x);
	printf("%d\n", is_empty(queue));

	queue = enqueue(queue, 3);
	x = front(queue);
	printf("%d\n", x);
	printf("%d\n", is_empty(queue));

	x = dequeue(&queue);
	printf("%d\n", x);
	x = front(queue);
	printf("%d\n", x);
	printf("%d\n", is_empty(queue));

	x = dequeue(&queue);
	printf("%d\n", x);
	x = front(queue);
	printf("%d\n", x);
	printf("%d\n", is_empty(queue));

	x = dequeue(&queue);
	printf("%d\n", x);
	x = front(queue);
	printf("%d\n", x);
	printf("%d\n", is_empty(queue));


	return 0;
}

Queue* new_queue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

bool is_empty(Queue* queue) {
	if(queue->front == NULL && queue->rear == NULL)
		return true;
	return false;
}

Queue* enqueue(Queue* queue, QTYPE value) {
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	if(is_empty(queue)) {
		temp->front = (Node*)malloc(sizeof(Node));
		temp->rear = temp->front;
		temp->front->data = value;
		return temp;
	}
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->next = NULL;
	temp1->data = value;
	queue->rear->next = temp1;
	queue->rear = temp1;
	return queue;
}

QTYPE dequeue(Queue** queue) {
	if(is_empty(*queue))
		return -1;
	if((*queue)->front == (*queue)->rear) {
		QTYPE res = (*queue)->front->data;
		(*queue)->front = (*queue)->rear = NULL;
		return res;
	}
	Node* temp_front = (*queue)->front;
	QTYPE res = (*queue)->front->data;
	(*queue)->front = (*queue)->front->next;
	free(temp_front);
	return res;
}

QTYPE front(Queue* queue) {
	if(is_empty(queue)) 
		return -1;
	return queue->front->data;
}