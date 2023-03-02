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
	int t,temp;
	cin >> t;

    string lamps;
	while(t--){
		cin >> temp;
        cin >> lamps;
        auto l = lamps.find_first_of('L');
        auto r = lamps.find_first_of('R');
        if(l != string::npos && r != string::npos){
            if(r<l){
                cout << 0 << endl;
            }else{cout << r << endl;}
        }else{
            cout << -1 << endl;
        }
	}
}