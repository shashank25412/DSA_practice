#include <bits/stdc++.h>
using namespace std;

/*
    Graph
    ------
    A non-linear data structure consisting of nodes and edges that connects these nodes to represent
    relationship.

    - Graph can be represented in memory in 2 ways:
        1. Adjecency list
        2. Adjecency matrix

    - Graph traversal algorithms:
        1. DFS (Depth first search): Explores as deep as possible from a node, before backtrack.
        2. BFS (Breadth first search): Traverse a graph layer by layer.

    Problem statement
    ------------------
    Given an adjecency list, traverse the graph in both DFS and BFS way.
*/

// Recursive
void DFS(vector<vector<int>> &graph, vector<int> &visited, int node){
    visited[node] = 1;
    cout<<node<<"=>";

    //recursively visit all the adjacent vertices that are not visited
    for(auto el: graph[node]){
        if(!visited[el])
            DFS(graph, visited, el);
    }
}

// Iterative
void DFS(vector<vector<int>> &graph){
    int vertices = graph.size();
    vector<int> visited(vertices, 0);

    stack<int> aStack;
    aStack.push(0); // insert the 1st element
    visited[0] = 1; // mark it visited

    while (!aStack.empty()) {
        int tmp = aStack.top();
        aStack.pop();

        cout<<tmp<<"=>";

        for(auto el: graph[tmp]){
            if(!visited[el]){
                // mark the node visited
                visited[el] = 1;
                aStack.push(el);
            }
        }
    }
}

int main() {

    //               1
    //              / \
    //             0---2
    //                / \
    //               3   4

    int vertices, edges;
    cin>>vertices>>edges;

    vector<vector<int>> graph(vertices);

    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(vertices, 0);
    // DFS(graph, visited, 0);
    DFS(graph);

    return 0;
}