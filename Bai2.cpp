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

int pop(Stack* stack){
	int temp;
	if(isEmpty(stack) == 1){
		printf("Ngan xep rong!");
		return 0;
	}
	temp = stack->array[stack->top];
	stack->array[--(stack->top)];
	return temp;
}

void printStack(Stack* stack){
	for(int i = stack->top; i >= 0; i--){
		printf("| %d |\n", stack->array[i]);
	}
}

int main(){
	int value, n;
	Stack stack;
	inital(&stack);
	printf("n = ");
	scanf("%d", &n);
	printf("Nhap vao gia tri can them: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &value);
		push(&stack, value);
	}
	printf("Phan tu bi xoa: %d\n", pop(&stack));
	printf("Cac phan tu con lai:\n");
	printStack(&stack);
	return 0;
}

