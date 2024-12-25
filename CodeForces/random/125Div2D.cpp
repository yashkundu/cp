/**
*    author:  lazyhash(yashkundu)
*    created: 10 Sep, 2024 | 23:14:05
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

const int MAXC = (int)1e6+10;

int n, m, tot;
int c;
ll d, h;



ll units[MAXC];
ll maxp[MAXC];

// map<int, ll> units;
// map<int, ll> maxp;
vector<pair<ll, int>> monsters;
vector<int> costs;
vector<int> ans;

const int inf = (int)1e9+10;

 
void solve() {
    cin >> n >> tot;
    monsters.clear();

    for(int i=0;i<n;i++) {
        cin >> c >> d >> h;
        units[c] = max(units[c], d*h);
    }
    
    cin >> m;
    costs.resize(m);
    ans.resize(m);
    fill(costs.begin(), costs.end(), inf);

    for(int i=0;i<m;i++) {
        cin >> d >> h;
        monsters.push_back({d*h, i});
    }

    sort(monsters.begin(), monsters.end());


    for(int cost=1;cost<=tot;cost++) {
        if(!units[cost]) continue;
        for(int i=1;i<=tot/cost;i++) {
            maxp[cost*i] = max(maxp[cost*i], units[cost]*i);
        }
    }

    for(int cost=1;cost<=tot;cost++) {
        if(!maxp[cost]) continue;
        int ind = lower_bound(monsters.begin(), monsters.end(), make_pair(maxp[cost], 0)) - monsters.begin() - 1;
        if(ind>=0) costs[ind] = min(costs[ind], cost);
    }


    for(int i=m-2;i>=0;i--) costs[i] = min(costs[i], costs[i+1]);


    for(int i=0;i<m;i++) {
        ans[monsters[i].second] = (costs[i]==inf?-1:costs[i]);
    }

    for(int i=0;i<m;i++) cout << ans[i] << " ";
    cout << "\n";








}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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