#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void push(int a);
void pop();
void display();

int stack[SIZE], top = -1;

void main() {
    int value, choice;

    while(1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExited\n");
                exit(0);

            default:
                printf("\nWrong Choice\n");
        }
    }
}

void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack is full\n");
    } else {
        top++;
        stack[top] = value;
        printf("Inserted %d\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
