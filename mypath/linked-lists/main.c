#include <stdlib.h>
#include <stdio.h>

struct _node {
    int value;
    struct _node* next;
};
typedef struct _node Tnode;


void printLinkedList(Tnode *head)
{
    Tnode *temporary = head;

    while (temporary != NULL) {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

Tnode * createNewNode(int value)
{
    Tnode *result = malloc(sizeof(Tnode));
    result->value = value;
    result->next = NULL;
    return result;
}

Tnode * insertAtHead(Tnode **head, Tnode *node_to_insert) {
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

Tnode * findNode(Tnode *head, int value) {
    Tnode *tmp = head;
    
    while (tmp != NULL) {
        if (tmp->value == value) return tmp;
            tmp = tmp->next;
    }
    return NULL;
}

void insertAfterNode(Tnode *node_to_insert_after, Tnode* newnode) {
    newnode->next = node_to_insert_after->next;
    node_to_insert_after->next = newnode;
}



int main() 
{
    Tnode *head = NULL;
    Tnode *tmp;

    for (int i = 0; i < 25; i++) {
        tmp = createNewNode(i);
        insertAtHead(&head, tmp);
    }


    tmp = findNode(head, 13);
    printf("Found node with value %d\n", tmp->value);

    insertAfterNode(tmp, createNewNode(75));

    printLinkedList(head);

    return 0;
}
