#include <iostream>
#include <set>
#include <queue>
#include <climits>
using namespace std;
 
// Below arrays detail all eight possible movements
// for a knight
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
 
// Check if (x, y) is valid chessboard coordinates.
// Note that a knight cannot go out of the chessboard
bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N) && (y >= 0 && y < N);
}
 
// A queue node used in BFS
struct Node
{
    // (x, y) represents chessboard coordinates
    // `dist` represents its minimum distance from the source
    int x, y, dist;
 
    // Node constructor
    Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
 
    // As we are using struct as a key in a `std::set`,
    // we need to overload `<` operator.
    // Alternatively, we can use `std::pair<int, int>` as a key
    // to store the matrix coordinates in the set.
 
    bool operator<(const Node& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};
 
// Find the minimum number of steps taken by the knight
// from the source to reach the destination using BFS
int findShortestDistance(int N, Node src, Node dest)
{
    // set to check if the matrix cell is visited before or not
    set<Node> visited;
 
    // create a queue and enqueue the first node
    queue<Node> q;
    q.push(src);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and process it
        Node node = q.front();
        q.pop();
 
        int x = node.x;
        int y = node.y;
        int dist = node.dist;
 
        // if the destination is reached, return distance
        if (x == dest.x && y == dest.y) {
            return dist;
        }
 
        // skip if the location is visited before
        if (!visited.count(node))
        {
            // mark the current node as visited
            visited.insert(node);
 
            // check for all eight possible movements for a knight
            // and enqueue each valid movement
            for (int i = 0; i < 8; i++)
            {
                // get the knight's valid position from the current position on
                // the chessboard and enqueue it with +1 distance
                int x1 = x + row[i];
                int y1 = y + col[i];
 
                if (isValid(x1, y1, N)) {
                    q.push({x1, y1, dist + 1});
                }
            }
        }
    }
 
    // return infinity if the path is not possible
    return INT_MAX;
}
 
int main()
{
    // N x N matrix
    int N = 8;
 
    // source coordinates
    Node src = {0, 7};
 
    // destination coordinates
    Node dest = {7, 0};
 
    cout << "The minimum number of steps required is " <<
            findShortestDistance(N, src, dest);
 
    return 0;
}
