/**
*    author:  lazyhash(yashkundu)
*    created: 07 Sep, 2024 | 13:48:04
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
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

const int MAXN = (int)2e5+10;

int n;
vector<int> a;
int cnt[MAXN];
vector<int> inds[MAXN];

vector<pair<int, int>> v;
 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=1;i<=n;i++) {
        cnt[i] = 0;
        inds[i].clear();
    }

    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
        inds[a[i]].push_back(i);
    }

    v.clear();

    for(int i=1;i<=n;i++) {
        if(cnt[i]) v.push_back({cnt[i], i});
    }


    sort(v.begin(), v.end());

    // debug(v);

    int sz = v.size();

    int ptr = (sz-2+sz)%sz;

    // debug(ptr);

    for(int i=sz-1;i>=0;i--) {
        int x = v[i].second;
        // debug(i, x);
        while(cnt[x]) {
            // debug(cnt[x], ptr);
            if(inds[v[ptr].second].size()) {
                a[inds[v[ptr].second].back()] = x;
                inds[v[ptr].second].pop_back();
                cnt[x]--;
            } else ptr = (ptr-1+sz)%sz;
        }
    }

    for(int i=0;i<n;i++) cout << a[i] << " ";
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