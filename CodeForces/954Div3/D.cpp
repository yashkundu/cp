/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jun, 2024 | 21:00:42
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


int minValue(vector<int> &v) {
    int sum = 0;
    bool zero = false;
    for(int i=0;i<n-1;i++) {
        if(v[i]!=1) sum += v[i];
        if(!v[i]) zero = true;
    }
    if(zero) return 0;
    return max(1, sum);
}

 
void solve() {
    cin >> n;
    cin >> s;

    vector<int> v;
    v.resize(n-1);

    int mn = 1e9;

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<i;j++) {
            v[j] = s[j]-'0';
        }
        v[i] = 10*(s[i]-'0') + (s[i+1]-'0');
        for(int j=i+2;j<n;j++) {
            v[j-1] = s[j]-'0';
        }
        mn = min(mn, minValue(v));
    }

    cout << mn << "\n";

    
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