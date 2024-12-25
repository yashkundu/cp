/**
*    author:  lazyhash(yashkundu)
*    created: 11 Oct, 2024 | 08:46:00
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
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

const int MAXN = (int)2005;
const ll inf = (ll)1e18+1000;

ll cnt[MAXN];

int n, k;
ll x;
string s;

vector<pair<char, int>> v;

ll mul(ll a, ll b) {
    if(a>inf/b) return inf;
    return a*b;
}
 
void solve() {
    cin >> n >> k >> x;
    cin >> s;



    v.clear();
    for(int i=0;i<n;i++) {
        if(!v.empty() && v.back().first==s[i]) v.back().second += 1;
        else v.push_back({s[i], 1});
    }


    cnt[v.size()] = 1;

    for(int i=v.size()-1;i>=0;i--) {
        if(v[i].first=='a') cnt[i] = cnt[i+1];
        else {
            ll res = cnt[i+1];
            res = mul(res, v[i].second*k+1);
            cnt[i] = res;
        } 
    }


    string ans = "";
    ll cur = x-1;

    for(int i=0;i<v.size();i++) {
        if(v[i].first=='a') {
            for(int j=0;j<v[i].second;j++) ans += 'a';
        } else {
            ll num = cur/cnt[i+1];
            assert(num<=k*v[i].second);
            for(int j=0;j<num;j++) ans += 'b';
            cur -= cnt[i+1]*num;
        }
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