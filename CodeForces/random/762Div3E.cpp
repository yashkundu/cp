/**
*    author:  lazyhash(yashkundu)
*    created: 12 Oct, 2024 | 10:43:18
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

const int MAXN = (int)2e5+10;

int cnt[MAXN];

int n;
int a;

vector<int> v;

ll cur = 0;

 
void solve() {
    cin >> n;
    fill(cnt, cnt+n+1, 0);

    for(int i=0;i<n;i++) {
        cin >> a;
        cnt[a]++;
    }

    cur = 0;
    v.clear();

    cout << cnt[0] << " ";

    for(int i=0;i<n;i++) {
        if(cnt[i]) for(int j=0;j<cnt[i]-1;j++) v.push_back(i);
        else if(v.empty()) {
            for(int j=i;j<n;j++) cout << "-1 ";
            cout << "\n";
            return;
        } else {
            int x = v.back();
            v.pop_back();
            cur += (i-x);
        }
        cout << (cur+cnt[i+1]) << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/