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

//First attempt gains one point (escape room)
//Ranked by total num of points, tie shares rank
//n participants w weeks
//Calculate average rank during w week competition

struct Player{
    int count, id, accumulateRank;
    Player(int passedId){
        count = 0;
        id = passedId;
        accumulateRank = 0;
    }
};
bool compareByCount(const Player &a, const Player &b)
{
    return a.count < b.count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w, inputs, temp;
	cin >> n >> w;
    vector<Player> players;
    for(int i = 0; i < n; i++){players.push_back(Player(i+1));}

	for(int j = 0; j < w; j++){
		cin >> inputs;
        while(inputs--){
            cin >> temp;
            ++players[temp-1].count;
        }
        sort(players.begin(),players.end(), compareByCount);
        int currentCount = -1, currentRank = 1, totalRank = 1;
        for(int i = 0; i < players.size(); i++){
            if(players[i].count == currentCount){
                players[i].accumulateRank += currentRank;
            }else{
                players[i].accumulateRank += totalRank;
                currentRank = totalRank;
                currentCount = players[i].count;
            }
            ++totalRank;
        }
	}
    for(Player& p : players){
        cout << ((double)p.accumulateRank) / w;
    }
    return 0;
}