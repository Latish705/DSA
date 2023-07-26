#include<iostream>
using namespace std;



class Array
{
    private:
    int capacity;
    int lastindex;
    int *ptr;
    public:
    //don't forget to make copy constructor
    Array(int data);
    bool isEmpty();
    void append(int data);
    void displayArray();
    void insert(int index,int data);
    void edit(int index,int data);
    void deleteEle(int index);
    bool isFull();
    int getele(int index);
    int count();
    ~Array();
    int findEle(int data);
    void sort();
    int findGreatest();
    int findSmallest();
    int searchEle(int data);
    int calculatesum();
    float calculateAvg();
    void rotateByOne();
    void removeDupli();
    int secondLargest();
    void operator=(Array a);
    void operator[](int size);
};
void Array::operator[](int size)
{
    ptr=new int[size];
}
void Array::operator=(Array a)
{
    capacity=a.capacity;
    lastindex=a.lastindex;
    int *ptrc=new int[capacity];
    int i;
    for(i=0;i<lastindex;i++)
        ptrc[i]=ptr[i];
}
int Array::secondLargest()
{
   if(lastindex!=-1)
   {
        int large=ptr[0],slarge;
        int i;
        for(i=1;i<=lastindex;i++)
        {
            if(ptr[i]>large)
            {
                slarge=large;
                large=ptr[i];
            }
        }
        cout<<slarge<<endl;
        cout<<large<<endl;
        return slarge;
   }
}
void Array::removeDupli()
{
    if(lastindex!=-1)
    {
        //we will use two loop concept;
        int i,j,k;
        for(i=0;i<=lastindex;i++)
        {
            for(j=i+1;j<=lastindex;j++)
            {
                if(ptr[i]==ptr[j])
                {
                    for(k=j;k<lastindex;k++)
                        ptr[k]=ptr[k+1];
                }
            }
        }
    }
}
void Array::rotateByOne()
{
    if(lastindex!=-1)
    {
        int i,temp=ptr[lastindex];
        for(i=lastindex;i>-1;i--)
        {
            ptr[i]=ptr[i-1];
        }
        ptr[0]=temp;
    }
    cout<<"Array is Empty"<<endl;
}
float Array::calculateAvg()
{
    if(lastindex!=-1)
    {
        int i;
        double avg=0;
        for(i=0;i<=lastindex;i++)
        {
            avg=avg+ptr[i];
        }
        return avg/i;
    }
}
int Array::calculatesum()
{
    if(lastindex!=-1)
    {
        int sum=0;
        int i;
        for(i=0;i<=lastindex;i++)
        {
            sum=sum+ptr[i];
        }
        return sum;
    }
    cout<<"Array is empty"<<endl;
    return -1;
}
int Array::searchEle(int data)
{
    //return first occurence or return -1
    if(lastindex!=-1)
    {
        int i;
        for(i=0;i<=lastindex;i++)
        {
            if(ptr[i]==data)
                return i;
    
        }
        return -1;
    }
    cout<<"Array is empty"<<endl;
    return -1;
}
int Array::findSmallest()
{
    int min=ptr[0];
    int i;
    for(i=0;i<=lastindex;i++)
    {
        if(ptr[i]<min)
            min=ptr[i];
    }
    return i;
}
int Array::findGreatest()
{
    int max=-1;
    int i;
    for(i=0;i<=lastindex;i++)
    {
        if(ptr[i]>max)
            max=ptr[i];
    }
    return i;
}
int Array::findEle(int data)
{
    if(lastindex!=-1)
    {
        int i;
        for(i=0;i<=lastindex;i++)
        {
            if(ptr[i]==data)
                return i;
        }
        cout<<"Element not found"<<endl;
        return -1;
    }
    return -1;
}
Array::~Array()
{
    delete []ptr;
}
int Array::count()
{
    return lastindex+1;
}
int Array::getele(int index)
{
    if(index<0||index>lastindex+1)
    {
        cout<<"Invalid Index"<<endl;
        return -1;
    }
    else
    {
        return ptr[index];
    }
}
bool Array::isFull()
{
    return lastindex+1==capacity;
}
void Array::deleteEle(int index)
{
    if(index<0||index>lastindex+1)
        cout<<"Invalid Index"<<endl;
    else
        {
            int i;
            for(i=index;i!=lastindex;i++)
                ptr[i]=ptr[i+1];
        }
}
void Array::edit(int index,int data)
{
    if(index<0 || index>lastindex+1)
        cout<<"Invalid Index"<<endl;
    else
        ptr[index]=data;
}
void Array::insert(int index,int data)
{
    if(capacity==lastindex+1)
        cout<<"Array is overflow"<<endl;
    else if(index<0||index>lastindex+1)
        cout<<"Invalid Index"<<endl;
    else
    {
        lastindex++;
        int i;
        for(i=lastindex;i!=index;i--)
            ptr[i]=ptr[i-1];
        ptr[index]=data;
    }

}
void Array::displayArray()
{
    if(lastindex!=-1)
    {
        int i;
        for(i=0;i<=lastindex;i++)
            cout<<" "<<ptr[i]<<"";
        cout<<endl;
        cout<<endl;
    }
}
void Array::append(int data)
{
    if(lastindex==capacity-1)
        cout<<"Array is overflow"<<endl;
    else
        lastindex++;
        ptr[lastindex]=data;
}
bool Array::isEmpty()
{
    return lastindex==-1;
}
Array::Array(int data)
{
    ptr=new int[data];
    lastindex=-1;
    capacity=data;
}

int main()
{
    Array a(12);
    a.append(14);
    a.displayArray();
    a.append(15);
    a.append(16);
    a.append(18);
    a.append(19);
    a.append(20);
    a.displayArray();
    a.insert(3,17);
    a.displayArray();
    a.rotateByOne();
    a.displayArray();
    a.append(20);
    a.append(16);
    a.append(15);
    a.append(19);
    a.displayArray();
    //a.removeDupli();
    a.displayArray();
    cout<<a.secondLargest()<<endl;
    return 0;
}