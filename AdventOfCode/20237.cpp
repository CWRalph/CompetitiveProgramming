#include <bits/stdc++.h>
using namespace std;


vector<string> getFileContents(string filename) {
    ifstream file(filename);
    vector<string> lines;
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return lines;
    }

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

vector<string> splitString(const string& input, char delimiter) {
    vector<string> result;
    stringstream stream(input);
    string token;

    while (getline(stream, token, delimiter)) {
        result.push_back(token);
    }

    return result;
}

int scoreHand(const string& cards) {
    set<char> letters(cards.begin(), cards.end());
    vector<int> counts(6, 0);
    for (const auto& c : letters) 
        if(c != 'J') counts[count(cards.begin(), cards.end(), c)]++;
    
    int jcount = count(cards.begin(), cards.end(), 'J');
    
    counts[0] = 1;
    if (jcount) {
        for (int i = 5; i >= 0; i--) {
            if (counts[i]) {
                counts[i]--;
                counts[i + jcount]++;
                break;
            }
        }
    }

    for (int i = 5; i > 0; i--) {
        if (counts[i] > 1) return i * 10;
        else if (counts[i] && counts[i - 1]) return i * 10 - 1;
        else if (counts[i]) return i * 10 - 2;
    }
}

map<char, int> cardValues = {
        {'J', 1},
        {'T', 10},
        {'Q', 12},
        {'K', 13},
        {'A', 14}
};

int scoreCard(const char c) {
    if (cardValues.count(c)) {
        return cardValues[c];
    }
    else return c - '0';
}

struct Hand {
    string cards;
    int bet;
    int score;
    Hand(string cards, int bet, int score): cards(cards), bet(bet), score(score) {}
    
    friend bool operator<(const Hand& h1, const Hand& h2) {
        if (h1.score == h2.score) {
            for (int i = 0; i < h1.cards.length(); i++) {
                int s1 = scoreCard(h1.cards[i]), s2 = scoreCard(h2.cards[i]);
                if (s1 > s2) return false;
                if (s2 > s1) return true;
            }
            return false;
        }
        else {
            return h2.score > h1.score;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> lines = getFileContents("input.txt");
    vector<Hand> hands;

    for (const auto& line : lines) {
        vector<string> keys = splitString(line, ' ');
        hands.emplace_back(keys[0], stoi(keys[1]), scoreHand(keys[0]));
    }

    sort(hands.begin(), hands.end());


    long long total = 0;
    for (int i = 0; i < hands.size(); i++) {
        cout << hands[i].cards << endl;
        total += (long long)hands[i].bet * (long long)(i + 1);
    }
    cout << "Total is: " << total << endl;

    return 0;
}