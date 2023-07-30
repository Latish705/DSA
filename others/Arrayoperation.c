#include <stdio.h>
void addEle(int index, int data,int size,int arr[])
{
    if (index < 0 || index >=size)
    {
        printf("Invalid Index\n");
    }
    else
    {
        arr[index] = data;
    }
}
void rotateByone(int size,int arr[])
{
    

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
            arr[size-i+1]=0;
        }
    }
}
void insert(int index,int data,int size,int arr[])
{
    if(index<0 ||index>size-1)
        printf("Invalid ");
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
        printf("5.form different array of even and odd elements\n");
        printf("6.Exit");
        scanf("%d", &choice);
        switch(choice)
        {   case 1:
                printf("Enter index and data : ");
                scanf("%d %d", &index, &data);
                addEle(index, data,size,a);
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
                rotateByone(size,a);
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