/**
*    author:  lazyhash(yashkundu)
*    created: 04 Aug, 2024 | 20:06:59
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
string s;

int cnt[4];
int qm;

void solve() {
    cin >> n;
    cin >> s;

    for(int i=0;i<4;i++) cnt[i] = 0;
    qm = 0;
    for(int i=0;i<4*n;i++) {
        if(s[i]=='?') qm++;
        else cnt[s[i]-'A']++;
    }

    int left = 0;
    int correct = 0;
    for(int i=0;i<4;i++) {
        correct += min(n, cnt[i]);
        left += max(0, n-cnt[i]);
    }

    cout << correct << '\n';





}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
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