/**
*   author: lazyhash(yashkundu)
*   created: 12 Sep, 2023 | 09:55:41
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
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ans(n, vector<char>(m, '.'));
    
    // vertical dominos
    vector<pair<int, int>> v;

    // horizontal dominos
    vector<pair<int, int>> h;

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            if(s[j]=='U') v.emplace_back(i, j);
            else if(s[j]=='L') h.emplace_back(i, j);
        }
    }

    sort(v.begin(), v.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        if(p1.first!=p2.first) return p1.first<p2.first;
        return p1.second<p2.second;
    });

    sort(h.begin(), h.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        if(p1.second!=p2.second) return p1.second<p2.second;
        return p1.first<p2.first;
    });


    for(int i=0;i<v.size();) {
        int j = i;
        while(j<v.size() && v[j].first==v[i].first) j++;
        if((j-i)&1) {
            cout << "-1\n";
            return;
        }
        for(int k=i;k<j;k++) {
            auto [x, y] = v[k];
            ans[x][y] = ((k-i)&1)?'W':'B';
            ans[x+1][y] = ((k-i)&1)?'B':'W';
        }
        i = j;
    }


    for(int i=0;i<h.size();) {
        int j = i;
        while(j<h.size() && h[j].second==h[i].second) j++;
        if((j-i)&1) {
            cout << "-1\n";
            return;
        }
        for(int k=i;k<j;k++) {
            auto [x, y] = h[k];
            ans[x][y] = ((k-i)&1)?'W':'B';
            ans[x][y+1] = ((k-i)&1)?'B':'W';
        }
        i = j;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << ans[i][j];
        }
        cout << "\n";
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