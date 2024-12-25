/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jun, 2024 | 14:35:53
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
vector<bool> v, t;
string s;
int cnt = 0;
int len = 0;


int calc(int l, int r) {
    len = r-l;
    cnt = 0;
    for(int i=0;i<len;i++) t[i] = 0;
    for(int i=0;i<len;i++) {
        if(v[i+l]) {
            if(i>0 && t[i-1]) continue;
            if(t[i]) continue;
            cnt++;
            t[i+1] = 1;
        }
    }
    return cnt;
}


 
void solve() {
    cin >> n;
    v.resize(n+1);
    t.resize(n+1);
    cin >> s;

    for(int i=0;i<n;i++) v[i] = s[i]=='1';


    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<=n;j++) ans += calc(i, j);
    }

    cout << ans << "\n";




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