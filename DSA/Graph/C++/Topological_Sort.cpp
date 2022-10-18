/* We can't  find topological sort of cyclic graph */
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, cnt = 0;
    cout << "Enter nodes and edges : ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
/* Made a vector of int type and initialized all its indexes to 0 */
    vector<int> indeg(n, 0);
    cout << "Enter edges :\n";
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
/* Insert edges to queue whose indegree = 0 */
    for(int i=0; i<n; i++){
        if(indeg[i] == 0){
            pq.push(i);
        }
    }
/* Print the 0 indegree edges and then push its
upper order edges which is now 0 indegree in queue */
    while(!pq.empty()){
        cnt++;
        int x = pq.front();
        pq.pop();
        cout << x << " ";
        for(auto it : adj[x]){
            indeg[it]--;
            if(indeg[it] == 0)
                pq.push(it);
        }
    }

    return 0;
}

/** -------------------------------STRIVER-------------------------------- */

class DFS {
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it])
                findTopoSort(it, vis, st, adj);
        }
        st.push(node);
    }
public:
    vector<int> topoSort(int N, vector<int> adj[]) {
        stack<int> st;
        vector<int> vis(N, 0);
        for(int i=0; i<N; i++)
            if(vis[i] == 0)
            findTopoSort(i, vis, st, adj);
        vector<int> topo;
        while(!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};

class BFS {
public:
    vector<int> topoSort(int N, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(N, 0);
        for(int i=0; i<N; i++)
            for(auto it: adj[i])
                indegree[it]++;
        for(int i=0; i<N; i++)
            if(indegree[i] == 0)
                q.push(i);
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
};
