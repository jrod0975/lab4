#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void printStack(Stack* top) {
	Stack* curr = top;
	while (curr != NULL) {
		printf("%d\n", curr->data);
		printf("|\n");
		curr = curr->below;
	}
}

void deleteStack(Stack* top) {
	Stack* curr = top;
	Stack* temp;

	while (curr != NULL) {
		temp = curr;
		curr = curr->below;
		free(temp);
	}
}

Stack* push(int value, Stack* top) {
	if (top == NULL) {
		Stack* newTop = (Stack*)malloc(sizeof(Stack));
		newTop->data = value;
		newTop->below = NULL;
		return newTop;
	}
	else {
		Stack* newTop = (Stack*)malloc(sizeof(Stack));
		newTop->data = value;
		newTop->below = top;
		return newTop;
	}
}

Stack* pop(Stack* top) {
	Stack* pop = top;
	top = top->below;
	free(pop);
	return top;
}

void search(int searchValue, Stack* top) {
	Stack* curr = top;
	int count = 1;
	while (curr != NULL) {
		if (curr->data == searchValue) {
			printf("Found %d at %d\n", searchValue, count);
			return;
		}
		curr = curr->below;
		count++;
	}
}

int peek(Stack* top) {
	//printf("The top is %d\n", top->data);
	return top->data;
}

void size(Stack* top) {
	int count = 0;
	Stack* curr = top;
	while (curr != NULL) {
		count++;
		curr = curr->below;
	}
	printf("The size of the stack is %d\n", count);
}
