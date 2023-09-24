/**
*   author: lazyhash(yashkundu)
*   created: 16 May, 2023 | 08:25:56
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> b(n*m);

    int max1 = -1e9, max2 = -1e9;
    int min1 = 1e9, min2 = 1e9;

    for(int i=0;i<n*m;i++) {
        cin >> b[i];
        if(b[i]>max1) {
            max2 = max1;
            max1 = b[i];
        } else if(b[i]>max2) max2 = b[i];
        if(b[i]<min1) {
            min2 = min1;
            min1 = b[i];
        } else if (b[i]<min2) min2 = b[i];
    }

    if(max1==max2 || min1==min2) {
        cout << (max1-min1)*(n*m-1) << "\n";
        return;
    }

    vector<int> v{max1, max2, min1, min2};
    int ans = -2e9-10;

    for(int i=0;i<4;i++) {
        vector<int> p;
        for(int j=0;j<4;j++) if(j!=i) p.push_back(v[j]);
        for(int j=0;j<3;j++) {
            vector<int> r;
            for(int k=0;k<3;k++) if(k!=j) r.push_back(p[k]);
            int d1 = max(r[0], p[j]) - min(r[0], p[j]);
            int d2 = max(r[1], p[j]) - min(r[1], p[j]);
            int cur = max(d1*(n-1)+d2*(m-1), d1*(m-1)+d2*(n-1)) + max(d1, d2)*(n*m-n-m+1);
            ans = max(ans, cur);
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