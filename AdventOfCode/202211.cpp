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

struct Monkey {
    vector<long long> items;
    int tTarget, fTarget;
    function<bool(long long)> operation;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ifstream file("test.txt");
    vector<Monkey> monkeys;

    if(file.is_open()){
        string line;
        
        while(getline(file, line)){
            if(line.empty()){
                continue;
            }

            Monkey monkey;
            
        }
    }


    return 0;
}