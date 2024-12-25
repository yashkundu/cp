/**
*    author:  lazyhash(yashkundu)
*    created: 05 Jul, 2024 | 18:58:59
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
 
const int MAXN = int(2e5) + 10;
const ll LIM = ll(1e16)+10;


ll a[MAXN];
ll pref[MAXN];

int n;

vector<int> nz;
int first = -1, last = -1;
ll curans = 0;
ll curmx = 0;
ll p;
int sz;

void solve() {
    cin >> n;
    pref[0] = 0;
    first = -1; 
    last = -1;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        pref[i] = a[i] + pref[i-1];
        if(a[i]!=1) {
            last = i;
            if(first==-1) first = i;
        }
    }

    if(first==-1) {
        cout << "1 1\n";
        return;
    }


    nz.clear();
    p = 1;

    for(int i=1;i<=n;i++) {
        if(a[i]==1) continue;
        if(p>LIM/a[i]) {
            cout << first << " " << last << "\n";
            return;
        }
        p *= a[i];
        nz.push_back(i);
    }



    sz = nz.size();
    first = -1;
    last = -1;
    curmx = 0;
    p = 1;
    for(int i=0;i<sz;i++) {
        p = 1;
        for(int j=i;j<sz;j++) {
            p *= a[nz[j]];
            curans = p+pref[nz[i]-1]+pref[n]-pref[nz[j]];
            if(curans > curmx) {
                curmx = curans;
                first = nz[i];
                last = nz[j];
            }
        }
    }

    cout << first << " " << last << "\n";






    
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