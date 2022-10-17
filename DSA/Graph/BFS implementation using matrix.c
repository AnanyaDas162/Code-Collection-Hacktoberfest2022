#include<stdio.h>

int a[20][20],q[20],visited[20],n,f=-1,r=-1;

void bfs(int v) 
{
       int i;
       for (i=0;i<n;i++)                                // check all the vertices in the graph
       {
               if(a[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
              {
                       r=r+1;
                       q[r]=i;                       // insert them into queue
                       visited[i]=1;          // mark the vertex visited
                       printf("%d  ",i);
              }
      }
      f=f+1;                             // remove the vertex at front of the queue
      if(f<=r)                           // as long as there are elements in the queue
            bfs(q[f]);                  // peform bfs again on the vertex at front of the queue
}
int main()
{
    int v,i,j;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    for (i=0;i<n;i++)                   // mark all the vertices as not visited
    {
        visited[i]=0;
    }
    printf("\n Enter graph data in matrix form:\n");
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
       scanf("%d",&a[i][j]);
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    f=r=0;
    q[r]=v;
    printf("\n BFS traversal is:\n");
    visited[v]=1;                                     // mark the starting vertex as visited
    printf("%d   ",v);
   
    bfs(v);
    if(r != n-1)
        printf("\n BFS is not possible");
}
