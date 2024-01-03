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

int v, e;
vector<vector<int>> adj;

vector<bool> visited;
vector<int> tin, low;
vector<pii> bridges;
int timer;

void dfs(int verts, int p = -1) {
    visited[verts] = true;
    tin[verts] = low[verts] = timer++;
    int children = 0;

    for (int to : adj[verts]) {
        if (to == p) continue;
        if (visited[to]) {
            low[verts] = min(low[verts], tin[to]);
        }
        else {
            dfs(to, verts);
            low[verts] = min(low[verts], low[to]);
            if (low[to] > tin[verts]) //Neighbour has higher low, must be no back edge
                bridges.push_back(make_pair(verts, to));
            ++children;
        }
    }
}

int main() {
    while (cin >> v && !cin.eof()) {
        timer = 0;

        visited.assign(v, false);
        tin.assign(v, -1);
        low.assign(v, -1);
        adj.clear();
        adj.resize(v);
        bridges.clear();

        for (int i = 0; i < v; i++) {
            int count, n, temp;
            char c;
            cin >> n >> c >> count >> c;
            rep(j, count, 1) {
                cin >> temp;
                adj[n].push_back(temp);
            }
        }

        for (int i = 0; i < v; ++i) 
            if (!visited[i])dfs(i);
        cout << bridges.size() << " critical links" << endl;
        
        sort(bridges.begin(), bridges.end(), [](const pii& a, const pii& b) {
            return a.first < b.first;
        });

        for (const pii& i : bridges) {
            cout << i.first << " - " << i.second << endl;
        }
    }
    return 0;
}