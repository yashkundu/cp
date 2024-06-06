/**
*   author: lazyhash(yashkundu)
*   created: 17 May, 2024 | 20:22:13
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+10;
const int M = 20;
int lim[M];
int a[N];

int n;
 
void solve() {
    cin >> n;
    int initVal = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        initVal |= a[i];
    }



    int f = 1;
    for(int j=0;j<20;j++) {
        int cnt = 0;
        lim[j] = 0;
        for(int i=0;i<n;i++) {
            if(a[i]&f) cnt=0;
            else {
                cnt++;
                lim[j] = max(lim[j], cnt);
            }
        }
        f = f<<1;
    }


    int val = 0;
    for(int k=1;k<=n;k++) {
        val = val|a[k-1];
        if(val!=initVal) continue;
        int f = 1;
        bool good = true;
        for(int j=0;j<20;j++) {
            if((f&val) && lim[j]>=k) good = false; 
            f = f<<1;
        }
        if(good) {
            cout << k << "\n";
            return;
        }
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/