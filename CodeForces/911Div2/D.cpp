/**
*   author: lazyhash(yashkundu)
*   created: 12 Dec, 2023 | 09:41:18
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
 
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

const int N = 1e5+10;
vector<int> factors[N];

int cnt[N];
int cnt2[N];

const int inf = 1e9+10;


void precompute() {
    for(int i=1;i<N;i++) {
        for(int j=i;j<N;j+=i) factors[j].push_back(i);
    }
    for(int i=0;i<N;i++) cnt2[i] = inf;
}
 
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());

    ll ans = 0;

    for(int i=0;i<n;i++) {
        for(int f: factors[a[i]]) cnt2[f] = 0;

        for(auto it=factors[a[i]].rbegin();it!=factors[a[i]].rend(); it++) {
            int f = *it;
            cnt2[f] += cnt[f];
            ans += 1LL*cnt2[f]*f*(n-i-1);
            for(int sF: factors[f]) if(cnt2[sF]!=inf) cnt2[sF] -= cnt2[f];
        }

        for(int f: factors[a[i]]) cnt2[f] = inf;

        for(int f: factors[a[i]]) cnt[f]++;
    }

    for(int x: a) for(int f: factors[x]) cnt[f] = 0;

    cout << ans << "\n";
    

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    precompute();
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