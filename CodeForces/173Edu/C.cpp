/**
*    author:  lazyhash(yashkundu)
*    created: 24 Dec, 2024 | 20:38:49
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
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



pair<ll, ll> find_max_min(vector<ll> a) {
    if(a.empty()) return {0, 0};
    ll mx = 0, mn = 0;
    ll n = a.size();


    set<ll> st;
    st.insert(0);

    ll sum = 0;
    for(int i=0;i<n;i++) {
        sum += a[i];
        ll first = *st.begin();
        ll second = *st.rbegin();
        mx = max(mx, sum-first);
        mn = min(mx, sum-second);
        st.insert(sum);
    }

    return {mn, mx};
}


int n;
vector<ll> a;

set<ll> ans;

 
void solve() {
    cin >> n;
    a.resize(n);
    ans.clear();
    ans.insert(0);

    int ind = -1;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]!=1 && a[i]!=-1) ind = i;
    }

    if(ind==-1) {
        auto [mn, mx] = find_max_min(a);
        // debug(mn, mx);
        for(ll i=mn;i<=mx;i++) ans.insert(i);
    } else {
        // debug(ind);
        vector<ll> v1, v2;
        for(int i=0;i<ind;i++) v1.push_back(a[i]);
        for(int i=ind+1;i<n;i++) v2.push_back(a[i]);
        pair<ll, ll> p = find_max_min(v1);
        // debug(p);
        for(ll i=p.first;i<=p.second;i++) ans.insert(i);
        p = find_max_min(v2);
        // debug(p);
        for(ll i=p.first;i<=p.second;i++) ans.insert(i);
        ll cur = 0;
        ll mx1 = 0, mn1 = 0;
        for(int i=ind+1;i<n;i++) {
            cur += a[i];
            mx1 = max(mx1, cur);
            mn1 = min(mn1, cur);
        }
        ll mx2 = 0, mn2 = 0;
        cur = 0;
        for(int i=ind-1;i>=0;i--) {
            cur += a[i];
            mx2 = max(mx2, cur);
            mn2 = min(mn2, cur);
        }
        ll mn = a[ind] + mn1 + mn2;
        ll mx = a[ind] + mx1 + mx2;
        // debug(mn, mx);

        for(ll i=mn;i<=mx;i++) ans.insert(i);
    }

    cout << ans.size() << "\n";
    for(ll x: ans) cout << x << " ";
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