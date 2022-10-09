#include <iostream>
using namespace std;


void merge(int *arr,int s,int e){
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int *arr1=new int[len1];
    int *arr2=new int[len2];
    
    //copying element
    int mainIndex=s;
    for(int i=0;i<len1;i++){
        arr1[i]=arr[mainIndex++];
    }
    
    mainIndex=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mainIndex++];
    }

    //merge sorted
    mainIndex=s;
    // int size=len1+len2;
    int index1=0,index2=0;

    while(index1<len1 && index2<len2){
        if(arr1[index1]<arr2[index2]){
            arr[mainIndex++]=arr1[index1++];
        }
        else{
            arr[mainIndex++]=arr2[index2++];
        }
    }

    while (index1<len1)
    {
        arr[mainIndex++]=arr1[index1++];
    }
    while (index2<len2)
    {
        arr[mainIndex++]=arr2[index2++];
    }

    delete []arr1;
    delete []arr2;

}

void mergeSort(int *arr,int s,int e){
    if(s>=e)return;

    int mid=(s+e)/2;

    //for left part
    mergeSort(arr,s,mid);

    //for right part
    mergeSort(arr,mid+1,e);

    //merge array
    merge(arr,s,e);

}

int main(){
    int arr[5]={7,3,5,2,4};
    mergeSort(arr,0,4);

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0; 
}