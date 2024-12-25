/**
*    author:  lazyhash(yashkundu)
*    created: 18 Sep, 2024 | 20:24:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)2e5+10;

int n, q;
int a[MAXN];
int cnt[MAXN][3];
int l, r;



 
void solve() {
    cin >> n >> q;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i]--;
        for(int j=0;j<3;j++) cnt[i+1][j] = cnt[i][j];
        cnt[i+1][a[i]]++;
    }

    while(q--) {
        cin >> l >> r;
        int del = (r-l+1);
        if(del&1) {
            cout << "NO\n";
            continue;
        }
        bool good = false;
        for(int j=0;j<3;j++) {
            if(cnt[r][j]-cnt[l-1][j]==del/2) good = true;
        }
        cout << (good?"YES\n":"NO\n");
    }


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