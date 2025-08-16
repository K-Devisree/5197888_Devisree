Question: Reverse a doubly Linked List
This challenge is part of a tutorial track by MyCodeSchool

Given the pointer to the head node of a doubly linked list, reverse the order of the nodes in place. That is, change the next and prev pointers of the nodes so that the direction of the list is reversed. Return a reference to the head node of the reversed list.

Note: The head node might be NULL to indicate that the list is empty.

Solution:

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* temp = NULL;
    DoublyLinkedListNode* current = head;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        if (!current->prev) {
            head = current;
        }
        current = current->prev;
    }

    return head;
}
