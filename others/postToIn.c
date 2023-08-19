#include <stdio.h> 
#include <stdlib.h> // Added for using the atoi() function

int lastindex=-1; 
int capacity; 

void push(char stack[], char data) 
{ 
    if (lastindex == capacity - 1) 
        printf("Stack overflow\n"); 
    else 
    { 
        lastindex++; 
        stack[lastindex] = data; 
    } 
} 
 
int pop(char stack[]) 
{ 
    if (lastindex == -1) 
    { 
        printf("Stack Underflow\n"); 
        return -1; // Added a return value to handle underflow
    } 
    int data = stack[lastindex]; // Store the value to be returned
    lastindex--; 
    return stack[lastindex+1]; // Return the popped value
} 
 
int postfixtoInfix(char postfix[], char stack[]) 
{ 
    int i = 0, val = 0; // Initialized val to 0
    while (postfix[i]) 
    { 
        if (postfix[i] >= '1' && postfix[i] <= '9') 
            push(stack, postfix[i] - '0'); // Convert char to int
        else 
        { 
            int y = pop(stack); 
            int x = pop(stack); 
            
            switch (postfix[i]) 
            { 
                case '+': 
                    val = x + y;                 
                    break; 
                case '-': 
                    val = x - y; 
                    break; 
                case '*': 
                    val = x * y; 
                    break; 
                case '/': 
                    val = x / y; 
                    break; 
                case '%': 
                    val = x % y; 
                    break; 
                default: 
                    break; 
            } 
            push(stack, val); 
        } 
        i++; // Move this line outside the if-else block
    } 
    return pop(stack); // Return the final result
} 

int main() 
{ 
    char postfix[100], stack[100]; 
    int val;
    lastindex = -1; 
    capacity = 10; 
    int choice = 0; 
    while (choice != 3) 
    { 
        printf("Enter choice you want to perform\n"); 
        printf("1. Enter postfix expression\n"); // Added menu items
        printf("2. Evaluate postfix expression\n");
        printf("3. Exit\n");
        scanf("%d", &choice); 
        switch (choice) 
        { 
            case 1: 
                fflush(stdin); 
                printf("Enter postfix expression\n"); 
                fflush(stdin); 
                fgets(postfix, 10, stdin); 
                break; 
            case 2: 
                val = postfixtoInfix(postfix, stack); // Added variable to store the result
                if (val != -1)
                    printf("Result: %d\n", val); // Print the result if it's valid
                break; 
            case 3: 
                break; 
            default: 
                printf("Invalid Choice\n"); 
        } 
    } 
    return 0; // Added return statement
}
