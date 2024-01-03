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



void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    vector<char> keys = {'v','i','k','a'};
    int index = 0, charIndex = 0;
    while(true){
        if(charIndex == 4){
            cout << "YES" << endl;
            return;
        }

        if(index == m){
            cout << "NO" << endl;
            return;
        }

        for(int i = 0; i < n; i++){
            if(grid[i][index] == keys[charIndex]){
                ++charIndex;
                break;
            }
        }
        ++index;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}