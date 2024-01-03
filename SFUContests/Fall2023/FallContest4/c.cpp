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

const int MAX_N = 1000;
const int MAX_M = 1000;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n, m;
string labyrinth[MAX_N];

struct Node {
    int x, y, d;
    string path;

    bool operator>(const Node& other) const {
        return d > other.d;
    }
};

int dist[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char direc[] = { 'R', 'L', 'D', 'U' };

bool is_valid(int x, int y) {
    // Implement your validity check here based on grid boundaries or obstacles.
    // Return true if (x, y) is a valid cell to move to.
    return x >= 0 && x < MAX_N&& y >= 0 && y < MAX_N && labyrinth[y][x] != '#';
}

void dijkstra(int startx, int starty, int endx, int endy) {
    memset(dist, -1, sizeof(dist));
    memset(visited, false, sizeof(visited));

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({ startx, starty, 0, "" });
    dist[starty][startx] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        int x = node.x;
        int y = node.y;
        int d = node.d;

        if (visited[y][x]) continue;
        visited[y][x] = true;

        if (x == endx && y == endy) {
            cout << "YES" << endl;
            cout << d << endl;
            cout << node.path << endl;
            return;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int tempx = x + dx[dir];
            int tempy = y + dy[dir];

            if (is_valid(tempx, tempy) && (dist[tempy][tempx] == -1 || d + 1 < dist[tempy][tempx])) {
                dist[tempy][tempx] = d + 1;
                pq.push({ tempx, tempy, d + 1, node.path + direc[dir] });
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    cin >> n >> m;

    int start_x, start_y, end_x, end_y;
    for (int i = 0; i < n; ++i) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; ++j) {
            if (labyrinth[i][j] == 'A') {
                start_x = j;
                start_y = i;
            }
            if (labyrinth[i][j] == 'B') {
                end_x = j;
                end_y = i;
            }
            dist[i][j] = INT_MAX;
        }
    }

    dijkstra(start_x, start_y, end_x, end_y);
    return 0;
}