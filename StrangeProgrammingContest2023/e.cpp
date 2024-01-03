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

vector<string> words;
vector<pair<string, string>> sortedWords;

bool isWordValid(pair<string,string> w, const vector<bool>& allowed,const set<char>& contains,const vector<pair<int, char>>& positions, const set<char>& singles) {
    string intersec;
    for (const auto& c : w.first) {
        if (!allowed[c - 'a']) return false;
    }
    set_intersection(w.second.begin(), w.second.end(), contains.begin(), contains.end(), back_inserter(intersec));
    if (intersec.length() != contains.size()) return false;

    for (char i : singles) {
        if (count(w.first.begin(), w.first.end(), i) > 1) return false;
    }

    for (auto i : positions) { if (w.first[i.first] != i.second) return false; }
    return true;
}

void solve() {
    string result, current = words[0];
    vector<bool> allowed(40, true);
    vector<pair<int, char>> positions;
    set<char> singles, contains;
    vector<pair<string, string>> res, wcopy = sortedWords;

    cout << words[0] << endl;
    cin >> result;
    
    while (result != "*****") {
        rep(i, 5, 1) {
            if (result[i] == '*') positions.push_back(make_pair(i, current[i]));
            else if (result[i] == '-' || result[i] == '*') {
                contains.insert(current[i]);
            }
            else {
                if (count(current.begin(), current.end(), current[i]) > 1) {
                    singles.insert(current[i]);
                }
                else allowed[current[i] - 'a'] = false;
            }
        }
        res.clear();
        for (const auto& w : wcopy) { if (isWordValid(w, allowed, contains, positions, singles)) res.push_back(w); }

        wcopy = res;
        current = wcopy[10878273847923 % res.size()].first;        
        cout << current << endl;
        cin >> result;
    }
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    ifstream inputFile("words.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line)) {
        words.push_back(line);
    }
    inputFile.close();
    for (auto w : words) { 
        string temp = w;
        sort(w.begin(), w.end()); 
        sortedWords.push_back(make_pair(temp, w));
    }

    int n = 0, g;
    string output;
    cin >> n >> g;

    while (n--) {
        solve();
    }
    return 0;
}