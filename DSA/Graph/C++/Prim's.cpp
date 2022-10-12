#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

typedef std :: pair<int,int> PII;
typedef std :: vector<PII> VPII;

int Prims_MST (int source_node, std :: vector<VPII> & graph){

    // The priority_queue stores the pair<weight, node>
    std :: priority_queue<PII, std :: vector<PII>, std :: greater<PII>> q;

    // The cost of the source node to itself is 0
    q.push(std :: make_pair(0, source_node));

    bool added[graph.size()];
    memset(added, false, sizeof(bool)*graph.size());

    int mst_cost = 0;

    while (!q.empty()) {

        // Select the item <cost, node> with minimum cost
        PII item;
        item = q.top();
        q.pop();

        int node = item.second;
        int cost = item.first;

        // If the node is node not yet added to the minimum spanning tree add it, and increment the cost.
        if (!added[node]) {
            mst_cost += cost;
            added[node] = true;

            // Iterate through all the nodes adjacent to the node taken out of priority queue.
            // Push only those nodes (weight,node) that are not yet present in the minumum spanning tree.
            for (auto & pair_cost_node : graph[node]) {
                int adj_node = pair_cost_node.second;
                if (added[adj_node] == false) {
                    q.push(pair_cost_node);
                }
            }
        }
    }
    return mst_cost;
}

int main(){

    // Outgoing edges from the node:<cost, adjacent_node> in graph 1.
    VPII from_node_zero_in_graph_1  = { {1,1}, {2,2}, {1,3}, {1,4}, {2,5}, {1,6} };
    VPII from_node_one_in_graph_1   = { {1,0}, {2,2}, {2,6} };
    VPII from_node_two_in_graph_1   = { {2,0}, {2,1}, {1,3} };
    VPII from_node_three_in_graph_1 = { {1,0}, {1,2}, {2,4} };
    VPII from_node_four_in_graph_1  = { {1,0}, {2,3}, {2,5} };
    VPII from_node_five_in_graph_1  = { {2,0}, {2,4}, {1,6} };
    VPII from_node_six_in_graph_1   = { {1,0}, {2,2}, {1,5} };

    int num_nodes = 7; // Nodes (0, 1, 2, 3, 4, 5, 6)

    std :: vector<VPII> graph_1;
    graph_1.resize(num_nodes);

    graph_1[0] = from_node_zero_in_graph_1;
    graph_1[1] = from_node_one_in_graph_1;
    graph_1[2] = from_node_two_in_graph_1;
    graph_1[3] = from_node_three_in_graph_1;
    graph_1[4] = from_node_four_in_graph_1;
    graph_1[5] = from_node_five_in_graph_1;
    graph_1[6] = from_node_six_in_graph_1;

    // Start adding nodes to minimum spanning tree with 0 as the souce node
    std :: cout << "Cost of the minimum spanning tree in graph 1 : " << Prims_MST(0, graph_1) << std :: endl;

    // Outgoing edges from the node:<cost, adjacent_node> in graph 2.
    VPII from_node_zero_in_graph_2  = { {4,1}, {1,2}, {5,3} };
    VPII from_node_one_in_graph_2   = { {4,0}, {2,3}, {3,4}, {3,5} };
    VPII from_node_two_in_graph_2   = { {1,0}, {2,3}, {8,4} };
    VPII from_node_three_in_graph_2 = { {5,0}, {2,1}, {2,2}, {1,4} };
    VPII from_node_four_in_graph_2  = { {3,1}, {8,2}, {1,3}, {3,5} };
    VPII from_node_five_in_graph_2  = { {3,1}, {3,4} };

    num_nodes = 6; // Nodes (0, 1, 2, 3, 4, 5)

    std :: vector<VPII> graph_2;
    graph_2.resize(num_nodes);

    graph_2[0] = from_node_zero_in_graph_2;
    graph_2[1] = from_node_one_in_graph_2;
    graph_2[2] = from_node_two_in_graph_2;
    graph_2[3] = from_node_three_in_graph_2;
    graph_2[4] = from_node_four_in_graph_2;
    graph_2[5] = from_node_five_in_graph_2;

    // Start adding nodes to minimum spanning tree with 0 as the souce node
    std :: cout << "Cost of the minimum spanning tree in graph 2 : " << Prims_MST(0, graph_2) << std :: endl;
    return 0;
}
