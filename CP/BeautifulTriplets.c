#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    int n,d;
    scanf("%d %d",&n,&d);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int s=0;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]-a[i]!=d) continue;
            for(int k=j+1;k<n;k++){
                if(a[j]-a[i]==a[k]-a[j] && a[k]-a[j]==d)s++;
            }
        }
    }
    printf("%d",s);
    return 0;
}