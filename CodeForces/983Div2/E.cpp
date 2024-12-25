/**
*    author:  lazyhash(yashkundu)
*    created: 02 Nov, 2024 | 12:17:07
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

int n;
vector<ll> a, orig;
vector<ll> d2, d1; 
vector<ll> ans;
vector<ll> nv;


void solve() {
    cin >> n;
    orig.resize(n);
    a.resize(2*n);
    d1.resize(2*n);
    d2.resize(2*n);
    ans.resize(n);
    nv.resize(n);




    for(int i=0;i<n;i++) {
        cin >> orig[i];
        a[i+n] = a[i] = orig[i];
    }

    for(int i=0;i<2*n;i++) {
        if(i&1) a[i] *= -1;
    }

    // debug(a);

    for(int i=2*n-2;i>=0;i--) a[i] += a[i+1];

    // debug(a);


    for(int i=0;i<n;i++) {
        ll x = a[i] - a[i+n-1];
        if(i%2==0) x *= -1;
        d2[i] = x;
        d2[i+n] = x;
    }

    // debug(d2);


    for(int i=2*n-3;i>=0;i--) d2[i] += d2[i+2];

    // debug(d2);

    for(int i=0;i<n;i++) {
        int ind = (i+2)%n;
        // debug(i, ind, ind+n-1, d2[ind], d2[ind+n-1]);
        d1[i] = -1LL*(d2[ind] - d2[ind+n-1]);
    }

    // debug(d1);

    
    ans[0] = (ll)1e17;

    for(int i=1;i<n;i++) ans[i] = ans[i-1] + d1[i];

    // debug(ans);

    for(int i=0;i<n;i++) {
        int cur = i, prv = (i-1+n)%n, nxt = (i+1)%n;
        nv[i] = orig[i] + 2*ans[cur] + ans[prv] + ans[nxt];
    }

    for(int i=1;i<n;i++) {
        if(nv[i]!=nv[i-1]) {
            cout << "--1\n";
            return;
        }
    }


    for(int i=0;i<n;i++) cout << ans[i] << " ";
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