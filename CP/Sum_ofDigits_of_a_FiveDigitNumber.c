#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,m,sum=0,temp;
    scanf("%d", &n);
    temp=n;
    while(temp>0)
    {
        m=temp%10;
        sum=sum+m;
        temp=temp/10;
    }
    printf("%d",sum);
    return 0;
}
