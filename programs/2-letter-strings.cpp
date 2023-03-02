#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,temp, sum = 0;
    char a, b;
	cin >> t;

    //Sum the column and row and subtract the exactly matching square
	while(t--){
		cin >> temp;
        sum = 0;
        vector<vector<int>> positions(12, vector<int>(12, 0));
        vector<int> col(12,0), row(12,0);
        while(temp--){
            cin >> a >> b;
            a-='a';
            b-='a';
            sum += col[a] + row[b] - (2*positions[b][a]);
            col[a]++;
            row[b]++;
            positions[b][a]++;
        }
        cout << sum << endl;
	}
}