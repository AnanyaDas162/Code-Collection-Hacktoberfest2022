#include <stdio.h>

void printReverse(int arr[], int len){
    
    for(int i = len - 1; i >= 0; i--)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    
    int len = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array in Reverse:\n");
    printReverse(arr, len);

    return 0;
}
