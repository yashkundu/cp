/**
*    author:  lazyhash(yashkundu)
*    created: 03 Aug, 2024 | 22:53:35
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

const int MAXN = 250000 + 100;

int n;
int a[MAXN];

int pmx[MAXN], pmn[MAXN];
int smx[MAXN], smn[MAXN];

int ops = 0;
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    if(n==1) {
        cout << "0\n";
        return;
    }

    pmx[0] = pmn[0] = 0;
    for(int i=1;i<n;i++) {
        if(a[i]>a[pmx[i-1]]) pmx[i] = i;
        else pmx[i] = pmx[i-1];
        if(a[i]<a[pmn[i-1]]) pmn[i] = i;
        else pmn[i] = pmn[i-1];
    }

    smx[n-1] = smn[n-1] = n-1;
    for(int i=n-2;i>=0;i--) {
        if(a[i]>smx[i+1]) smx[i] = i;
        else smx[i] = smx[i+1];
        if(a[i]<smn[i+1]) smn[i] = i;
        else smn[i] = smn[i+1];
    }

    int first = -1, second = -1;
    for(int i=0;i<n;i++) {
        if(a[i]==1 || a[i]==n) {
            if(first==-1) first = i;
            else second = i;
        }
    }

    int *x = (a[first]==1)?pmx:pmn;
    int *y = (a[first]==1)?pmn:pmx;

    ops = 0;
    while(first>0) {
        ops++;
        first = x[first-1];
        swap(x, y);
    }

    x = (a[second]==n)?smn:smx;
    y = (a[second]==n)?smx:smn;

    while(second<n-1) {
        ops++;
        second = x[second+1];
        swap(x, y);
    }

    ops++;

    cout << ops << '\n';





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