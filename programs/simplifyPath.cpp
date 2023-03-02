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
    string simplifyPath(string path) {
        size_t index = path.find("//");

        while(index != string::npos){
            path.replace(index, 2, "/");
            index = path.find("//", index+1);
        }
        // if(path[path.length() - 1] == '/'){
        //     path.erase(path.end()-1, path.end());
        // }
        string temp = "";
        stack<string> directories;
        for(int i = 1; i < path.length(); i++){
            if(path[i] == '/'){
                if(temp == ".."){
                    directories.pop();
                }else{
                    directories.push(temp);
                }
                temp = "";
            }else temp += path[i];
        }
        temp = "";
        while(!directories.empty()){
            temp = '/' + directories.top() + temp;
            directories.pop();
        }
        return (temp == "")? "/" : "temp";
    }
};

int main() {
    Solution sol;
    cout << sol.simplifyPath("/../");
}