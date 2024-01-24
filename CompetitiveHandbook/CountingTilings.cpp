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

int n,m;
int tilings[1001][(1<<10)];

void fill_column(int column, int index, int curr_mask, int next_mask){
    if(index == n){
        tilings[column + 1][next_mask] = (
            tilings[column + 1][next_mask] + tilings[column][curr_mask]
        ) % MOD;
        return;
    }
    //Check if this actual tile is full, and the current mask by 1 shifted by the position in the column
    if((curr_mask)&(1<<index)) fill_column(column, index+1, curr_mask, next_mask);
    //Otherwise, possibility to put a horizontal tile
    else{
        fill_column(column, index + 1, curr_mask, next_mask|(1<<index));
        //If we are able to add a vertical tile, try adding it
        if(index + 1 < n && (!(curr_mask&(1<<(index + 1))))){
            fill_column(column, index+2, curr_mask, next_mask);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    tilings[0][0] = 1;
    //look over all possible columns and masks
    //If the mask is > 0, that means it is possible
    for(int column = 0; column < m; column++){
        for(int mask = 0; mask < (1 << n); mask++){
            if(tilings[column][mask] > 0){
                fill_column(column, 0, mask, 0);
            }
        }
    }
    cout << tilings[m][0];

    return 0;
}