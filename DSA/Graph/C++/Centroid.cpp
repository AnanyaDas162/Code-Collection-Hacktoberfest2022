#include<bits/stdc++.h>
using namespace std;
vector<int> sum;

void dfs(vector<int> g[],int u,vector<int> &vis)
{
    vis[u]=1;
    sum[u]=1;

    for(auto v:g[u])
    {
        if(vis[v]==0)
        {
            //if(sum[])
            dfs(g,v,vis);
            sum[u]+=sum[v];
        }
    }
}

void dfs2(vector<int> g[],int u,int p)
{
    sum[u]=1;

    for(auto v:g[u])
    {
        if(v!=p)
        {
            //if(sum[])
            dfs2(g,v,u);
            sum[u]+=sum[v];
        }
    }
}

int centroid(vector<int> g[],int u,int p,int n)
{
    for(auto v:g[u])
    {
        if(v!=p && sum[v]>n/2)
            return centroid(g,v,u,n);
    }
    return u;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t=1;
    //cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> g[n+1];
        sum.resize(n+1,0);
        int k=n-1;
        int a,b;
        while(k--)
        {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> vis(n+1,0);

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs(g,i,vis);
            }
        }

        dfs2(g,1,-1);
        cout<<centroid(g,1,-1,n)<<endl;
    }
}

