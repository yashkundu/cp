/**
*    author:  lazyhash(yashkundu)
*    created: 23 Nov, 2024 | 20:27:27
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

ll x;
ll m;

 
void solve() {
    cin >> x >> m;

    ll cnt = 0;

    int l = 32 - __builtin_clz(x);

    ll lim = (1<<l)-1;
    if(lim>m) lim = (int)m;


    for(ll y=1;y<=lim;y++) {
        ll num = y^x;
        if(num%x==0 || num%y==0) cnt++;
    }


    if(m<=x) {
        cout << cnt << '\n';
        return;
    }

    ll tm = m;

    for(int j=0;j<l;j++) {
        if((tm>>j)&1) tm -= (1<<j);
    }

    cnt += max(0LL, tm/x-1);

    if(!tm) {
        cout << cnt << '\n';
        return;
    }

    lim = (1<<l);

    for(ll y=1;y<lim;y++) {
        ll ty = tm^y;
        if(ty>m) break;
        ll num = ty^x;
        if(num%x==0 || num%ty==0) cnt++;
    }

    cout << cnt << '\n';



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