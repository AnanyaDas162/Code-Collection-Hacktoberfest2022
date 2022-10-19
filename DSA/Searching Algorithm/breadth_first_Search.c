#include<stdio.h>
#include<stdlib.h>
int q[100],mat[100][100],vis[20];
int f=-1;
int r=-1,size[100];
int isempty();
int delet();
int add(int);

int main(){
	int i,j,v,n;
	char s;
	printf("Enter No of vertex:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
	
	printf("Enter 1 for connected and 0 for not connected:");
	scanf("%d",&mat[i][j]);}}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
	printf("%d",mat[i][j]);}
	printf("\n");}
	for(i=0;i<n;i++){
		vis[i]=0;
		}
	printf("Enter Starting Vertex:");
//	scanf("%d",&v);
     scanf("%c",&s);
     v=s-65;
	vis[v]=1;
	printf("BFS=");
	printf("%c",v+65);
	add(v);
	while(isempty())
	{
		int o=delet();
		for(j=0;j<n;j++){
			if(mat[o][j]==1 && vis[j]==0)
			{
				printf("%c",j+65);
				vis[j]=1;
				add(j);
			}
		}}}
int isempty(){
	if(f==r && f!=0){
		return 0;
	}
	else{
		
	return 1;
}
}

int add(int v){
	if(r==15){
		printf("Queue Full");
	}
	else if(f==-1){
		r++;
		q[r]=v;
		f++;
	}
	else{
		r++;
		q[r]=v;
	}
	return 0;
	
}
int delet()
   {
	int a;
	if(r==-1)
	printf("Empty\n");
	else{
	
		a=q[f];
		f++; 

		return a;
	}}
