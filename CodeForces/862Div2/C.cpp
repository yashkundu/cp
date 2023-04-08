/**
*   author: lazyhash(yashkundu)
*   created: 02 Apr, 2023 | 20:20:05
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
vector<int> a(N), b(N), c(N);
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> slopes(n);


    for(int i=0;i<n;i++) {
        int m;
        cin >> m;
        slopes[i] = {m, i};
    }

    for(int i=0;i<m;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    sort(slopes.begin(), slopes.end());

    debug(slopes);

    for(int i=0;i<m;i++) {
        ll k = 1LL*4*a[i]*c[i];
        if(k<=0) {
            cout << "No\n";
            continue;
        }
        int ind = upper_bound(slopes.begin(), slopes.end(), make_pair(b[i], n-1)) - slopes.begin();
        debug(i, ind, k);
        ll x1 = 1e18;
        if(ind<n) x1 = 1LL*(b[i]-slopes[ind].first)*(b[i]-slopes[ind].first);
        ll x2 = 1e18;
        if(ind>0) x2 = 1LL*(b[i]-slopes[ind-1].first)*(b[i]-slopes[ind-1].first);

        if(x1<k) {
            cout << "Yes\n";
            cout << slopes[ind].first << "\n";
        } else if(x2<k) {
            cout << "Yes\n";
            cout << slopes[ind-1].first << "\n";
        } else {
            cout << "No\n";
        }



    }




    

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