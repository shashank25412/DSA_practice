#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &graph){
    int vertices = graph.size();
    vector<int> visited(vertices, 0);

    queue<int> aQueue;
    aQueue.push(0);
    visited[0] = 1;

    while (!aQueue.empty())
    {
        int tmp = aQueue.front();
        aQueue.pop();

        cout<<tmp<<"=>";

        for(auto el: graph[tmp]){
            if(!visited[el]){
                visited[el] = 1;
                aQueue.push(el);
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

    BFS(graph);

    return 0;
}