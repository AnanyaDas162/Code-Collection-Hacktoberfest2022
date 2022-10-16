#include<stdio.h>
#include<stdlib.h>


int main() 
{ 
    int arr[] = {30, 50, 30, 10, 20, 40, 10, 20}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    int visited[n] = {0};
    int count_dis=0;
    
    for(int i=0; i < n; i++)
    {
        // only if unvisited
        if(visited[i]==0)
        {
            for(int j = i+1; j < n; j++){
              
                if(arr[i] == arr[j]){
                    // mark visited
                    visited[j] = 1;
                }
            }
          
            count_dis++;
        }
    }
   printf("Distinct items : %d ",count_dis);
   return 0; 
}
