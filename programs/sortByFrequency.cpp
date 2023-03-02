#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define HIGH_PRIME 1000000009
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

struct myComp {
    constexpr bool operator()(
        pair<char, int> const& a,
        pair<char, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};

class Solution {
public:
    map<char, int> values;
    priority_queue<pair<char, int>, vector<pair<char,int>>, myComp> pque;
    string frequencySort(string s) {
        for (char& c : s) values[c]++;
        for (auto val : values) pque.push(pair<char,int>(val.first, val.second));
        string temp = "";
        while (!pque.empty()) {
            temp += string(pque.top().second, pque.top().first);
            pque.pop();
        }
        return temp;
    }
};

int main() {
    Solution s;
    cout << s.frequencySort("tree");
}