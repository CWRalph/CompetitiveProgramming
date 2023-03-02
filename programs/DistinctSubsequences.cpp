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

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> positions(t.length(), vector<int>(s.length() + 1, 0));
        for(int row = 0; row < t.length(); row++){
            for(int col = 1; col <= s.length(); col++){
                if(s[col-1] == t[row]){
                    //Characters match, add including it vs not including it
                    positions[row][col] = positions[row-1][col-1] + positions[row][col-1];
                }else{
                    positions[row][col] = positions[row][col-1];
                }
            }
        }
        return positions[t.length()-1][s.length()];
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
    cout << s.numDistinct("rabbbitt", "rabbit");
}