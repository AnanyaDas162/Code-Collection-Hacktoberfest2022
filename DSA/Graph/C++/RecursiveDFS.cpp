#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS Traversal of an undirected and unweighted graph.
void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); 
} 

void RecursiveDFS(vector <int> adjList[], vector <bool> visitedVertex, int source){
  visitedVertex.at(source) = true;
  cout << source << " "; 
  for (vector<int>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
    if (!visitedVertex[*it])
      RecursiveDFS(adjList, visitedVertex, *it); 
} 

int main (void){
  const int numVertices = 5; 
  int source = 0;
  vector<int> adjList[numVertices]; 
  vector <bool> visitedVertex(numVertices, false);
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 3);
  createAndAddEdge(adjList, 1, 4);
  createAndAddEdge(adjList, 3, 3); 
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 2, 2);
  RecursiveDFS(adjList, visitedVertex, source);
  cout << endl;
}
