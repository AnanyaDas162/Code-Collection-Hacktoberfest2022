#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cout<<"Input testcase: "<<endl;
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"Enter size of array size: ";
        cin>>n;
        int a[n]; //will contain 0,1,2
        cout<<endl<<"Enter array elements: "<<endl;
        for (int i=0;i<n;i++)
        {
            cin>>a[i]; //it takes inputs of array
        }
        
        int c0=0,c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            c0++;  //will count how many 0s are present in array
            else if(a[i]==1)
            c1++;  //will count how many 1s are present in array
            else
            c2++;  //will count how many 2s are present in array
        }
        int k=0;  //use to increase array index and store element by it
        for(int i=0;i<c0;i++)  //takes the total number of 0s and print that num of zeros 
        a[k++]=0;  
        for(int i=0;i<c1;i++)
        a[k++]=1;  //if in previous k was 3 now here it will start from 4
        for(int i=0;i<c2;i++)
        a[k++]=2;

        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" "<<endl;

        }


    }
    return 0;
}