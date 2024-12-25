/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jul, 2024 | 20:13:41
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
 
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

int n;
int a[MAXN];

vector<int> v;

vector<int> divs[MAXN];

map<int, int> mp;




void init() {
    for(int i=1;i<MAXN;i++) {
        for(int j=i;j<MAXN;j+=i) divs[j].push_back(i);
    }
}

 
void solve() {
    cin >> n;
    mp.clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    v.clear();
    for(auto [x, c]: mp) v.push_back(c);

    sort(v.rbegin(), v.rend());

    debug(v);

    for(int i=1;i<v.size();i++) v[i] += v[i-1];

    debug(v);


    for(int l=n;l>0;l--) {
        for(int d: divs[l]) {
            if(d<=v.size() && v[d-1]>=l) {
                cout << l << "\n";
                return;
            }
        }
    }

    

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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