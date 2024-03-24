/**
*   author: lazyhash(yashkundu)
*   created: 18 Mar, 2024 | 07:07:48
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

const int N = 2e5+10;
int a[N];

const int M = 17;
const int inf = 1e9;

vector<int> v, preV;

int calcPersons(int x) {
    int p = 1;
    while(p<x) p = (p<<1);
    return p - x;
}

 
void solve() {
    int n;
    cin >> n;

    v.clear();
    preV.clear();

    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);


    for(int i=0;i<n;) {
        int j = i;
        while(j<n && a[j]==a[i]) j++;
        v.push_back(j-i);
        i = j;
    }

    preV.resize(v.size()+1, 0);
    for(int i=1;i<=v.size();i++) preV[i] = preV[i-1] + v[i-1];


    int ans = inf;

    int s = v.size();

    for(int i=0;i<=s;i++) {
        int k = 1;
        int p1 = calcPersons(preV[i]);
        for(int j=0;j<M;j++) {
            // (pre[i] + 2^j)
            auto it = upper_bound(preV.begin(), preV.end(), preV[i] + k);
            int ind = it - preV.begin() - 1;
            int p2 = calcPersons(preV[ind] - preV[i]);
            int p3 = calcPersons(preV[s] - preV[ind]);
            ans = min(ans, p1+p2+p3);
            k = (k<<1);
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/