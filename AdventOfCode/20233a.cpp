#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;

#define ll long long
#define ld long double

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rep(i,n,c) for(int i = 0; i < n; i+=c)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<string> getFileContents(string filename) {
    ifstream file(filename);
    vector<string> lines;
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return lines;
    }

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

vector<string> splitString(const string& input, char delimiter) {
    vector<string> result;
    stringstream stream(input);
    string token;

    while (getline(stream, token, delimiter)) {
        result.push_back(token);
    }

    return result;
}

bool checkValidPart(pair<int, pii>& part, vector<vector<bool>>& symbols, int n, int m) {
    int y = part.second.first;
    int x = part.second.second;
    int length = to_string(part.first).length();

    int ybegin = y - 1, yend = y+1, xbegin = x-1, xend = x+length;

    for (int i = ybegin; i <= yend; i++) {
        for (int j = xbegin; j <= xend; j++) {
            if (j >= m) continue;
            if (i < 0) continue;
            if (j < 0) continue;
            if (i >= n) continue;
            //cout << n << ", " << m << ", " << i << ", " << j << endl;
            if (symbols[i][j]) return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> lines = getFileContents("test.txt");
    int rows = lines.size();
    int cols = lines[0].size();
    int total = 0;

    vector<pair<int, pii>> partPos;
    vector<vector<bool>> symbols(rows, vector<bool>(cols));

    for (int i = 0; i < lines.size(); i++) {
        string temp = "", line = lines[i];
        for (int j = 0; j < line.size(); j++) {
            if (line[j] == '.') {
                if (temp.size()) {
                    partPos.push_back(make_pair(stoi(temp), make_pair(i, j - temp.size())));
                    temp = "";
                }
            }
            else if (isdigit(line[j])) {
                temp += line[j];
            }
            else {
                if (temp.size()) {
                    partPos.push_back(make_pair(stoi(temp), make_pair(i,j - temp.size())));
                    temp = "";
                }
                symbols[i][j] = true;
            }
        }
        if (temp.size()) {
            partPos.push_back(make_pair(stoi(temp), make_pair(i, line.size() - temp.size())));
        }
    }

    for (auto& i : partPos) {
        if (checkValidPart(i, symbols, rows, cols)) {
            total += i.first;
        }
    }

    cout << "RESULT IS: " << total;
    return 0;
}