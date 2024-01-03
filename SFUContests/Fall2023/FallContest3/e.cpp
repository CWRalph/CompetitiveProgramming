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



bool solve(const string& s) {
    stringstream ss(s);
    string word;
    set<string> existingWords;
    while(ss >> word){
        if(existingWords.count(word) > 0) return false;
        existingWords.insert(word);
    }
    return true;
}

int main() {
    string word;
    getline(cin, word);
    cout <<  (solve(word)? "yes":"no");
}