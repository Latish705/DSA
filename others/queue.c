#include<stdio.h>
int front=-1;
int rear=-1;
int capacity;


void Delete(int arr[])
{
    if(front==-1 || rear==-1)
        printf("Queue is Empty\n");
    else if(front==rear)
    {
        printf("Element %d is successfully deleted\n",arr[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
        printf("Element %d is successfully deleted\n",arr[front]);
    }
}

void Insert(int arr[])
{
    if(rear==capacity-1)
        printf("Queue is Full\n");
    else if(front==-1 && rear==-1)
    {
        int data;
        printf("Enter the data you want to insert : ");
        scanf("%d",&data);
        front++;
        rear++;
        arr[rear]=data;
        printf("\nThe data %d is successfull inserted\n",data);
    }
    else
    {
        int data;
        printf("Enter the data you want to insert : ");
        scanf("%d",&data);
        rear++;
        arr[rear]=data;
        printf("\nThe data %d is successfull inserted\n",data);
    }

}

int main()
{
    int size;
    printf("Enter the size of Queue you want : ");
    scanf("%d",&size);
    int queue[size];
    capacity=size;
    int choice,i;
    while(choice!=4)
    {
        printf("Enter the choice of operation you want to perform\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
    {
        case 1:
        Insert(queue);
        for(i=front;i<=rear;i++)
            printf("%d ",queue[i]);
            printf("\n");
            break;
        case 2:
            Delete(queue);
            if(front==-1 && rear==-1)
            {
                printf("\n");
            }
            else
            {
                for(i=front;i<=rear;i++)
                {
                    printf("%d ",queue[i]);
                }
                printf("\n");
            }
            break;
        case 3:
            if(front==-1 && rear==-1)
            {
                printf("Queue is Empty\n");
                printf("\n");
            }
            else
            {
                for(i=front;i<=rear;i++)
                {
                    printf("%d ",queue[i]);
                    
                }
                printf("\n");
            }
            break;
        case 4:
            break;
    }
    }


    return 0;
}
