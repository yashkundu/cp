/**
*    author:  lazyhash(yashkundu)
*    created: 13 Oct, 2024 | 22:40:33
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
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

const int MAXN = (int)2e5+10;

int n;
int m[MAXN], k[MAXN];

int sums[MAXN] = {0};
int msgs[MAXN];


bool cmp(int x, int y) {
    return sums[x]>sums[y];
}

bool operator>(const pair<int, int> &p1, const pair<int, int> &p2) {
    return 1LL*p1.first*p2.second > 1LL*p2.first*p1.second;
}

 
void solve() {
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> m[i] >> k[i];
        sums[m[i]] += k[i];
    }

    iota(msgs, msgs+MAXN, 0);

    sort(msgs+1, msgs+MAXN, cmp);

    int ans = 0;
    pair<int, int> fr = {0, 1};


    if(n>20) {
        int num = 0;
        for(int i=1;i<=20;i++) num += sums[msgs[i]];
        for(int i=21;i<=n;i++) {
            num += sums[msgs[i]];
            pair<int, int> cfr = {num, i};
            if(cfr>fr) {
                fr = cfr;
                ans = i;
            }
        }
    }


    for(int j=1;j<=min(n, 20);j++) {
        fill(sums, sums+MAXN, 0);
        for(int i=0;i<n;i++) {
            sums[m[i]] += min(j, k[i]);
        }
        sort(msgs+1, msgs+MAXN, cmp);
        int num = 0;
        for(int i=1;i<=j;i++) num += sums[msgs[i]];
        // debug(j, sums[5], sums[10]);
        // debug(j, num);
        pair<int, int> cfr = {num, j};
        if(cfr>fr) {
            fr = cfr;
            ans = j;
        }
    }


    fill(sums, sums+MAXN, 0);
    for(int i=0;i<n;i++) sums[m[i]] += min(ans, k[i]);

    sort(msgs+1, msgs+MAXN, cmp);


    cout << ans << "\n";
    for(int i=1;i<=ans;i++) cout << msgs[i] << " ";
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