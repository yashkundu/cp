/**
*    author:  lazyhash(yashkundu)
*    created: 21 Jun, 2024 | 18:29:29
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

int n, m, k;
vector<int> a, d, f;
int del = 0;
int cnt = 0;


bool checkSum(int l, int r) {
    if(l>r) return false;
    int p1 = k, p2 = k;
    for(int i=0;i<k;i++) if(f[i]<=r) {
        p1 = i;
        break;
    }
    for(int i=0;i<k;i++) if(f[i]<l) {
        p2 = i;
        break;
    }
    if(p1==k) return false;
    for(int i=0;i<m;i++) {
        while(p1<k && f[p1]>r-d[i]) p1++;
        while(p2<k && f[p2]>=l-d[i]) p2++;
        if(p1<p2) return true;
    }
    return false;
}

bool check(int x) {
    cnt = 0;
    for(int i=1;i<n;i++) {
        del = a[i] - a[i-1];
        if(del>x) {
            if(cnt) return false;
            cnt++;
            if(!checkSum(max(a[i-1], a[i]-x), min(a[i-1]+x, a[i]))) return false;
        }
    }
    return true;
}


 
void solve() {
    cin >> n >> m >> k;

    a.resize(n), d.resize(m), f.resize(k);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> d[i];
    for(int i=0;i<k;i++) cin >> f[i];

    sort(d.begin(), d.end());
    sort(f.rbegin(), f.rend());

    int L = 0, R = 2e9+10;

    while(R-L>1) {
        int mid = (int)((1LL*L+R)/2);
        if(check(mid)) R = mid;
        else L = mid;
    }

    cout << R << "\n";




    
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