/**
*   author: lazyhash(yashkundu)
*   created: 09 May, 2024 | 10:06:53
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

const int N = 5e5+10;
const int M = 20;
int a[N];
int freq[N] = {0};
vector<int> freqVal[N];

ll pref[N];
int ans[N];
 

int n, m, q;


vector<pair<int, pair<ll, int>>> queries;



struct BIT{
    int n;
    vector<int> tree;
    BIT(int n) {
        tree.resize(n+1);
        tree.assign(n+1, 0);
        this->n = n;
    }
    void update(int ind, int val) {
        for(;ind<=n;ind+=ind&(-ind)) {
            tree[ind] += val;
        }
    }
    int query(int ind) {
        int ans = 0;
        for(;ind>0;ind-=ind&(-ind)) ans += tree[ind];
        return ans;
    }
    int lower_bound(int x) {
        int ind = 0;
        int sum = 0;
        for(int p=(1<<M);p>0;p>>=1) {
            if(ind+p<=n && sum + tree[ind+p]<x) {
                ind = ind + p;
                sum += tree[ind];
            }
        }
        return ind+1;
    }
};


void solve() {
    cin >> n >> m >> q;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    for(int i=1;i<=m;i++) freqVal[freq[i]].push_back(i);

    pref[0] = 0;
    ll cur = 0;
    for(int f=0;f<n;f++) {
        cur += 1LL*freqVal[f].size();
        pref[f+1] = cur;
        pref[f+1] += pref[f];
    }


    for(int i=0;i<q;i++) {
        ll k;
        cin >> k;
        k -= n;
        int ind = lower_bound(pref, pref+n+1, k) - pref;
        queries.push_back({ind, {k, i}});
    }

    sort(queries.begin(), queries.end());


    BIT ftree(m);


    int curInd = 0;
    for(auto p: queries) {
        int ind = p.first;
        ll k = p.second.first;
        int origInd = p.second.second;
        
        if(ind==n+1) {
            k -= pref[ind-1];
            ans[origInd] = (k-1)%m + 1;
        } else {
            while(curInd<ind) {
                for(int v: freqVal[curInd]) {
                    ftree.update(v, 1);
                }
                curInd++;
            }
            k -= pref[ind-1];
            ans[origInd] = ftree.lower_bound(k);
        }
    }

    for(int i=0;i<q;i++) cout << ans[i] << "\n";

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