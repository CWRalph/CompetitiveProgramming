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

const int MAX_N = 001;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int dx[] = {-1,1,0,0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'L', 'R', 'U', 'D'};

int n,m;
vector<string> labyrinth(MAX_N);

bool checkPlayerWin(const int &row, const int &col){
    return ((row == 0 || row == n-1 || col == 0 || col == m-1) && labyrinth[row][col] == '.');
}

bool checkValid(const int &row, const int &col){
    return ((row >= 0 && row < n && col >= 0 && col < m) && labyrinth[row][col] == '.');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    vector<string> labyrinth(n);

    queue<pair<int,int>> pq;
    queue<pair<int,int>> mq;

    rep(i, 0, n){
        cin >> labyrinth[i];
    }

    rep(i, 0, n){
        rep(j, 0, n){
            if(labyrinth[i][j] == 'A') pq.push(make_pair(i,j));
            else if(labyrinth[i][j] == 'M') mq.push(make_pair(i,j));
        }
    }

    while(!pq.empty()){
        auto ppos = pq.front();pq.pop();
        int row = ppos.first;
        int col = ppos.second;
        labyrinth[ppos.first][ppos.second] = 'P';
        
        if(checkPlayerWin(row, col)){
            cout << "LETS GOO" << row << col << endl;
            break;
        }
        
        rep(i, 0, 4){
            int newRow = row + dy[i];
            int newCol = col + dx[i];
            if(checkValid(newRow, newCol)){
                pq.push({newRow, newCol});
            }
        }

        int mSize = mq.size();
        rep(i, 0, mSize){
            auto mpos = mq.front();mq.pop();
            int row = mpos.first;
            int col = mpos.second;
            labyrinth[mpos.first][mpos.second] = 'M';
            rep(i, 0, 4){
                int newRow = row + dy[i];
                int newCol = col + dx[i];
                if(checkValid(newRow, newCol)){
                    mq.push({newRow, newCol});
                }
            }
        }
    }

    return 0;
}