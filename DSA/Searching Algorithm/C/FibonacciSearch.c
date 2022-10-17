/*A program to search a value in an array using Fibonacci Search method*/

#include <stdio.h>

int min(int x, int y)
{
    if(x<y)
        return x;
    return y;
}

int fibonacciSearch(int *array, int n, int target)
{
	int i,fib2,fib1,fib;
	int fib1=1,fib2=0,offset=-1;
	fib=fib2+fib1;
	while(fib<n)
	{
		fib2=fib1;
		fib1=fib;
		fib=fib2+fib1;
	}
	while(fib>1)
	{
		i=min(offset+fib2,n-1);
		if(array[i]<target)
		{
			fib=fib1;
			fib1=fib2;
			fib2=fib-fib1;
			offset=i;
		}
		else if(array[i]>target)
		{
			fib=fib2;
			fib1=fib1-fib2;
			fib2=fib-fib1;
		}
		else
			return i;
	}
	if(fib1 && array[offset+1]==target)
		return offset+1;
        
	return -1;
}

int main()
{
    int n,i,item,index;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int arr[n];
	puts("\nEnter array elements");
	for(i=0;i<=n-1;i++)
	    scanf("%d",&arr[i]);
	printf("\nEnter the value to search: ");
	scanf("%d",&item);
	
	index=fibonacciSearch(arr,n,item);
	
    if(index!=-1)
		printf("\n%d present in position: %d",item,index+1);
	else
		printf("\n%d not present in the array...",item);
    
    return 0;
}