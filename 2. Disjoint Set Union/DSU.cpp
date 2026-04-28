#include <bits/stdc++.h>
using namespace std;

/*
    What is Disjoint Set Union (DSU)?
    --------------------------------------
    Disjoint Set Union (DSU), also known as Union-Find, is a data structure that keeps track of a partition 
    of a set into disjoint subsets. It provides efficient operations for merging two subsets and finding 
    the representative (or "parent") of a subset. DSU is commonly used in algorithms that involve grouping elements,
    such as Kruskal's algorithm for finding the Minimum Spanning Tree (MST) of a graph, and in problems related 
    to connectivity and equivalence relations.

    Implementation of DSU:
    --------------------------------------
    The DSU data structure typically consists of two main components:
    1. An array (or vector) to store the parent of each element. 
       Initially, each element is its own parent, indicating that each element is in its own subset.
    2. An array (or vector) to store the size or rank of each subset. 
       This helps in optimizing the union operation by always attaching the smaller tree under the larger tree.

    Path Compression: This technique is used during the find operation to flatten the structure of the tree.
    When finding the representative of a subset, we make every node on the path point directly to the 
    representative, which speeds up future queries.

    Operations in DSU:
    --------------------------------------
    1. Find: This operation finds the representative (or parent) of the subset that an element belongs to.
       It uses path compression to flatten the structure of the tree, making future queries faster.
    2. Union: This operation merges two subsets into a single subset. It uses union by size or rank to keep 
       the tree shallow, optimizing the performance of future find operations.

    How to identify problems that can be solved using DSU?
    --------------------------------------
    Problems that can be solved using DSU typically involve:
    1. Grouping elements into disjoint subsets.
    2. Merging subsets based on certain conditions.
    3. Finding the representative of a subset to check if two elements belong to the same subset.
    4. Counting the number of distinct subsets or checking if two elements are in the same subset.
    5. Problems related to connectivity in graphs, such as checking if two nodes are in the same connected component.
*/

vector<int> parent, rankOfSet;

void build(int n){
    parent.resize(n+1);
    rankOfSet.resize(n+1, 1);

    for(int i=0; i<=n; i++) parent[i]=i;
}

int find(int n){
    if(n==parent[n]) return n;
    return parent[n] = find(parent[n]);
}

bool unionSet(int m, int n){
    m = find(m);
    n = find(n);

    if(m != n){
        if(rankOfSet[m] < rankOfSet[n]){
            parent[m] = n;
        }
        else if(rankOfSet[m] > rankOfSet[n]){
            parent[n] = m;
        }
        else{
            parent[n] = m;
            rankOfSet[m]++;
        }
        return true;
    }

    return false;
}

int main(){

    int n, q; // n = number of elements, q = number of queries
    cin >> n >> q;

    build(n);

    while(q--){
        int t, a, b; // t = type of query (1 for union, 2 for find), a and b are the elements to be processed
        cin >> t >> a >> b;

        if(t == 1){
            unionSet(a, b);
        }
        else{
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}