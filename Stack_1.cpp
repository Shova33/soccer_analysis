//This program illustrates the use of basic stack operations

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

struct stack {
    int top;
    int items[STACKSIZE];
};

void push(struct stack* ps, int x);
int pop(struct stack* ps);
void display(struct stack* ps);

int main() {
    struct stack s;
    int i, x;
    char ch = 'y';
    char option;
    s.top = -1;

    while (ch == 'y' || ch == 'Y') {
        printf("\nWhich option do you want to choose?");
        printf("\n1. Push items to the stack");
        printf("\n2. Pop items from the stack");
        printf("\n3. Display stack contents");
        printf("\n4. Exit the program");
        printf("\nEnter your choice: ");
        scanf(" %c", &option); // Note the space before %c to consume any leftover whitespace

        switch (option) {
            case '1':
                printf("Enter the item to push into the stack: ");
                scanf("%d", &x);
                push(&s, x);
                break;
            case '2':
                i = pop(&s);
                printf("The popped item from the stack is %d\n", i);
                break;
            case '3':
                display(&s);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
        
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch); // Note the space before %c to consume any leftover whitespace
    }

    return 0;
}

void push(struct stack* ps, int x) {
    if (ps->top == STACKSIZE - 1) {
        printf("Stack overflow\n");
    } else {
        ps->items[++(ps->top)] = x;
    }
}

int pop(struct stack* ps) {
    if (ps->top == -1) {
        printf("Stack underflow\n");
        return -1; // Return a sentinel value to indicate stack underflow
    } else {
        return ps->items[(ps->top)--];
    }
}

void display(struct stack* ps) {
    int i;
    printf("The stack elements are:");
    for (i = ps->top; i >= 0; i--) {
        printf("\n%d", ps->items[i]);
    }
}

