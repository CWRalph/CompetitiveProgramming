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

struct Monkey {
    vector<long long> items;
    int tTarget, fTarget;
    long long inspections = 0;
    function<bool(long long)> test;
    function<long long(long long)> operation;
};

long long superModulo;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream file("test.txt");
    vector<Monkey> monkeys;

    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            if (line.empty()) {
                continue;
            }

            Monkey monkey;

            //GET THE ITEMS
            getline(file, line);
            size_t pos = line.find(":") + 2;
            stringstream itemList(line.substr(pos));
            string token;
            
            while (getline(itemList, token, ',')) {
                size_t start = token.find_first_not_of(" \t\n\r");
                size_t end = token.find_last_not_of(" \t\n\r");
                monkey.items.push_back(stoll(token.substr(start, end - start + 1)));
            }

            //GET THE OPERATION
            getline(file, line);
            pos = line.find("old") + 4;
            string op = line.substr(pos, 1);
            string a = line.substr(pos+2);

            if (op == "*") {
                if (a == "old") {
                    monkey.operation = [](long long old) {return old * old; };
                }
                else {
                    long long amount = stoll(a);
                    monkey.operation = [amount](long long old) {return old * amount; };
                }
            }
            else {
                if (a == "old") {
                    monkey.operation = [](long long old) {return old + old; };
                }
                else {
                    long long amount = stoll(a);
                    monkey.operation = [amount](long long old) {return old + amount; };
                }
            }
            
            getline(file, line);
            pos = line.find("by") + 3;
            
            long long divisible = stoll(line.substr(pos));

            monkey.test = [divisible](long long old) {return old % divisible == 0; };
            superModulo += divisible;

            getline(file, line);
            pos = line.find("monkey") + 7;
            monkey.tTarget = stoi(line.substr(pos));

            getline(file, line);
            pos = line.find("monkey") + 7;
            monkey.fTarget = stoi(line.substr(pos));

            monkeys.push_back(monkey);
        }
        
        int n = 10000;
        while (n--) {
            for (Monkey& m : monkeys) {
                for (auto item : m.items) {
                    m.inspections++;
                    long long newVal = m.operation(item);

                    newVal %= superModulo;

                    if (m.test(newVal)) {
                        monkeys[m.tTarget].items.push_back(newVal);
                    }
                    else {
                        monkeys[m.fTarget].items.push_back(newVal);
                    }
                }
                m.items.clear();
            }
        }
        sort(monkeys.begin(), monkeys.end(), [](const Monkey& a, const Monkey& b) {
            return a.inspections > b.inspections;
        });
        cout << "Product of max inspections is: " << monkeys[0].inspections << ", " <<  monkeys[1].inspections << ", " << monkeys[0].inspections * monkeys[1].inspections << endl;
    }


    return 0;
}