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
string abcs;

bool checkIsAbc(int& pos){
    switch(abcs[pos]){
        case 'a':
            if(pos < abcs.length() -2){
                return (abcs[pos+1] == 'b') && (abcs[pos+2] == 'c');
            }
            else return false;
        case 'b':
            if(pos < abcs.length() - 1 && pos > 0){
                return (abcs[pos-1] == 'a') && (abcs[pos+1] == 'c');
            }
            else return false;
        case 'c':
            if(pos > 1){
                return (abcs[pos-2] == 'a') && (abcs[pos-1] == 'b');
            }
            else return false;
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, current, count = 0, temp;
    char c;
	cin >> n >> q;
    cin >> abcs;
    size_t pos = abcs.find("abc");
    while(pos != string::npos){
        ++count;
        pos = abcs.find("abc",pos+1);
    }
	while(q--){
		cin >> temp;
        temp -= 1;
        cin >> c;
        if(c == abcs[temp]){
            cout << count << endl;
            continue;
        }
        //Check if this forms or breaks an abc
        if(checkIsAbc(temp)){count -= 1;}
        abcs[temp] = c;
        if(checkIsAbc(temp)){count += 1;}
        cout << count << endl;
	}
}