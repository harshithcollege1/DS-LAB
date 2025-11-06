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
void insertAtBegin(struct node **head,int value){
    struct node *newnode = Createnode(value);
    newnode -> next = *head;
    *head = newnode;
}
void insertAtEnd(struct node ** head,int value){
    struct node * newnode = Createnode(value);
    if(*head == NULL){
        *head = newnode;
        return;

    }
    struct node *temp= * head;
    while(temp-> next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertAtPosition(struct node** head,int value,int position){
    struct node * newnode = Createnode(value);
    if(*head == NULL){
        *head = newnode;
        return;
    }
    struct node * temp = *head;
    for (int i = 1; i < position-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position out of Range.\n");
        free(newnode);
    }
    else{
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}
int main(){
    struct node *head = NULL;
    int choice,value,position;
    printf("1.Insert at Begining\n");
    printf("2.Insert at End\n");
    printf("3.Insert at Any POsition \n");
    printf("4.Display\n");
    printf("5.Exit\n");
    while(1){
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert :");
            scanf("%d",&value);
            insertAtBegin(&head,value);
            break;
        case 2:
            printf("Enter value to insert :");
            scanf("%d",&value);
            insertAtEnd(&head,value);
            break;    
        case 3:
            printf("Enter value to insert :");
            scanf("%d",&value);
            printf("Enter position :");
            scanf("%d",&position);
            insertAtPosition(&head,value,position);
            break;
        case 4:
            display(head);
            break;
        case 5:
            printf("Exiting..\n");
            exit(0);
        default:
            printf("Invalid Choice!\n");
            break;
        }
    }
}