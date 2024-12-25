/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jun, 2024 | 18:49:00
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

const int MAXN = 2e5+10;
pair<int, int> v[MAXN];
bool good[MAXN];
int inds[MAXN];
int p[MAXN];

int n; 


void solve() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v, v+n, [](const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first>p2.first;
    });

    for(int i=0;i<n;i++) inds[v[i].second] = i;

    ll mxStr = 0;
    int mnMus = 1e9;


    for(int i=0;i<n;i++) {
        cin >> p[i];
        p[i]--;
        p[i] = inds[p[i]];
    }
    for(int i=0;i<n;i++) good[i] = 1;


    int cnt = 0;
    int j = 0;
    for(int i=0;i<n;i++) {
        while(j<n && cnt<i+1) {
            if(good[j]) cnt++;
            j++;
        }
        if(cnt==i+1) {
            ll val = 1LL*v[j-1].first*cnt;
            if(val>mxStr) {
                mxStr = val;
                mnMus = cnt;
            } else if(val==mxStr) mnMus = min(mnMus, cnt);
        }
        good[p[i]] = 0;
        if(p[i]<j) cnt--;
    }

    cout << mxStr << " " << mnMus << "\n";



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