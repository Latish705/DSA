#include<stdio.h>
int lastindex;
int capacity;
void push(char stack[],char data)
{
    if(lastindex==capacity-1)
        printf("Stack overflow\n");
    else
    {
        lastindex++;
        stack[lastindex]=data;
    }
}

int pop(char stack[])
{
    if(lastindex==-1)
    {
        printf("Stack Underflow\n");

    }
    lastindex--;
    return (int)stack[lastindex];
}

int postfixtoInfix(char postfix[],char stack[])
{   int i=0,val;
    while(postfix[i])
    {
        if(postfix[i]>='1'&&postfix[i]<='9')
            push(stack,postfix[i]);
        else
        {
            int x=pop(stack);
            int y=pop(stack);
            switch (postfix[i])
            {
            case '+':
            val=x+y;                
                break;
            case '-':
            val=x-y;
                break;
            case '*':
            val=x*y;
                break;
            case '/':
            val=x/y;
                break;
            case '%':
            val=x%y;
                break;

            default:
                break;
            }
            push(stack,val);
        }

    }
}

int main()
{
    char postfix[10],stack[10];
    lastindex=-1;
    capacity=10;
    int choice;
    while(choice!=3)
    {
        printf("Enter choice you want to perform\n");
        printf("1.");
        printf("2.");
        printf("3.");
        switch (choice)
        {
        case 1:
            printf("Enter postfix expression\n");
            gets(postfix);
            break;
        case 2:
            
            printf("%d",postfixtoInfix(postfix,stack));
        default:
            break;
        }
        
     
    }


}