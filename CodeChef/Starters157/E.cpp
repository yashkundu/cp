/**
*    author:  lazyhash(yashkundu)
*    created: 23 Oct, 2024 | 20:26:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
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
vector<int> a;
map<int, int> mp, mp2;
 
void solve() {
    cin >> n;
    a.resize(n);
    mp.clear();
    mp2.clear();

    for(int i=0;i<n;i++) cin >> a[i];


    ll ans = 0;


    for(int i=0;i<n;) {
        if(a[i]==2) {
            i++;
            continue;
        }
        int j = i;
        while(j<n && a[j]==a[i]) j++;
        ans += 1LL*(j-i+1)*(j-i)/2;
        i = j;
    }



    mp[0]++;
    mp2[0]++;

    int c1 = 0, c3 = 0;

    for(int i=0;i<n;i++) {
        if(a[i]==1) c1++;
        else if(a[i]==3) c3++;
        else mp2.clear();
        ans += mp[c1-c3];
        ans -= mp2[c1-c3];
        mp[c1-c3]++;
        mp2[c1-c3]++;
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