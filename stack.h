#ifndef STACK_H
#define STACK_H

typedef struct Stack {
	int data;
	struct Stack* below;
}Stack;


Stack* push(int value, Stack* top);
int peek(Stack* top);
Stack* pop(Stack* top);
void search(int searchValue, Stack* top);
void size(Stack* pop);
void printStack(Stack* top);
void deleteStack(Stack* top);



#endif