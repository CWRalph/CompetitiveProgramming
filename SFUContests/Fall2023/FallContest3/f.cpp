#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rep(i,n,c) for(int i = 0; i < n; i+=c)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int C,B,A;
    cin >> C >> B >> A;
    vector<pair<int,int>> ranges(3);
    vector<pair<int,int>> rangesOf2(2);

    for(int i = 0; i < 3; i++){
        int a,b;
        cin >> a >> b;
        ranges.push_back(make_pair(a,b));
    }

    std::sort(ranges.begin(), ranges.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    for(int i = 0; i < 2; i++){
        if(ranges[i].second > ranges[i+1].first){
            rangesOf2.push_back(make_pair(ranges[i+1].first, min(ranges[i].second, ranges[i+1].second)));
        }else{
            rangesOf2.push_back(make_pair(0,0));
        }
    }

    int overlap3 = (rangesOf2[0].second > rangesOf2[1].first)
        ? min(ranges[0].second, ranges[1].second) - ranges[1].first
        : 0;
    
    int overlap2 = std::accumulate(ranges.begin(), ranges.end(), 0, [](int currentSum, const std::pair<int, int>& pair) {
        return currentSum + (pair.second - pair.first);
    });

    int overlap3 = std::accumulate(ranges.begin(), ranges.end(), 0, [](int currentSum, const std::pair<int, int>& pair) {
        return currentSum + (pair.second - pair.first);
    });

    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < ranges[i].size() - 1; j++){
    //         ranges[i+1].push_back(make_pair(ranges[i][j].second, ranges[i][j+1].second - ranges[i][j].second));
    //     }
    // }

    // int overlap3 = std::accumulate(ranges[2].begin(), ranges[2].end(), 0, [](int currentSum, const std::pair<int, int>& pair) {
    //     return currentSum + (pair.second - pair.first);
    // });

    // int overlap2 = std::accumulate(ranges[1].begin(), ranges[1].end(), 0, [](int currentSum, const std::pair<int, int>& pair) {
    //     return currentSum + (pair.second - pair.first);
    // });

    // int overlap1 = std::accumulate(ranges[1].begin(), ranges[1].end(), 0, [](int currentSum, const std::pair<int, int>& pair) {
    //     return currentSum + (pair.second - pair.first);
    // });

    return 0;
}