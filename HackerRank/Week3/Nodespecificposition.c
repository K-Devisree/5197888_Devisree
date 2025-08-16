Question: Node specific position

This challenge is part of a tutorial track by MyCodeSchool and is accompanied by a video lesson.

Given the pointer to the head node of a linked list and an integer to insert at a certain position, create a new node with the given integer as its  attribute, insert this node at the desired position and return the head node.

A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. The head pointer given may be null meaning that the initial list is empty.

Solution:

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int value, int pos) {
    SinglyLinkedListNode* newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    SinglyLinkedListNode* walker = head;
    for (int i = 0; i < pos - 1 && walker != NULL; i++) {
        walker = walker->next;
    }

    if (walker) {
        newNode->next = walker->next;
        walker->next = newNode;
    }

    return head;
}
