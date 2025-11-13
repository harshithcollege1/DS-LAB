#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *Createnode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = NULL;
    return newnode;
}
struct node *head = NULL;
void insertAtBegin(struct node **head,int value){
    struct node *newnode = Createnode(value);
    newnode -> next = *head;
    *head = newnode;
}
void deleteAtStart(){
    if(head == NULL){
        printf("List Empty!");
        return;
    }
    struct node* temp = head;
    head = temp ->next;
    free(temp);

}
void display(struct node *head){
    struct node* temp = head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("Linked List :");
    while(temp != NULL){
        printf("%d -> ",temp->data );
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    int choice, value, position;
    printf("LINKED LIST MENU\n");
    printf("1. Insert at Beginning\n");
    printf("2. Delete at Beginning\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBegin(&head, value);
                break;
            case 2:
                deleteAtStart();
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}