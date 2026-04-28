#include <bits/stdc++.h>
using namespace std;

/*
    25D. Roads not only in Berland
    --------------------------------------
    Berland Government decided to improve relations with neighboring countries. First of all, it was decided
    to build new roads so that from each city of Berland and neighboring countries it became possible to reach
    all the others. There are n cities in Berland and neighboring countries in total and exactly n - 1 two-way
    roads. Because of the recent financial crisis, the Berland Government is strongly pressed for money,
    so to build a new road it has to close some of the existing ones. Every day it is possible to close one
    existing road and immediately build a new one. Your task is to determine how many days would be needed to
    rebuild roads so that from each city it became possible to reach all the others, and to draw a plan of closure
    of old roads and building of new ones.

    Input
    --------------
    The first line contains integer n (2 ≤ n ≤ 1000) — amount of cities in Berland and neighboring countries.
    Next n - 1 lines contain the description of roads. Each road is described by two space-separated integers
    ai, bi (1 ≤ ai, bi ≤ n, ai ≠ bi) — pair of cities, which the road connects. It can't be more than one road
    between a pair of cities. No road connects the city with itself.

    Output
    --------------
    Output the answer, number t — what is the least amount of days needed to rebuild roads so that from each city
    it became possible to reach all the others. Then output t lines — the plan of closure of old roads and building
    of new ones. Each line should describe one day in the format i j u v — it means that road between cities i and j
    became closed and a new road between cities u and v is built. Cities are numbered from 1. If the answer is not
    unique, output any.

    Example
    --------------
    Input:7
        1 2
        2 3
        3 1
        4 5
        5 6
        6 7

    Output: 1
        3 1 3 7

*/

vector<int> parent, rankOfItem;

void initSet(int n){
    parent.resize(n+1);
    for(int i=0; i<=n; i++) parent[i]=i;

    rankOfItem.resize(n+1, 1);
}

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

bool unionSet(int u, int v){
    u = find(u); // to find the representative
    v = find(v); // to find the representative

    if(u != v){
        if(rankOfItem[u] < rankOfItem[v]){
            parent[u] = v;
        }
        else if(rankOfItem[u] > rankOfItem[v]){
            parent[v] = u;
        }
        else{
            parent [v] = u;
            rankOfItem[u]++;
        }

        return true; // union operation happened
    }

    return false;
}

int main(){

    int n; cin>>n;
    initSet(n);

    vector<pair<int, int>> pathToRemove;

    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;

        if(!unionSet(u, v)){
            pathToRemove.push_back({u, v});
        }
    }

    vector<int> representatives;
    for(int i=1; i<=n; i++){
        if(parent[i]==i)
            representatives.push_back(i);
    }

    if(pathToRemove.size() != representatives.size()-1){
        return -1;
    }

    cout<<pathToRemove.size()<<endl;

    for(int k=0; k<pathToRemove.size(); k++){
        int i = pathToRemove[k].first;
        int j = pathToRemove[k].second;
        int u = representatives[k];
        int v = representatives[k+1];

        printf("%d %d %d %d\n", i,j,u,v);
    }
    
    return 0;
}