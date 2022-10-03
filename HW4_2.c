/*
Ibrokhimbek Pulatov
CSCI-240
Infix to Posfix
10/10/2021
*/


#define SIZE 50            /* Size of Stack */
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>




char stack[SIZE];
int top=-1;       /* Global declarations */
 
/* Function for PUSH operation */

void push(char item){
    if(top >= SIZE - 1){
		printf("Stack Overflow ..\n");
		return;
	}

	else{
    	top = top + 1;
        stack[top] = item;
	}
} 

/* Function for POP operation */
char pop(){
    int item;
    if(top < 0)
    {
        printf("\nStack Underflow..\n");
        exit(0);
    } 

	else 
	{
		item = stack[top]; 
        top = top - 1;
        return item;
	}
}

 /* Function for precedence */
int pr(char elem){                
    switch (elem){
        case '^':
            return 3;
            break;
        case '/':
        case '*':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
    }
    return -1;
}


 /* Function for infix to postfix conversion */
void InfixToPostfix(char infx[], char pofx[]){
	int j = 0;
	for(int i = 0; infx[i] != '\0'; i++){
		if(isalnum(infx[i])){
			pofx[j] = infx[i]; 
			j++;
		}
		else if(infx[i] == '('){
			push(infx[i]);
		}

		else if(infx[i] == ')'){
			while(stack[top] != '('){
				pofx[j] = pop();
				j++;
			}
			if(stack[top] != '('){
				return;
			}
			else{
				pop();
			}
		}

		else{
			while (pr(infx[i]) <= pr(stack[top])){
				pofx[j] = pop();
				j++;
			}
			push(infx[i]);
		}
		
	}

	while(top > -1){
		pofx[j] = pop();
		j++;
	}

	pofx[j] = '\0';
	return;
}

/* main function begins */
int main()
{
	char infix[SIZE], postfix[SIZE];        /* declare infix string and postfix string */
	printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	FILE *in = fopen("in.txt","r");

    if(in != NULL)
    {

	    fscanf(in, "%s", infix);
	    InfixToPostfix(infix,postfix);                   /* call to convert */
		printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n", infix, postfix);
    }
    
    fclose(in);
	return 0;
}

// Please mercy!!!