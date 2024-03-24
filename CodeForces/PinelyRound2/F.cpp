/**
*   author: lazyhash(yashkundu)
*   created: 19 Sep, 2023 | 00:02:40
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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




 
void solve() {
    int n;
    cin >> n;

    vector<ll> maskL(n, 0), maskR(n, 0);
    vector<bool> isLGood(n, 0), isRGood(n, 0);
    vector<ll> a(n);


    vector<ll> prefixA(n+1, 0);

    for(int i=0;i<n;i++){
        cin >> a[i];
        prefixA[i+1] = prefixA[i]^a[i];
    }



    for(int l=n;l>1;l--) {
        for(int i=0;i+l-1<n;i++) {
            int j = i+l-1;
            ll x = prefixA[j+1]^prefixA[i];
            if(l==n || isLGood[i] || (x&maskL[i])>0 || isRGood[j] || (x&maskR[j])>0) {
                // this subarray is reachable
                // add the msb of its xor to maskL[i]
                if(x) {
                    maskL[i] |= (1LL<<(63-__builtin_clzll(x)));
                    maskR[j] |= (1LL<<(63-__builtin_clzll(x)));
                } else {
                    isLGood[i] = isRGood[j] = 1;
                }
            }
        }
    }

    for(int i=0;i<n;i++) {
        if(isLGood[i] || isRGood[i] || (a[i]&maskL[i])>0 || (a[i]&maskR[i])>0 || n==1) cout << 1;
        else cout << 0;
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/