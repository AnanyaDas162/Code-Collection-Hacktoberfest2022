#include<stdio.h>
#include<math.h>

int main()
{
	int a[20][20],i,j,sum=0,n;
	float d;
		
	printf("enter the size\n");
	scanf("%d",&n);
	
		printf("enter the elements\n");
		for(i=0;i<n;i++){
		for(j=0;j<n;j++){	
		scanf("%d",&a[i][j]);
     	}
}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){	
		sum=sum+pow(a[i][j],2);
     	}
}
d=sqrt(sum);

printf("%0.2f is the norm",(d));



}


