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

string simplify(string current){
    for(auto&c : current){
        switch(c){
            case '0':
                c = 'o';
                break;
            case 'I':
            case '1':
            case 'i':
                c = 'l';
                break;
        }
        c = tolower(c);
    }
    return current;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string login, temp;
    bool valid = true;
    int t;
    cin >> login;
    login = simplify(login);
    
    cin >> t;
    while(t--){
        cin >> temp;
        temp = simplify(temp);
        //cout << login << ", " << temp << endl;
        if(temp == login){
            valid = false;
        }
    }
    cout << ((valid)? "Yes" : "No") << endl;
    return 0;
}