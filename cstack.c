#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX],i,j;
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
}

// Function to pop the top element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

// Function to search for an element in the stack
void search(int value) {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    for (i = top; i >= 0; i--) {
        if (stack[i] == value) {
            printf("%d found at position %d from bottom (position %d from top).\n", value, i + 1, top - i + 1);
            return;
        }
    }
    printf("%d not found in the stack.\n", value);
}

// Function to delete a specific element from the stack
void delete(int value) {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    int i, found = 0;
    // Search the element from top to bottom
    for (i = top; i >= 0; i--) {
        if (stack[i] == value) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%d not found in the stack.\n", value);
        return;
    }

    // Shift elements to delete the element at index i
    for (j = i; j < top; j++) {
        stack[j] = stack[j + 1];
    }
    top--;
    printf("%d deleted from the stack.\n", value);
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for ( i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Search\n4. Delete\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

