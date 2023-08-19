#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // Include for isdigit and isalpha
#define max 100
char a[max];
int top = -1;
void push(char a[], char);
char pop(char a[]);
void intopost(char source[], char target[]);
int getpriority(char op);
void main()
{
    char infix[100], postfix[100];
    int choice, i, n;
    do
    {
        printf("\nEnter your choice:\n1. Enter Postfix Expression\n2.Convert Infix to Postfix and Display\n3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter any infix expression: \n");
            getchar();  // Clear the newline character
            gets(infix);
            strcpy(postfix, "");
            break;
        case 2:
            intopost(infix, postfix);
            break;
        case 3:
            break;
        }
    } while (choice != 3);
}
void intopost(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(a, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (a[top] != '('))
            {
                target[j] = pop(a);
                j++;
            }
            if (top == -1)
            {
                printf("\nIncorrect Expression");
                exit(1);
            }
            temp = pop(a); //To remove left parenthesis
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (a[top] != '(') && (getpriority(a[top]) >= getpriority(source[i])))
            {
                target[j] = pop(a);
                j++;
            }
            push(a, source[i]);
            i++;
        }
        else
        {
            printf("\n Incorrect element in expression");
            exit(1);
        }
    }
    while ((top != -1) && (a[top] != '('))
    {
        target[j] = pop(a);
        j++;
    }
    target[j] = '\0';
    printf("The corresponding postfix expression is: ");
    puts(target);
}
int getpriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    return -1;  // Handle other operators if necessary
}
void push(char a[], char n)
{
    if (top == max - 1)
    {
        printf("Stack Overflow, Cannot push in Stack\n");
    }
    else
    {
        top++;
        a[top] = n;
    }
}
char pop(char a[])
{
    char n = ' ';
    if (top == -1)
    {
        printf("Stack Underflow, Cannot pop from Stack\n");
    }
    else
    {
        n = a[top];
        top--;
    }
    return n;
}
