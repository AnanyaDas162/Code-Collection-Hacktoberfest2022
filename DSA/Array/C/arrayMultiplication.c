#include<stdio.h>
#include<stdlib.h>
void main()
{
	//int *A,*B,*C;
	int R,c,i,j,k;
	printf("\nEnter the number of rows:");
	scanf("%d",&R);
	printf("\nEnter the number of columns:");
	scanf("%d",&c);
	int *A=(int *)malloc((R*c)*sizeof(int));
	int *B=(int *)malloc((R*c)*sizeof(int));
	int *C=(int *)malloc((R*c)*sizeof(int));
	printf("\nEnter the first matrix elements:");
	for(i=0;i<R;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nEnter element at A[%d][%d]",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	printf("\nEnter the Second matrix elements:");
	for(i=0;i<R;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nEnter element at B[%d][%d]",i,j);
			scanf("%d",&B[i][j]);
		}
	}
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<c;j++)
		{
			C[i][j]=0;
			for(k=0;k<c;k++)
			{
				C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
			}
		}
	}
	printf("\nMatrix after multiplication:");
	for(i=0;i<R;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",C[i][j]);
		}
		printf("\n");
	}
	
}
