#include <bits/stdc++.h>
using namespace std;

/*
    The Earliest Moment When Everyone Become Friends
    --------------------------------------
    There are n people in a social group labeled from 0 to n - 1.
    You are given an array logs where each logs[i] = [timestamp_i, x_i, y_i] indicates that at time timestamp_i, 
    person x_i and person y_i became friends. Friendship is symmetric. That means if a is friends with b, and b 
    is friends with c, then a is also friends with c (directly or indirectly).
    Return the earliest time at which all people became friends (i.e., everyone is connected in a single group).
    If there is no such time, return -1.

    Constraints
    - 2 <= n <= 100
    - 1 <= logs.length <= 10^4
    - logs[i].length == 3
    - 0 <= timestamp_i <= 10^9
    - 0 <= x_i, y_i < n
    - x_i != y_i
    - All timestamps are unique

    Input:
    logs = [
        [20190101, 0, 1],
        [20190104, 3, 4],
        [20190107, 2, 3],
        [20190211, 1, 5],
        [20190224, 2, 4],
        [20190301, 0, 3],
        [20190312, 1, 2],
        [20190322, 4, 5]
    ]
    n = 6

    Output:
    20190301
*/

vector<int> groupIcon, rankOfSet;

void initSet(int n){
    groupIcon.resize(n);
    for(int i=0; i<n; i++) groupIcon[i] = i;

    rankOfSet.resize(n, 1);
}

int find(int u){
    if(groupIcon[u] == u) return u;
    return groupIcon[u] = find(groupIcon[u]);
}

bool unionSet(int u, int v){
    u = find(u);
    v = find(v);

    if(u != v){
        if(rankOfSet[u] < rankOfSet[v]){
            groupIcon[u] = v;
        }
        else if(rankOfSet[u] > rankOfSet[v]){
            groupIcon[v] = u;
        }
        else{
            groupIcon[v] = u;
            rankOfSet[u]++;
        }
        return true;
    }
    return false;
}


int main(){

    int n; cin>>n; //nodes
    initSet(n);

    int components = n;
    int ans = -1;

    int l; cin>>l; //logs
    vector<vector<int>> logs(l, vector<int>(3));

    for(int i = 0; i < l; i++){
        cin >> logs[i][0] >> logs[i][1] >> logs[i][2];
    }

    // SORT by timestamp
    sort(logs.begin(), logs.end());

    for(int i=0; i<l; i++){
        int a = logs[i][1];
        int b = logs[i][2];
        int t = logs[i][0];

        if(unionSet(a,b)){
            components--;
            if(components==1){
                ans = t;
                break;
            }
        }
    }
    cout<<"Ans is " << ans << endl;
    
    return 0;
}