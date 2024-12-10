#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct {
	int array[MAX];
	int top;
} Stack;

void inital(Stack* stack){
	stack->top = -1;
}

int isEmpty(Stack* stack){
	if(stack->top == -1){
		return 1;
	}
	return 0;
}

int isFull(Stack* stack){
	if(stack->top >= MAX - 1){
		return 1;
	}
	return 0;
}

void push(Stack* stack, char value){
	if(isFull(stack) == 1){
		printf("Ngan xep da day, khong them duoc");
		return;
	}
	stack->array[++(stack->top)] = value;
}

void printStack(Stack* stack){
	for (int i = stack->top; i >= 0; i--) {
        printf("%c", stack->array[i]);
    }
	printf("\n");
}
int main(){
	char value[MAX];
	Stack stack;
	inital(&stack);
	printf("Nhap vao xau ki tu: ");
	fgets(value, MAX, stdin);
    value[strcspn(value, "\n")] = '\0';
    int n = strlen(value);
    for (int i = 0; i < n; i++) {
        push(&stack, value[i]);
    }
	printStack(&stack);
	return 0;
}

