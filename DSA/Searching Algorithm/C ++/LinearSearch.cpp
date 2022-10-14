#include<iostream>
#include<stdlib.h>
using namespace std;

bool LinearSearch(int array[],int size,int key){
    for(int i=0;i<size;i++){
        if(array[i] == key){
            return 1;

        }
    }
    return 0;
}

int main()
{
int array[10] = {1,2,3,4,5,6,7,8,9,10};
int key;
cout<<"Enter the value of key :" <<endl;
cin>>key;
bool found = LinearSearch(array,10,key);
if(found){
    cout<<"Element is persent "<<endl;
}
else{
    cout<<"Element is not persent"<<endl;
}
}
