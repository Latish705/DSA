#include<stdio.h>

int main()
{
    int n;
    int i;
    for(i=0;n;i++)
    {
        printf("Enter a number\n");
        scanf("%d",&n);
        if(n%2!=0)
            n=0;
    }
    return 0;
}