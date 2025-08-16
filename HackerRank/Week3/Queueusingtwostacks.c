Question: Queue using two stacks

A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting the longest) is always the first one to be removed.

A basic queue has the following operations:

Enqueue: add a new element to the end of the queue.
Dequeue: remove the element from the front of the queue and return it.
In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.

Solution:

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void push(Stack* s, int val) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->value = val;
    node->next = s->top;
    s->top = node;
}

int pop(Stack* s) {
    if (!s->top) return -1;
    StackNode* temp = s->top;
    int val = temp->value;
    s->top = temp->next;
    free(temp);
    return val;
}

int peek(Stack* s) {
    return s->top ? s->top->value : -1;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

typedef struct {
    Stack stackIn;
    Stack stackOut;
} Queue;

void enqueue(Queue* q, int val) {
    push(&q->stackIn, val);
}

void dequeue(Queue* q) {
    if (isEmpty(&q->stackOut)) {
        while (!isEmpty(&q->stackIn)) {
            push(&q->stackOut, pop(&q->stackIn));
        }
    }
    if (!isEmpty(&q->stackOut)) {
        pop(&q->stackOut);
    }
}

int front(Queue* q) {
    if (isEmpty(&q->stackOut)) {
        while (!isEmpty(&q->stackIn)) {
            push(&q->stackOut, pop(&q->stackIn));
        }
    }
    return peek(&q->stackOut);
}

int main() {
    int queries;
    scanf("%d", &queries);

    Queue q;
    q.stackIn.top = NULL;
    q.stackOut.top = NULL;

    for (int i = 0; i < queries; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int val;
            scanf("%d", &val);
            enqueue(&q, val);
        } else if (type == 2) {
            dequeue(&q);
        } else if (type == 3) {
            printf("%d\n", front(&q));
        }
    }

    return 0;
}
