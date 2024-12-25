/**
*    author:  lazyhash(yashkundu)
*    created: 28 Oct, 2024 | 20:21:11
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
vector<ll> a;
vector<ll> val;

const ll inf = (ll)1e18+10;


ll calc(int ind) {
    ll ans = 1;
    vector<ll> v;
    for(int i=0;i<n;i++) if(i!=ind) v.push_back(a[i]);



    for(int i=0;i<v.size();i+=2) ans = max(ans, v[i+1]-v[i]);
    return ans;
}


 
void solve() {
    cin >> n;
    a.resize(n);
    val.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];


    if(n%2==0) {
        ll ans = 1;
        for(int i=0;i<n;i+=2) ans = max(ans, a[i+1]-a[i]);
        cout << ans << "\n";
        return;
    }


    for(int i=0;i<n;i++) {
        ll x = a[i]+1;
        int j = i+1;
        while(j<n && a[j]==x) {
            j++;
            x++;
        }
        val[i] = x - a[i];
        x = a[i]-1;
        j = i-1;
        while(j>=0 && a[j]==x) {
            j--;
            x--;
        }
        val[i] = min(val[i], a[i]-x);
    }


    ll ans = inf;

    for(int i=0;i<n;i++) {
        ans = min(ans, max(val[i], calc(i)));
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