#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

void push(Stack *stack, char value) {
    if (!isFull(stack)) {
        stack->items[++(stack->top)] = value;
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[(stack->top)--];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isExpressionValid(const char *expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), ch)) {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}

int main() {
    char expression[MAX];

    printf("Nhap bieu thuc: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0';

    if (isExpressionValid(expression)) {
        printf("Bieu thuc hop le\n");
    } else {
        printf("Bieu thuc không hop le\n");
    }
    return 0;
}

