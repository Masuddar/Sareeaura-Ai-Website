#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push() {
    int element;
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &element);
        stack[++top] = element;
        printf("%d pushed into stack.\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

void printTop() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

void printStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print Top");
        printf("\n4. Print All");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printTop();
                break;
            case 4:
                printStack();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
