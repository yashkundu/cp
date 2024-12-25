/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jul, 2024 | 21:26:39
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
string s, ts;

int ans;

int calcInv(string s) {
    int cnt = 0;
    int res = 0;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') res += cnt;
        else cnt++;
    }
    return res;
}

 
void solve() {
    cin >> n >> k;
    cin >> s;


    ans = calcInv(s);


    for(int x=0;x<=k;x++) {
        int num1 = x;
        int num0 = k-x;
        ts = s;
        for(int i=0;i<n;i++) {
            if(ts[i]=='1' && num1) {
                ts[i] = '0';
                --num1;
            } 
        }
        for(int i=n-1;i>=0;i--) {
            if(ts[i]=='0' && num0>0) {
                ts[i] = '1';
                --num0;
            }
        }
        ans = min(ans, calcInv(ts));
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