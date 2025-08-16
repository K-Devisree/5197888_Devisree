Question: Balanced Brackets

A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

By this logic, we say a sequence of brackets is balanced if the following conditions are met:

It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given  strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES. Otherwise, return NO.

Solution:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    char value;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void push(Stack* s, char c) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->value = c;
    node->next = s->top;
    s->top = node;
}

char pop(Stack* s) {
    if (!s->top) return 0;
    StackNode* temp = s->top;
    char val = temp->value;
    s->top = temp->next;
    free(temp);
    return val;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

char* isBalanced(char* s) {
    Stack st;
    st.top = NULL;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&st, c);
        } else {
            if (isEmpty(&st)) return "NO";
            char top = pop(&st);
            if (!isMatching(top, c)) return "NO";
        }
    }
    return isEmpty(&st) ? "YES" : "NO";
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[1001];
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }
    return 0;
}
