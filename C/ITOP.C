#include<stdio.h>
#include<conio.h>
#define SIZE 50
char stack[SIZE] ;
int topS = -1 ;
char postfix[SIZE] ;
int topP = -1 ;
void pushInStack(char ch)
{
	if(topS == SIZE - 1)
	{
		printf("The stack is full") ;
	}
	else
	{
		topS++ ;
		stack[topS] = ch ;
	}
}
void popFromStack()
{
	if(topS == -1)
	{
		printf("The stack is already empty") ;
	}
	else
	{
		topS-- ;
	}
}
void pushInPostfix(char c)
{
	if(topP == SIZE - 1)
	{
		printf("The stack is full") ;
	}
	else
	{
		topP++ ;
		postfix[topP] = c ;
	}
}
int getPriority(char op)
{
	switch(op)
	{
		case '+' : return 1 ;
			   break ;
		case '-' : return 1 ;
			   break ;
		case '*' : return 2 ;
			   break ;
		case '/' : return 2 ;
			   break ;
		case '%' : return 3 ;
			   break ;
		case '(' : return 0 ;
			   break ;
	}
}

void main()
{
	char str[SIZE] ;
	int i, len ;
	clrscr() ;
	printf("Enter an infix expression: ") ;
	scanf("%s" , str) ;
	len = strlen(str) ;
	str[len] = ')' ;
	pushInStack('(') ;
	for(i = 0 ; i <= len ; i++)
	{
		if (isalpha(str[i]))
		{
			pushInPostfix(str[i]) ;
		}
		else
		{
			if(str[i] == '(')
			{
				pushInStack(str[i]) ;
			}
			else if(str[i] == ')')
			{
				while(stack[topS] != '(')
				{
					pushInPostfix(stack[topS]) ;
					popFromStack() ;
				}
				popFromStack() ;
			}
			else
			{
				if(getPriority(str[i]) <= getPriority(stack[topS]))
				{
					pushInPostfix(stack[topS]) ;
					popFromStack() ;
					pushInStack(str[i]) ;
				}
				else
				{
					pushInStack(str[i]) ;
				}
			}
		}
	}
	printf("Thus the final postfix expression is :\n") ;
	for(i = 0 ; i < len ; i++)
	{
		printf("%c", postfix[i]) ;
	}
	getch() ;
}
