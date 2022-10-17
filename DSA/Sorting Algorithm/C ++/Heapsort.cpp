#include<bits/stdc++.h>
using namespace std;
//int arr[20];
//void heap_sort(int,int);
//void MaxHeapify(int,int,int);
  void MaxHeapify(int arr[],int n,int i)
{
  int t;
  int largest=i;
  int l=2*i+1;
  int r=2*i+2;
  if(l<n  &&   arr[l]>arr[largest])
  {
         largest=l;
  }
  if(r<n  &&   arr[r]>arr[largest])
  {
        largest=r;
  }
  if(largest!=i)
  {
    t=arr[i];
    arr[i]=arr[largest];
    arr[largest]=t;
    MaxHeapify(arr,i,largest);
  }
}
void heap_sort(int arr[],int n)
      {
        int i,l,t ;
        for(i=n/2-1;i>=0;i--)
        {
             MaxHeapify(arr,n,i);
        }
        for(i=n-1;i>0;i--)
        {
          t=arr[0];
          arr[0]=arr[i];
          arr[i]=t;
          MaxHeapify(arr,i,0);
        }
      }
  int main()
    {
    int  i,n;
    cout<<"Enter the size:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements for sorting:";
    for(i=0;i<n;i++)
    cin>>arr[i];
   heap_sort(arr,n);
   cout<<"\nSorted Data :";
   for (i = 0; i <n; i++)
    {
    cout<<arr[i];
    }
    }

