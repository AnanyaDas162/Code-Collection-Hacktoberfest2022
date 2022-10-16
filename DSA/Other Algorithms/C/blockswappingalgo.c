#include<stdio.h>
 
void printArray(int arr[], int size);
void swap(int arr[], int fi, int si, int d);
 
void leftRotate(int arr[], int d, int n)
{
    if(d == 0 || d == n)
        return;
     
    if(n-d == d){
        swap(arr, 0, n-d, d);  
        return;
    } 
     
    if(d < n-d){ 
        swap(arr, 0, n-d, d);
        leftRotate(arr, d, n-d);   
    }   
    else{
        swap(arr, 0, d, n-d);
        leftRotate(arr+n-d, 2*d-n, d);
    }
}
 

void swap(int arr[], int fi, int si, int d)
{
   int i, temp;
   for(i = 0; i<d; i++)  
   {
     temp = arr[fi + i];
     arr[fi + i] = arr[si + i];
     arr[si + i] = temp;
   }    
}    
 

int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60, 70};
   leftRotate(arr, 2, 7);
   
   for(int i = 0; i < 7; i++)
    printf("%d ", arr[i]);
   
   return 0;
}   
