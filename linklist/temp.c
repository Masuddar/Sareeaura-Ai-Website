#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct Node {
    int data;
    struct Node* next;  // Pointer to the next node in the stack
};

struct Node* top = NULL;  // Top of the stack

// Push a new element onto the stack
void push() {
    int element;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Create new node

    if (newNode == NULL) {
        printf("Stack Overflow! Not enough memory.\n");
        return;
    }

    printf("Enter the element to push: ");
    scanf("%d", &element);

    newNode->data = element;   // Assign value to new node
    newNode->next = top;       // Link new node to the previous top
    top = newNode;             // Update top to the new node

    printf("%d pushed into stack.\n", element);
}

// Pop the top element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        struct Node* temp = top;  // Temporary pointer to current top
        printf("%d popped from stack.\n", top->data);
        top = top->next;          // Move top to the next element
        free(temp);               // Free the old top
    }
}

// Show the top element of the stack
void printTop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Main function with a menu to interact with the stack
int main() {
    int choice;

    while (1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print Top");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                return 0;  // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
