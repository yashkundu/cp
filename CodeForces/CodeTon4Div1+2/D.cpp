/**
*   author: lazyhash(yashkundu)
*   created: 31 Mar, 2023 | 20:50:45
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int q;
    cin >> q;
    ll l = 1, r = 8e18;

    while(q--) {
        int type;
        cin >> type;
        if(type==1) {
            ll a, b, n;
            cin >> a >> b >> n;
            // max((a-b)*(n-1) + 1, (a-b)*(n-2)+a+1) - (a-b)*(n-1)+a
            ll L = max((a-b)*(n-1) + 1, (a-b)*(n-2)+a+1);
            ll R = (a-b)*(n-1)+a;
            if(n==1) L = 1;
            ll new_l = max(l, L);
            ll new_r = min(r, R);
            if(new_l>new_r) {
                cout << "0\n";
            } else {
                cout << "1\n";
                l = new_l;
                r = new_r;
            }
        } else {
            ll a, b;
            cin >> a >> b;
            if(l<=a) {
                if(r<=a) {
                    cout << "1\n";
                } else {
                    cout << "-1\n";
                }
            } else {
                ll x = l-a-1;
                ll y = x/(a-b)*(a-b);
                y += a-b;
                if(y+a>=r) {
                    cout << (x/(a-b)) + 2 << "\n";
                } else {
                    cout << "-1\n";
                }
            }
            
            
                

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