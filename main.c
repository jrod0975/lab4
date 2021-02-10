#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "stack.h"

bool isOp(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}

int performOp(int v1, int v2, char op) {
	int answer;
	switch (op) {
	case '+':
		answer = v2 + v1;
		break;
	case '-':
		answer = v2 - v1;
		break;
	case '*':
		answer = v2 * v1;
		break;
	case '/':
		answer = v2 / v1;
	}
	return answer;
}

int main(int argc, char* argv[]) {
	FILE* file = fopen("input.txt", "r");
	//Stack* stack = NULL;
	

	while (!feof(file)) {
		Stack* stack = NULL;
		char buffer[50];
		fgets(buffer, 50, file);
		printf("%s\n", buffer);
		int length = strlen(buffer);

		int v1, v2, answer;
		for (int i = 0; i < length; i++) {
			//Stack* stack = NULL;
			int x = 0;
			//printf("%c\n", buffer[i]);
			if (isalpha(buffer[i]) || buffer[i] == '%') {
				printf("invalid Character %c!\n", buffer[i]);
			}
			if (!isOp(buffer[i])) {
				x = x * 10 + (buffer[i] - '0');
				stack = push(x, stack);
				//printf("\n\n");
				//printStack(stack);
			}
			if (isOp(buffer[i])) {
				v2 = peek(stack);
				stack = pop(stack);
				//printStack(stack);
				v1 = peek(stack);
				stack = pop(stack);
				//printStack(stack);
				answer = performOp(v2, v1, buffer[i]);
				stack = push(answer, stack);
				
			}
			
		}
		//printf("\n****\n");
		stack = pop(stack);
		int y = peek(stack);
		stack = pop(stack);
		printf("*********the answer is %d***********\n\n", y);
		printStack(stack);
		//printf("****");
		deleteStack(stack);
	}


	return 0;
}
