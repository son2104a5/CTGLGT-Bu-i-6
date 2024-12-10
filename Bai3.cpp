#include <stdio.h>
#include <stdlib.h>

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

void push(Stack* stack, int value){
	if(isFull(stack) == 1){
		printf("Ngan xep da day, khong them duoc");
		return;
	}
	stack->array[++(stack->top)] = value;
}

void printStack(Stack* stack){
	if(stack->top == -1){
		printf("Ngan xep rong");
	} else {
		printf("Ngan xep khong rong");
	}
}

int main(){
	int value, n;
	Stack stack;
	inital(&stack);
	printf("n = ");
	scanf("%d", &n);
	if(n > 0){
		printf("Nhap vao gia tri can them: ");
		for(int i = 0; i < n; i++){
			scanf("%d", &value);
			push(&stack, value);
		}
	}
	printStack(&stack);
	return 0;
}

