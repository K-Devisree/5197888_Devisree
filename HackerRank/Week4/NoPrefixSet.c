Question: No Prefix Set

There is a given list of strings where each string contains only lowercase letters from , inclusive. The set of strings is said to be a GOOD SET if no string is a prefix of another string. In this case, print GOOD SET. Otherwise, print BAD SET on the first line followed by the string being checked.

Note If two strings are identical, they are prefixes of each other.

Solution:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 10

struct TrieNode {
    int isEnd;
    struct TrieNode* children[ALPHABET];
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEnd = 0;
    for(int i = 0; i < ALPHABET; i++) node->children[i] = NULL;
    return node;
}

int insertWord(struct TrieNode* root, char* str) {
    struct TrieNode* current = root;
    int conflict = 0;
    for(int i = 0; str[i]; i++) {
        int index = str[i] - 'a';
        if(current->children[index] == NULL) current->children[index] = createNode();
        current = current->children[index];
        if(current->isEnd) conflict = 1;
    }
    for(int i = 0; i < ALPHABET; i++)
        if(current->children[i] != NULL) conflict = 1;
    current->isEnd = 1;
    return conflict;
}

int main() {
    int n;
    scanf("%d", &n);
    char word[1001];
    struct TrieNode* root = createNode();
    for(int i = 0; i < n; i++) {
        scanf("%s", word);
        if(insertWord(root, word)) {
            printf("BAD SET\n%s\n", word);
            return 0;
        }
    }
    printf("GOOD SET\n");
    return 0;
}
