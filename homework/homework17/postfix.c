#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Converts a char array representing a simple mathematical expression into 
 * postfix notation.
 */
char* postfix(char* str) {

	// buffers
	char expr[strlen(str)];
	char symbols[strlen(str)];

	char *expr_ptr = expr;
	char *symb_ptr = symbols;

	while(*str) {
		if(	*str == '+' ||
			 	*str == '-' ||
			 	*str == '/' ||
			 	*str == '*' ||
				*str == '(' ) {
			
			*symb_ptr = *str;
			symb_ptr++;
			str++;
		}

		else if(*str == ')') {
			while(symb_ptr > symbols) {
				symb_ptr--;
				if(*symb_ptr == '(') break;
				*expr_ptr = *symb_ptr;
				expr_ptr++;
			}
			if(symb_ptr < symbols) return NULL;
			str++;
		}

		else {
			*expr_ptr = *str;
			expr_ptr++;
			str++;
		}
	}
	
	// for the rest of the expression buffer after the input is finished
	while(symb_ptr >= symbols) {
		symb_ptr--;
		*expr_ptr = *symb_ptr;
		expr_ptr++;
	}

	*expr_ptr = '\0';

	// allocates heap memory for char array so it can be returned
	char *expr_cpy = malloc(sizeof(char) * (strlen(expr) + 1));
	strcpy(expr_cpy, expr);

	return expr_cpy;
}


/**
 * Computes a postfix expression and returns the integer value.
 */
int compute(char* pf) {
	
	int buffer[strlen(pf)];
	int *b_ptr = buffer;

	while(*pf) {
		switch(*pf) {
			case '+':
				b_ptr--;
				*(b_ptr-1) = *b_ptr + *(b_ptr-1);
				break;
			case '-':
				b_ptr--;
				*(b_ptr-1) = *(b_ptr-1) - *b_ptr;
				break;		
			case '*':
				b_ptr--;
				*(b_ptr-1) = *b_ptr * *(b_ptr-1);
				break;		
			case '/':
				b_ptr--;
				*(b_ptr-1) = *(b_ptr-1) / *b_ptr;
				break;
			default:
				*b_ptr = *pf - '0';
				b_ptr++;
		}
		pf++;
	}	

	return (int)*buffer;
}

/**
 * Reads a standard mathematical expression as input and prints the postfix 
 * and computation as output.
 */
int main() {
	
	char buffer[500];

	printf("Enter a basic mathematical expression: ");
	scanf("%s", buffer);
	
	char *new = postfix(buffer);
	int y = compute(new);

	printf("Postfix: %s\n", new);
	printf("Compute: %d\n", y); 

	free(new);

	return 0;
}
