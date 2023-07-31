#include <stdio.h>
int lastindex=-1;
int sizeo;
void addEle(int data,int arr[])
{
    if(lastindex==sizeo-1)
        printf("Array is Full\n");
    else
    {
        lastindex++;
        arr[lastindex] = data;
    }
}
void rotateRightByone(int sizeo,int arr[])
{
    int last=arr[sizeo-1];
    int i;
    for(i=sizeo-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[0]=last;

}
void deleteEle(int index,int size,int arr[])
{
    if(arr[0]==0)
        printf("Array is empty\n");
    else if (index < 0 || index >= size)
        printf("Invalid Index\n");
    else
    {
        int i;
        for (i = index; i < size; i++)
        {
            arr[i]=arr[i+1];
        }
        arr[size-1]=0;
    }
}
void insert(int index,int data,int size,int arr[])
{
    if(lastindex==size-1)
        printf("Array is Full\n");
    else if(index<0||index>lastindex+1)
        printf("Invalid Index\n");
    else
    {
        int i=lastindex+1;
        for(i;i!=index;i++)
            arr[i]=arr[i-1];
        arr[index]=data;
    }
}
void sort(int size,int arr[])
{
    int i,j,temp;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{   int size;
    printf("Enter the size of Array you want : ");
    scanf("%d", &size);
    int a[size];
    sizeo=size;
    int i;
    int data, index;
    for(i=0;i<size;i++)
    {
        a[i]=0;
    }
    int choice = 0;
    while (choice != 6)
    {
        printf("Enter your choice to perform operation\n");
        printf("1.Add at specific index\n");
        printf("2.delete at specific index\n");
        printf("3.Insert at specific index\n");
        printf("4.Sort\n");
        printf("5.Rotate Array by one\n");
        printf("6.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {   case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                addEle(data,a);
                for(i=0;i<size;i++)
                {
                    printf("%d ",a[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Enter index to delete : ");
                scanf("%d",&index);
                deleteEle(index,size,a);
                for(i=0;i<size;i++)
                {
                    printf("%d ",a[i]);
                }
                printf("\n");
                break;
            case 3:
                printf("Enter index and data\n");
                scanf("%d %d",&index,&data);
                insert(index,data,size,a);
                for(i=0;i<size;i++)
                {
                    printf("%d ",a[i]);
                }
                printf("\n");
                break;
            case 4:
                sort(size,a);
                for(i=0;i<size;i++)
                {
                    printf("%d ",a[i]);
                }
                printf("\n");
                break;
            case 5:
                rotateRightByone(size,a);
                for(i=0;i<size;i++)
                {
                    printf("%d ",a[i]);
                }
                printf("\n");
                break;
            case 6:
                break;
    }

    }


    return 0;
}