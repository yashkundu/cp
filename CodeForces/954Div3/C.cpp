/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jun, 2024 | 20:38:43
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

int n, m;
string s, t;
vector<int> inds;
vector<int> ans;
 
multiset<int> ms;

void solve() {
    cin >> n >> m;
    cin >> s;

    ms.clear();
    inds.resize(m);
    ans.resize(m);

    fill(ans.begin(), ans.end(), -1);

    for(int i=0;i<m;i++) cin >> inds[i];
    cin >> t;

    sort(inds.begin(), inds.end());

    for(int i=0;i<m;i++) ms.insert(t[i]-'a');


    for(int i=0;i<m;) {
        int j = i;
        while(j<m && inds[j]==inds[i]) j++;
        ans[j-1] = *ms.begin();
        ms.erase(ms.begin());
        i = j;
    }

  

    for(int i=0;i<m;i++) {
        if(ans[i]==-1) {
            ans[i] = *ms.begin();
            ms.erase(ms.begin());
        }
    }


    for(int i=0;i<m;i++) {
        s[inds[i]-1] = (char)('a'+ans[i]);
    }

    cout << s << "\n";









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