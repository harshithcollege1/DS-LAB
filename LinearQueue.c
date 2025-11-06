#include <stdio.h>
#define Max 5
int queue[Max];
int item;
int front=-1, rear=-1;
void insert(){
    if(rear == Max-1){
        printf("\nQueue Overflow!");
    }
    else{
        if(front == -1 && rear ==-1) front = 0;
        printf("Enter your element to insert :");
        scanf("%d",&item);
        rear++;
        queue[rear] = item;
    }
}
void delete(){
    if(front == -1 && rear == -1 || front > rear){
        printf("\nQueue Underflow!");
    }
    else{
        printf("\nDeleted %d",queue[front]);
        front++;
    }
}
void display(){
    if(front == -1 && rear == -1 || front > rear){
        printf("Queue is Empty!");
    }
    else{
        printf("Queue elements :");
        for(int i = front;i <= rear;i++){
            printf("%d ",queue[i]);
        }
    }
}

int main(){
    int choice;
    do{
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4 :
            printf("Exiting...\n");
            break;
        default :
            printf("Invalid Choice!");
        }
    }while(choice != 4);
    return 0;
}
