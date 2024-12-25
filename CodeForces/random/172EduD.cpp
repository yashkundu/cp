/**
*    author:  lazyhash(yashkundu)
*    created: 09 Dec, 2024 | 20:16:05
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
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

const int MAXN = (int)2e5+10;

int n;
map<int, vector<pair<int, int>>> lmp, rmp;
int lft[MAXN], rght[MAXN];

multiset<int> ms;
 
int l[MAXN], r[MAXN];

void solve() {
    cin >> n;
    fill(lft, lft+n, -1);
    fill(rght, rght+n, -1);

    lmp.clear(), rmp.clear();


    for(int i=0;i<n;i++) {
        cin >> l[i] >> r[i];
        if(!lmp.count(l[i])) lmp[l[i]] = vector<pair<int, int>>();
        lmp[l[i]].push_back({r[i], i});
        if(!rmp.count(r[i])) rmp[r[i]] = vector<pair<int, int>>();
        rmp[r[i]].push_back({l[i], i});
    }

    ms.clear();


    for(auto it=lmp.begin(); it!=lmp.end(); it++) {
        for(auto p: it->second) ms.insert(p.first);

        for(auto p: it->second) {
            ms.extract(p.first);
            auto iter = ms.lower_bound(p.first);
            if(iter!=ms.end()) rght[p.second] = *iter;
            ms.insert(p.first);
        }

    }

    ms.clear();

    for(auto it=rmp.rbegin(); it!=rmp.rend(); it++) {
        for(auto p: it->second) ms.insert(p.first);

        for(auto p: it->second) {
            ms.extract(p.first);
            auto iter = ms.upper_bound(p.first);
            if(iter!=ms.begin()) {
                iter--;
                lft[p.second] = *iter;
            }
            ms.insert(p.first);
        }
    } 

    for(int i=0;i<n;i++) {
        if(lft[i]==-1) {
            cout << "0\n";
            continue;
        }
        cout << rght[i] - lft[i] - (r[i]-l[i]) << "\n";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/