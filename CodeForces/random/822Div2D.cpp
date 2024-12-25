/**
*    author:  lazyhash(yashkundu)
*    created: 25 Jul, 2024 | 17:13:17
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

const int MAXN = int(2e5)+10;
const ll inf = ll(1e18)+10;

int n, k;
ll a[MAXN];
ll psum[MAXN];
pair<int, ll> nxt[MAXN], prv[MAXN];


 
void solve() {
    cin >> n >> k, k--;

    psum[0] = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        psum[i+1] = psum[i] + a[i];
    }

    for(int i=0;i<n;i++) nxt[i] = {n, 0};
    for(int i=0;i<n;i++) prv[i] = {-1, 0};

    ll mn, sum;

    for(int i=k;i<n-1;) {
        int j = i+2;
        mn = a[i+1];
        sum = a[i+1];
        while(sum<0 && j<n) {
            sum += a[j++];
            mn = min(mn, sum);
        }
        if(sum>=0) {
            nxt[i] = {j-1, mn};
            i = j-1;
        } else break;
    }

    for(int i=k;i>0;) {
        int j = i-2;
        mn = a[i-1];
        sum = a[i-1];
        while(sum<0 && j>=0) {
            sum += a[j--];
            mn = min(mn, sum);
        }
        if(sum>=0) {
            prv[i] = {j+1, mn};
            i = j+1;
        } else break;
    }


    int l = k, r = k;
    sum = a[k];


    while(true) {
        if(nxt[r].first!=n && nxt[r].second+sum>=0) {
            sum += psum[nxt[r].first+1] - psum[r+1];
            r = nxt[r].first;
        } else if(prv[l].first!=-1 && prv[l].second+sum>=0) {
            sum += psum[l] - psum[prv[l].first];
            l = prv[l].first;
        } else break;
    } 

    ll tsum = sum;
    bool good = true;

    for(int i=l-1;i>=0;i--) {
        tsum += a[i];
        if(tsum<0) good = false;
    }

    if(good) {
        cout << "YES\n";
        return;
    }

    good = true;

    tsum = sum;
    for(int i=r+1;i<n;i++) {
        tsum += a[i];
        if(tsum<0) good = false;
    }

    if(good) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";




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