#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        size_t index = path.find("//");

        while (index != string::npos) {
            path.replace(index, 2, "/");
            index = path.find("//", index);
        }
        if(path[path.length() - 1] != '/'){
            path += '/';
        }
        string temp = "";
        stack<string> directories;
        for (int i = 1; i < path.length(); i++) {
            if (path[i] == '/') {
                if(temp == "."){}
                
                else if (temp == "..") {
                    if(!directories.empty()) directories.pop();
                }
                
                else {
                    directories.push(temp);
                }
                temp = "";
            }
            else temp += path[i];
        }
        temp = "";
        while (!directories.empty()) {
            temp = '/' + directories.top() + temp;
            directories.pop();
        }
        return (temp == "") ? "/" : temp;
    }
};