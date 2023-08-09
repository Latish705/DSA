#include<stdio.h>
char stack[100]={'0'};
int capacity,top=-1;
void infixToPostFix(char infix[],char postfix[])
{
    int i=0,j=0;
    for(int i;infix[i];i++)
    {
        if(infix[i]=='(')
            push(stack,infix[i]);
        else if(infix[i]==')')
        {
            while((top!=-1) && (stack[top]!='('))
            {
                postfix[j]=pop(stack);
            }
        }
    }
}
void push(char arr,char data)
{
    if(top==capacity-1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top]=data;
    }
}
char pop(char arr)
{
    if(top==-1)
        printf("Stack Underflow\n");
    else
    {
        stack[top]=-1;
        top--;
        return stack[top+1];
    }
}
char peek(char arr)
{
    if(top==-1)
        printf("Stack underflow\n");
    else
        return stack[top];
}

int main()
{
    char infix[100]={'0'};
    printf("Enter Expression :\n");
    gets(infix);
    char postfix[100]={'0'};
    infixToPostFix(infix,postfix);

    return 0;
}