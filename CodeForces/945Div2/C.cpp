/**
*   author: lazyhash(yashkundu)
*   created: 18 May, 2024 | 10:42:02
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

const int N = 1e5+10;
int p[N];
int q[N];

int n;
 
void solve() {
    cin >> n;

    bool odd = true;

    for(int i=0;i<n;i++) {
        cin >> p[i];
        if(i%2==1 && i!=n-1 && p[i]==1) odd = false;
    }

    vector<pair<int, int>> good;
    vector<pair<int, int>> bad;

    for(int i=0;i<n;i++) {
        if(i==0 || i==n-1) {
            bad.push_back({p[i], i});
            continue;
        }
        bool isGood = (odd?i%2==1:i%2==0);
        if(isGood) good.push_back({p[i], i});
        else bad.push_back({p[i], i});
    }


    sort(good.rbegin(), good.rend());
    sort(bad.rbegin(), bad.rend());

    for(int i=0;i<bad.size();i++) {
        q[bad[i].second] = i+1;
    }

    for(int i=0;i<good.size();i++) {
        q[good[i].second] = n - n/2 + 2 + i;
    }

    for(int i=0;i<n;i++) cout << q[i] << " ";
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