/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jun, 2024 | 17:43:43
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 11;
int val[N];


int n, m;
string s;

int convert(string s) {
    int x = 0;
    for(int i=0;i<m;i++) {
        if(s[i]=='o') x += (1<<i);
    }
    return x;
}
 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> s;
        val[i] = convert(s);
    }

    int ans = 20;
    for(int mask=0;mask<(1<<n);mask++) {
        int x = 0;
        int cnt = 0;
        for(int j=0;j<n;j++) {
            if((mask>>j)&1) {
                cnt++;
                x |= val[j];
            }
        }
        if(x==((1<<m)-1)) ans = min(ans, cnt);
    }

    cout << ans << "\n";

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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