/**
*    author:  lazyhash(yashkundu)
*    created: 09 Nov, 2024 | 18:44:17
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

ll n, m;
ll k;

string s;
 
void solve() {
    cin >> n >> m >> k;

    cin >> s;

    ll num = min(n, m);

    
    ll rounds = num/k;
    ll left = num%k;

    // debug(num, rounds, left);


    ll tot = 0;



    for(int i=0;i<k;i++) {
        if(s[i]!='A') continue;
        // 2(num-i-1) + 2(num-i-1-k) + 2(num-i-1-2k)
        // 2(num-i-1)*rounds -k(1+2+3 ++ rounds-1)
        // 2(num-i-1)*rounds - k(rounds)(rounds-1)
        tot += (n+m-1)*rounds - (2*(num-i-1)*rounds - k*rounds*(rounds-1));
    }

    for(int i=0;i<left;i++) {
        if(s[i]!='A') continue;
        tot += (n+m-1) - 2*(left-i-1);
    }

    // debug(tot);

    ll other = n*m - tot;

    if(tot>other) cout << "Alice\n";
    else if(other>tot) cout << "Bob\n";
    else cout << "Draw\n";








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