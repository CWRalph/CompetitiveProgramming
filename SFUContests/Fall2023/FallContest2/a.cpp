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

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v != parent[v]) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
            return true;
        }
        else return false;
    }
};

int main() {
    int n, m, x, y;
    cin >> n >> m;
    vector<pii> newRoads;
    UnionFind uf(n);
    while (m--) {
        cin >> x >> y;
        uf.unionSets(x-1, y-1);
    }
    for (int i = 1; i < n; i++) {
        if (uf.unionSets(i - 1, i)) newRoads.push_back(make_pair(i - 1, i));
    }
    cout << newRoads.size() << endl;
    for (auto i : newRoads) {
        cout << i.first + 1 << " " << i.second + 1 << endl;
    }
}