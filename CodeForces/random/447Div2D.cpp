/**
*   author: lazyhash(yashkundu)
*   created: 01 Jun, 2024 | 14:32:33
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


const int N = 1e6+5;
int n, q;
int l[N];
int cur, ind;

ll ans = 0;

int v;
ll h;


vector<ll> sV[N];
vector<ll> prefV[N];


void merge(int v) {
    int left = 2*v, right = 2*v+1;
    sV[v].push_back(0LL);
    if(left>n) {
        return;
    }
    else if(right>n) {
        for(ll x: sV[left]) sV[v].push_back(x+l[left]);
        return;
    }
    int i = 0, j = 0;
    while(i<sV[left].size() || j<sV[right].size()) {
        if(i<sV[left].size() && (j==sV[right].size() || sV[left][i]+l[left]<=sV[right][j] + l[right])) sV[v].push_back(sV[left][i++] + l[left]);
        else sV[v].push_back(sV[right][j++] + l[right]);
    }
}


 
void solve() {
    cin >> n >> q;
    for(int i=2;i<=n;i++) cin >> l[i];


    for(int i=n;i>0;i--) merge(i);
    for(int i=1;i<=n;i++) {
        prefV[i].resize(sV[i].size()+1);
        prefV[i][0] = 0;
        for(int j=1;j<prefV[i].size();j++) prefV[i][j]= prefV[i][j-1] + sV[i][j-1];
    }


    while(q--) {
        cin >> v >> h;
        ans = 0;
        // inside the subtree

        auto it = upper_bound(sV[v].begin(), sV[v].end(), h);
        if(it!=sV[v].begin()) {
            it--;
            ind = it - sV[v].begin();
            ind++;
            ans += h*ind - prefV[v][ind];
        }


        // ancesstors
        cur = v;
        ll wt = 0;
        while(cur/2>0) {
            wt += l[cur];
            int sib = cur + (cur%2==0?1:-1);
            cur = cur/2;
            if(wt<h) {
                ans += (h-wt);
                if(sib<=n) {
                    auto it2 = upper_bound(sV[sib].begin(), sV[sib].end(), h-wt-l[sib]);
                    if(it2!=sV[sib].begin()) {
                        it2--;
                        ind = it2 - sV[sib].begin();
                        ind++;
                        ans += h*ind - (prefV[sib][ind] + 1LL*ind*(wt+l[sib]));
                    }
                }
            }
        }

        cout << ans << "\n";

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/