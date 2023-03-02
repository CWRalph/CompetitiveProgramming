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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
    string temp;
    map<int,char> positions;
	for(int i = 0; i < t; i++){
		cin >> temp;
        for(int j = 0; j < temp.length(); j++){
            if(positions.find(j) == positions.end()){
                positions[j] = (temp[j] == '?') ? 'c': temp[j];
            }else if(positions[j] != '?'){
                positions[j] = (positions[j] == temp[j])? temp[j] : '?';
            }
        }
	}
    temp = "";
    for(auto& c : positions){
        temp += c.second;
    }
    cout << temp;
}