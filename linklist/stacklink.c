#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push() {
    int element;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter the element to push: ");
    scanf("%d", &element);
    newNode->data = element;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", element);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
    } else {
        struct Node* temp = top;
        printf("%d popped from stack.\n", top->data);
        top = top->next;
        free(temp);
    }
}

void printTop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

void printStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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
