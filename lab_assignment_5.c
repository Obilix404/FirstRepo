#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char         letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
    struct node* temp   = head;
    int          length = 0;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head) {
    int   var  = length(head);
    char* list = malloc(var + 1);
    int   i    = 0;
    while (head != NULL) {
        list[i++] = head->letter;
        head      = head->next;
    }
    list[i] = '\0';

    return list;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {
    struct node* temp = malloc(sizeof(node));
    temp->letter      = c;
    temp->next        = *pHead;
    *pHead            = temp;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead) {
    struct node* temp = *pHead;
    struct node* dVar;
    while (temp != NULL) {
        dVar = temp->next;
        free(temp);
        temp = dVar;
    }
}

int main(void) {
    int   i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char  c;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL) {
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);
}