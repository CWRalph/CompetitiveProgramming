#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;

#define ll long long
#define ld long double

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rep(i,n,c) for(int i = 0; i < n; i+=c)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> lines = getFileContents("test.txt");
    int total = 0;

    vector<string> letternums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };



    for (auto line : lines) {
        vector<pii> numbers;
        for (int i = 0; i < letternums.size(); i++) {
            size_t pos = line.find(letternums[i]);
            while (pos != string::npos) {
                numbers.push_back(make_pair(pos, i + 1));
                pos = line.find(letternums[i], pos + 1);
            }
        }

        for (int i = 0; i < line.size(); i++) {
            if (isdigit(line[i])) numbers.push_back(make_pair(i, line[i] - '0'));
        }
        sort(numbers.begin(), numbers.end());

        total += 10 * numbers.front().second + numbers.back().second;
    }
    cout << total << endl;
    return 0;
}


bool containsAllSubstrings(const string& mainString, const vector<string>& substrings) {
    for (const auto& substring : substrings) {
        if (mainString.find(substring) == string::npos) {
            return false;
        }
    }
    return true;
}

//bool checkValidPassport(const string& passport) {
//    stringstream ss(passport);
//    string word;
//    while (ss >> word) {
//        string sub = word.substr(0, 3);
//        size_t colonPos, i, c;
//        int number;
//        string ending;
//        vector<string> validEyes = { "amb", "blu", "brn", "gry","grn", "hzl", "oth" };
//        bool found;
//
//
//        if (sub == "byr") {
//            colonPos = word.find(':');
//            number = stoi(word.substr(colonPos + 1));
//            if (number < 1920 || number > 2002) return false;
//        }
//        else if (sub == "iyr") {
//            colonPos = word.find(':');
//            number = stoi(word.substr(colonPos + 1));
//            if (number < 2010 || number > 2020) return false;
//        }
//        else if (sub == "eyr") {
//            colonPos = word.find(':');
//            number = stoi(word.substr(colonPos + 1));
//            if (number < 2020 || number > 2030) return false;
//        }
//        else if (sub == "hgt") {
//            ending = word.substr(word.size() - 2);
//            if (ending == "in") {
//                colonPos = word.find(':');
//                i = word.find('i');
//                number = stoi(word.substr(colonPos + 1, i));
//                if (number < 150 || number > 193) return false;
//            }
//            else if (ending == "cm") {
//                colonPos = word.find(':');
//                c = word.find('c');
//                number = stoi(word.substr(colonPos + 1, c));
//                if (number < 59 || number > 76) return false;
//            }
//            else return false;
//        }
//        else if (sub == "hcl") {
//            if (word.size() < 6) return false;
//            ending = word.substr(word.size() - 6);
//            for (char ch : word) {
//                if (!(ch >= 'a' && ch <= 'f') && !(ch >= '0' && ch <= '9')) return false;
//            }
//        }
//        else if (sub == "ecl") {
//            ending = word.substr(word.size() - 3);
//            found = false;
//            for (auto color : validEyes) {
//                if (ending == color) found = true;
//            }
//            if (!found) return false;
//        }
//        else if (sub == "pid") {
//            colonPos = word.find(':');
//            return word.substr(colonPos + 1).size() == 9;
//        }
//    }
//    return true;
//}