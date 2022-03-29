//Queue - Array based implementation.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QTYPE int
#define QUEUE_SIZE 5

typedef struct Queue {
	QTYPE data[QUEUE_SIZE];
	int front;
	int rear;
}Queue;

Queue* new_queue();
bool is_empty(Queue* queue);
bool is_full(Queue* queue);
void enqueue(Queue* queue, QTYPE value);
QTYPE dequeue(Queue* queue);
QTYPE front(Queue* queue);

int main(int argc, char** argv[]) {
	Queue* queue = new_queue();
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));

	enqueue(queue, 10);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	enqueue(queue, 20);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	enqueue(queue, 30);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	enqueue(queue, 40);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	enqueue(queue, 50);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	QTYPE x;
	x = dequeue(queue);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	x = dequeue(queue);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	x = dequeue(queue);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	x = dequeue(queue);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	x = dequeue(queue);
	printf("%d\n", is_empty(queue));
	printf("%d\n", is_full(queue));
	printf("%d\n", front(queue));

	return 0;
}

Queue* new_queue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = -1;
	queue->rear = -1;
	return queue;
}

bool is_empty(Queue* queue) {
	return queue->front == -1 && queue->rear == -1;
}

bool is_full(Queue* queue) {
	if(!is_empty(queue) && ((queue->front + QUEUE_SIZE - 1) % QUEUE_SIZE) != queue->rear)
		return false;
	return true;
}

void enqueue(Queue* queue, QTYPE value) {
	if(is_empty(queue)) {
		queue->front = 0;
		queue->rear = 0;
	} else if(!is_full(queue)) {
		queue->rear = (queue->rear + 1) % QUEUE_SIZE;
	} else {
		return;
	}
	queue->data[queue->rear] = value;
}

QTYPE front(Queue* queue) {
	if(is_empty(queue)) 
		return -1;
	return queue->data[queue->front];
}

QTYPE dequeue(Queue* queue) {
	if(is_empty(queue))
		return -1;
	if(queue->front == queue->rear) {
		QTYPE res = queue->data[queue->front];
		queue->front = -1;
		queue->rear = -1;
		return res;
	}
	QTYPE res = queue->data[queue->front];
	queue->front = (queue->front + 1) % QUEUE_SIZE;
	return res;
}