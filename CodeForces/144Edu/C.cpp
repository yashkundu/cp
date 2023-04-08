/**
*   author: lazyhash(yashkundu)
*   created: 28 Feb, 2023 | 21:03:51
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int mod = 998244353;
 
 
void solve() {
    int l, r;
    cin >> l >> r;

    int cnt = 1;
    int x = l;
    while(x*2<=r) {
        x *= 2;
        cnt++;
    }
    
    int L = l;
    int del = (r-x)/(1<<(cnt-1));
    int R = l+del;

    ll ans = (R-L+1);

    debug(ans);

    if(cnt==1) {
        cout << cnt << " " << ans << "\n";
        return;
    }

    L--;
    while(L<R) {
        int mid = (L+R+1)/2;
        int last = mid*(1<<(cnt-2))*3;
        if(last<=r) {
            L = mid;
        } else {
            R = mid - 1;
        }
    }

    debug(L-l+1);

    ans += 1LL*(L-l+1)*(cnt-1)%mod;
    ans = ans%mod;

    cout << cnt << " " << ans << "\n";


    
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