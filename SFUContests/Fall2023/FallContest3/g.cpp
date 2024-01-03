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



int main() {
    int n,temp;
    cin >> n;
    while(n--){
        set<string> cities;
        cin >> temp;
        while(temp--){
            string s;
            cin >> s;
            cities.insert(s);
        }
        cout << cities.size() << endl;
    }
}