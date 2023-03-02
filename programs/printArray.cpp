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

class Foo {
private:
    promise<bool> firstPromise;
    promise<bool> secondPromise;
public:
    Foo() {
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstPromise.set_value(true);
    }

    void second(function<void()> printSecond) {
        future<bool> secondWait = firstPromise.get_future();
        secondWait.wait();
        printSecond();
        secondPromise.set_value(true);

    }

    void third(function<void()> printThird) {
        future<bool> thirdWait = secondPromise.get_future();
        thirdWait.wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		;
	}
}