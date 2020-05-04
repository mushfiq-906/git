#include<bits/stdc++.h>
using namespace std;

void Insert(int A[],int n)
{
    int i=n,temp;
    temp=A[i];
    while(i>1 and temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

void Create_Heap(int A[],int n)
{
    for(int i=2;i<=n;i++)
    {
        Insert(A,i);
    }
}

int Delete(int A[],int n)
{
    int temp,i,j;
    temp=A[1];
    A[1]=A[n];
    i=1; j=2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j]){
            swap(A[i],A[j]);
            i=j;
            j=j*2;
        }
        else
            break;
    }
    A[n]=temp;
    return temp;
}

void Print(int A[],int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void heap_sort(int arr[],int n)
{
    for(int i=n;i>=1;i--)
    {
        Delete(arr,i);
    }
}

int main()
{
    int arr[6]={0,10,5,7,12,15};
    cout<<"Input: ";
    Print(arr,5);
    Create_Heap(arr,5);
    cout<<"\nHeap: ";
    Print(arr,5);
    heap_sort(arr,5);
    cout<<"\nSorted: ";
    Print(arr,5);
}
