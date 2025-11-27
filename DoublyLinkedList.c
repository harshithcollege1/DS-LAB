#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
void insertEnd(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void insertLeft(int target, int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (!temp) {
        printf("Target value %d not found.\n", target);
        return;
    }

    struct Node *newNode = createNode(value);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev)
        temp->prev->next = newNode;
    else
        head = newNode;
    temp->prev = newNode;
    printf("Inserted %d to the left of %d\n", value, target);
}
void deleteValue(int value) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (!temp) {
        printf("Value %d not found.\n", value);
        return;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    printf("Deleted %d\n", value);
    free(temp);
}
void display() {
    struct Node *temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, value, target;
    while (1) {
        printf("\n Doubly Linked List Menu \n");
        printf("1. Insert at End\n");
        printf("2. Insert to the Left of Node\n");
        printf("3. Delete by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 2:
                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertLeft(target, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}