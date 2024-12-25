/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jun, 2024 | 15:44:03
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
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

const int MAXN = 2e5+10;
ll a[MAXN];
int ans[MAXN];
ll suf[MAXN];

set<int> st;

int n;
ll c;
 
vector<pair<ll, int>> v;

void solve() {
    cin >> n >> c;
    v.clear();
    st.clear();

    for(int i=0;i<n;i++) st.insert(i);

    for(int i=0;i<n;i++) ans[i] = n;


    for(int i=0;i<n;i++) {
        cin >> a[i];
        v.push_back({-a[i], i});
    }

    sort(v.begin(), v.end());

    ll sum = 0;
    int minNum = 0;
    for(int i=0;i<n;i++) {
        minNum = *st.begin();
        if(minNum>=v[i].second) continue;
        if(sum+a[minNum]+c<(-v[i].first)) ans[v[i].second] = i;
        st.erase(v[i].second);
        sum += v[i].first*-1; 
    }

    suf[n] = 0;
    for(int i=n-1;i>=0;i--) {
        suf[i] = suf[i+1];
        suf[i] = max(suf[i], a[i]);
    }

    sum = 0;
    for(int i=0;i<n;i++) {
        if(suf[i]<=a[i]+sum+c) {
            ans[i] = min(ans[i], i);
        } else {
            ans[i] = min(ans[i], i+1);
        }
        sum += a[i];
    }

    for(int i=0;i<n;i++) {
        cout << ans[i] << " ";
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