#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};


void insertAtBeginning(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;

    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }

    (*head) = newNode;
}

void printList(struct node* head) {
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(struct node **head, int key) {
    struct node *temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main(int argc, char const *argv[]) {
    struct node *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);

    printf("Doubly linked list: ");
    printList(head);

    deleteNode(&head, 20);
    printf("Doubly linked list after deletion: ");
    printList(head);

    return 0;
}