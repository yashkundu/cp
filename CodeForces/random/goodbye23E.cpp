/**
*    author:  lazyhash(yashkundu)
*    created: 29 Jun, 2024 | 09:57:28
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


vector<string> seq[100];

void init() {
    seq[1] = {"1"};
    seq[3] = {"169", "196", "961"};

    for(int i=5;i<=99;i+=2) {
        for(auto s: seq[i-2]) seq[i].push_back(s+"00");
        string zeros = "";
        for(int k=0;k<(i-3)/2;k++) zeros += "0";
        seq[i].push_back("1" + zeros + "6" + zeros + "9");
        seq[i].push_back("9" + zeros + "6" + zeros + "1");
    }
}

int n;
 
void solve() {
    cin >> n;
    for(string s: seq[n]) cout << s << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
    return 0;
}
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/