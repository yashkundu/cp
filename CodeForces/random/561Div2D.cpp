/**
*   author: lazyhash(yashkundu)
*   created: 09 May, 2024 | 20:24:51
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

vector<ll> seq;
 
void solve() {
    ll a, b, m;
    cin >> a >> b >> m;

    seq.clear();

    if(a==b) {
        cout << "1 " << a << "\n";
        return;
    }

    seq.push_back(0);
    seq.push_back(a);

    while(true) {
        ll el = 2*seq.back()+1;
        if(el>=b) break;
        seq.push_back(el);
    }

    // debug(seq);

    ll lastEl = max(b-m, seq.back());
    ll del = lastEl - seq.back();

    // debug(lastEl, del);

    ll f = 1LL<<(seq.size()-3);

    for(int i=2;i<seq.size();i++) {
        ll num = min(m-1, del/f);
        del -= num*f;
        seq[i] = 2*seq[i-1] + 1 + num;
        // debug(num, f, del);
        f = f>>1;
    }

    if(del) {
        cout << "-1\n";
        return;
    }

    seq.push_back(seq.back()+b);

    cout << seq.size() -1 << " ";

    for(int i=1;i<seq.size();i++) {
        cout << (seq[i]-seq[i-1]) << " ";
    }

    cout << "\n";




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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/