/**
*    author:  lazyhash(yashkundu)
*    created: 05 Oct, 2024 | 01:30:12
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
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

const int MAXN = (int)2e5+10;
int t[4*MAXN];

int n;
int a[MAXN];
int ans[MAXN];
vector<pair<int, int>> segs;


void build(int v, int tl, int tr) {
    if(tl==tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(2*v+1, tl, tm);
    build(2*v+2, tm+1, tr);
    t[v] = gcd(t[2*v+1], t[2*v+2]);
}


int query(int v, int tl, int tr, int l, int r) {
    if(l>r) return 0;
    if(tl==l && tr==r) return t[v];
    int tm = (tl+tr)/2;
    int a = query(2*v+1, tl, tm, l, min(r, tm));
    int b = query(2*v+2, tm+1, tr, max(tm+1, l), r);
    return gcd(a, b);
}

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    segs.clear();


    build(0, 0, n-1);

    for(int i=0;i<n;i++) {
        int L = i, R = n;
        while(R-L>1) {
            int mid = (L+R)/2;
            if(query(0, 0, n-1, i, mid)>=mid-i+1) L = mid;
            else R = mid;
        }
        if(query(0, 0, n-1, i, L)==L-i+1) segs.push_back({i, L});
    }

    sort(segs.begin(), segs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second<p2.second;
    });


    fill(ans, ans+n, 0);

    int cur = -1;
    int cnt = 0;
    for(auto p: segs) {
        if(p.first>cur) {
            cnt++;
            ans[p.second] = cnt;
            cur = p.second;
        }
    }


    cur = 0;
    for(int i=0;i<n;i++) {
        if(ans[i]) cur = ans[i];
        else ans[i] = cur;
    }


    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";



    
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