/**
*   author: lazyhash(yashkundu)
*   created: 19 Feb, 2024 | 14:46:47
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
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


vector<vector<int>> pos(26, vector<int>());
vector<int> ptr(26, 0);

 
void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    for(int i=0;i<26;i++) {
        pos[i].clear();
        ptr[i] = 0;
    }

    for(int i=0;i<n;i++) {
        pos[s[i]-'a'].push_back(i);
    }

    // debug(pos);
    // debug(ptr);

    for(int i=0;i<m;i++) {
        int j = t[i]-'a';
        // debug(j, pos[j], ptr[j]);
        if(ptr[j]==pos[j].size()) {
            cout << "NO\n";
            return;
        }
        int indLim = pos[j][ptr[j]];
        ptr[j]++;
        for(int k=0;k<j;k++) {
            while(ptr[k]<pos[k].size() && pos[k][ptr[k]]<indLim) ptr[k]++;
        }
        // debug(ptr);
    }

    cout << "YES\n";


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