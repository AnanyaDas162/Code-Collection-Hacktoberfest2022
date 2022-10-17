#include<stdio.h>
int a[100];
int max,min;
void maximum(int i,int j)
{
	int max1,min1;
	if(i==j)
	{
		max=min=a[i];
	}
	else if(i=j-1)
	{
		if(a[i]<a[j])
		{
			max=a[j];
			min=a[i];
		}
	     else
	    {
		max=a[i];
		min=a[j];
	    }
      }
else
{
	int mid=(i+j)/2;
	maximum(i,mid);
	max1=max;
	min1=min;
	maximum(mid+1,j);
	if(max<max1)
	max=max1;
	if(min>min1)
	min=min1;
}
}
int main()
{
	int n,i,j,l;
	printf("Enter the size:");
	scanf("%d",&n);
	printf("Enter array:\n");
	for(l=0;l<n;l++)
	scanf("%d",&a[l]);
	i=0,j=n-1;
	maximum(i,j);
	printf("maximum:%d",max);
	printf("minimum:%d",min);
}
