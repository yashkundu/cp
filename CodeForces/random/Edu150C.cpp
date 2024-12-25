/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jul, 2024 | 12:11:41
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

int n;
string s;
vector<int> a;
vector<int> mx;

ll inans = 0;
ll ans = 0;
ll curans = 0;
int mx1, mx2;

int val[] = {1, 10, 100, 1000, 10000};

int cnt[5] = {0};

int getContri(int x, int i) {
    if(mx[i+1]>x) return -val[x];
    else return val[x];
}
 
void solve() {
    cin >> s;
    n = s.size();

    a.resize(n);
    mx.resize(n+1);

    for(int i=0;i<n;i++) a[i] = s[i]-'A';
    // debug(a);

    inans = 0;
    mx[n] = 0;
    for(int i=n-1;i>=0;i--) {
        inans += (mx[i+1]>a[i]?-val[a[i]]:val[a[i]]);
        mx[i] = max(a[i], mx[i+1]);
    }

    ans = inans;
    // debug(inans);

    for(int j=0;j<5;j++) cnt[j] = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<a[i];j++) {
            curans = inans - getContri(a[i], i) + getContri(j, i);
            mx1 = max(mx[i+1], j);
            mx2 = mx[i];
            for(int k=mx2-1;k>=mx1;k--) {
                curans += 2LL*val[k]*cnt[k];
            }
            ans = max(ans, curans);
        }
        for(int j=a[i]+1;j<5;j++) {
            curans = inans - getContri(a[i], i) + getContri(j, i);
            mx1 = mx[i];
            mx2 = max(j, mx[i+1]);
            for(int k=mx1;k<mx2;k++) {
                curans -= 2LL*val[k]*cnt[k];
            }
            ans = max(ans, curans);
        }
        cnt[a[i]]++;
        for(int j=0;j<a[i];j++) cnt[j] = 0;
    }

    cout << ans << "\n";




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