#include<stdio.h>
int lcm(int, int);
int main()
{
    int a, b;
    printf("enter two numbers to calculate lcm");
    scanf("%d %d",&a, &b);
    printf("%d is the lcm of the given nunbers",lcm(a,b));
    return 0;
}
lcm(int x, int y)
{
    int i;
    for(i=2;i<=x || i<=y; i++)
    {
        if(x%i==0 && y%i==0)
        break;  
    }
    return i;
}