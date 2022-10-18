/* Find the shortest path from node 'u' to node 'v' */
#include<bits/stdc++.h>
using namespace std;

const int inf = 1e7;

int main()
{
    int n, m;
    cout << "Enter nodes and edges : ";
    cin >> n >> m;
    vector<int> dist(n+1, inf);
    vector<vector<pair<int, int>>> graph(n+1);
    cout << "Enter edges :\n";
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int source;
    cout << "Enter source node : ";
    cin >> source;
    dist[source] = 0;
    set<pair<int, int>> s;
// {wt, vertex}
    s.insert({0, source});
    while(!s.empty()){
// Take smallest element from set
        auto x = *(s.begin());
        s.erase(x);
        for(auto it : graph[x.second]){
            if(dist[it.first] > dist[x.second] + it.second){
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
    for(int i=1; i<n; i++){
        if(dist[i] < inf){
            cout << dist[i] << " ";
        }
        else{
            cout << -1 << " ";
        }
    }

    return 0;
}

/** --------------------------------STRIVER--------------------------------- */

int main()
{
    int n, m, source;
    cin >> n >> m;
    vector<pair<int, int>> g[n+1];

    int a, b, wt;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> wt;
        g[a].push_back({b, wt});
        g[b].push_back({a, wt});
    }
    cin >> source;

    // Dijkstra's algorithm begins from here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n+1, INT_MAX);

    distTo[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for(auto it: g[prev]) {
            int next = it->first;
            int nextDist = it->second;
            if(distTo[next] > distTo[prev] + nextDist) {
                distTo[next] = distTo[prev] + nextDist;
                pq.push({distTo[next], next});
            }
        }
    }

    cout << "Distances from source, " << source << " are: \n";
    for(int i=1; i<=n; i++)
        cout << distTo[i] << " ";
    cout<<"\n";

    return 0;
}
