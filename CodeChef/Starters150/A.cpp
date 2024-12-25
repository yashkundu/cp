/**
*    author:  lazyhash(yashkundu)
*    created: 04 Sep, 2024 | 20:03:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+10;

int n;
int freq[MAXN];

int x, y;
 
void solve() {  
    cin >> n;
    for(int i=1;i<=n;i++) freq[i] = 0;

    ll cur = 0;
    int mxf = 0;
    ll ans = 0;

    int del = 0;


    for(int i=0;i<n;i++) {
        cin >> x >> y;
        cur += freq[y];
        freq[y]++;
        mxf = max(freq[y], mxf);
        
        del = (n-i-1);
        ans = cur + 1LL*del*mxf + 1LL*del*(del-1)/2;
        cout << ans << " ";
    }

    cout << "\n";



    
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