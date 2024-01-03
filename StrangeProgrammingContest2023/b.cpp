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
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map<char, char> mmap;
    string temp;

    mmap['A'] = 'T';
    mmap['B'] = 'G';
    mmap['C'] = 'O';
    mmap['D'] = 'S';
    mmap['E'] = 'Z';
    mmap['F'] = 'W';
    mmap['G'] = 'E';
    mmap['H'] = 'K';
    mmap['I'] = 'P';
    mmap['J'] = 'R';
    mmap['K'] = 'F';
    mmap['L'] = 'I';
    mmap['M'] = 'B';
    mmap['N'] = 'U';
    mmap['O'] = 'M';
    mmap['P'] = 'N';
    mmap['Q'] = 'Y';
    mmap['R'] = 'X';
    mmap['S'] = 'H';
    mmap['T'] = 'L';
    mmap['U'] = 'D';
    mmap['V'] = 'J';
    mmap['W'] = 'V';
    mmap['X'] = 'Q';
    mmap['Y'] = 'A';
    mmap['Z'] = 'C';
    

    while (getline(cin, temp)) {
        string changed = "";
        for (char c : temp) {
           if (mmap.find(c) != mmap.end()) changed += mmap[c];
           else changed += c;
        }
        cout << changed << endl;
    }

    return 0;
}