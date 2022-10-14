#include<iostream>
#include<stdlib.h>
using namespace std;
#include<math.h>
#include<climits>

int getMIN(int num[],int n){
    int min =INT_MAX;
    for(int i=0;i<n;i++){
        if(num[i]<min){

            min=num[i];
        }
    }
    return min;
}

int getMax(int num[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(num[i]>max){
            max=num[i];
        }
    }
   return max;
}
int main()
{
system("CLS");
int size;
cout<<"Enter the size of array ";
cin>>size;


int num[100];
cout<<"Emter elements of array ";
for(int i=0;i<=size;i++){
    
    cin>>num[i];
}
cout<<"Maximum Value is "<<getMax(num,5)<<endl;
cout<<"Minimu Value is "<<getMIN(num,5)<<endl;

return 0;
}