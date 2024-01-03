#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rep(i,n,c) for(int i = 0; i < n; i+=c)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int v,e; 
vector<vector<int>> adj; 

vector<bool> visited;
vector<int> tin, low;
set<int> cutpoints;
int timer;

void dfs(int verts, int p = -1) {
    visited[verts] = true;
    tin[verts] = low[verts] = timer++;
    int children=0;

    for (int to : adj[verts]) {
        if (to == p) continue;
        if (visited[to]) {
            low[verts] = min(low[verts], tin[to]); //Back edge, update vertex low
        } else {
            dfs(to, v);
            low[verts] = min(low[verts], low[to]); //Check if neighbour (not parent) had lower low
            if (low[to] >= tin[verts] && p!=-1) //Neighbour has higher low, thus current vertex is a cut vertice
                cutpoints.insert(verts);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cutpoints.insert(verts);
}

int main() {
    while(1){
        cin >> v >> e;
        timer = 0;
        if(v == 0 && e == 0) break;

        visited.assign(v, false);
        tin.assign(v, -1);
        low.assign(v, -1);
        adj.clear();
        adj.resize(v);
        cutpoints.clear();

        for (int i = 0; i < e; i++) {
            int f, t;
            cin >> f >> t;
            adj[--f].push_back(--t);
            adj[t].push_back(f);
        }

        for (int i = 0; i < v; ++i) if (!visited[i])dfs (i);
        cout << cutpoints.size() << endl;
    }
    return 0;
}