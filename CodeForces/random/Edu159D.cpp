/**
*    author:  lazyhash(yashkundu)
*    created: 01 Jul, 2024 | 15:14:49
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
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

const int MAXN = 200000 + 10;

int n, q;
string s;

int x, y, l, r;

map<pair<int, int>, vector<int>> fmp, rmp;
vector<pair<int, int>> fv, rv;


pair<int, int> convDir(char ch) {
    switch(ch) {
        case 'U':
            return {0, 1};
        case 'D':
            return {0, -1};
        case 'L':
            return {-1, 0};
        case 'R':
            return {1, 0};
        default:
          return {0, 0};
    }
    return {0, 0};
}


 
void solve() {
    cin >> n >> q;
    cin >> s;

    fmp.clear(), rmp.clear();
    fv.resize(n+1);
    rv.resize(n+2);

    fv[0] = {0, 0};
    for(int i=0;i<n;i++) {
        auto p = convDir(s[i]);
        fv[i+1] = {fv[i].first+p.first, fv[i].second+p.second};
    }

    for(int i=0;i<=n;i++) {
        if(!fmp.count(fv[i])) fmp[fv[i]] = vector<int>();
        fmp[fv[i]].push_back(i);
    }

    rv[n+1] = {0, 0};
    for(int i=n-1;i>=0;i--) {
        auto p = convDir(s[i]);
        rv[i+1] = {rv[i+2].first+p.first, rv[i+2].second+p.second};
    }

    for(int i=1;i<=n+1;i++) {
        if(!rmp.count(rv[i])) rmp[rv[i]] = vector<int>();
        rmp[rv[i]].push_back(i);
    }

    // debug(fv);
    // debug(rv);


    while(q--) {
        cin >> x >> y >> l >> r;
        if(fmp.count({x, y}) && (fmp[{x, y}].front()<l || fmp[{x, y}].back()>r)) {
            cout <<"YES\n";
            continue;
        }
        x = x - fv[l-1].first + rv[r+1].first;
        y = y - fv[l-1].second + rv[r+1].second;
        // debug(x, y);
        if(rmp.count({x, y})) {
            auto &v = rmp[{x, y}];
            auto it = lower_bound(v.begin(), v.end(), l);
            if(it!=v.end() && *it<=r) {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }






    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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