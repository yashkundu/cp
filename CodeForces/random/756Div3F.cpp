/**
*    author:  lazyhash(yashkundu)
*    created: 15 Oct, 2024 | 21:53:20
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
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

const ll inf = (ll)1e18+10;
const int LG = 18;

int n;
ll s;
vector<ll> a;
 


struct Ftree{
    int n;
    vector<ll> v;
    Ftree(int n) {
        this->n = n;
        v.resize(n+1);
        fill(v.begin(), v.end(), inf);
    }

    void update(int ind, ll val) {
        for(;ind<=n;ind+=ind&-ind) v[ind] = min(v[ind], val);
    }

    ll query(int ind) {
        ll ans = inf;
        for(;ind>0;ind-=ind&-ind) ans = min(ans, v[ind]);
        return ans;
    }

    int find(ll x) {
        int ind = 0;
        for(int j=LG;j>=0;j--) {
            if(ind+(1<<j)<=n && v[ind+(1<<j)]>=x) ind += (1<<j);
        }
        return ind+1;
    }

};





void solve() {
    cin >> n >> s;
    a.resize(n+1);

    a[0] = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    Ftree ft(n);
    int ans = 0;
    pair<int, int> p = {-1, -1};


    for(int i=n;i>0;i--) {
        ft.update(i, a[i]);
        int j = ft.find(a[i-1]-s);
        if(j-i>ans) {
            ans = j-i;
            p = {i, j-1};
        }
    }

    if(!ans) {
        cout << "-1\n";
        return;
    }


    cout << p.first << " " << p.second << "\n";




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