/**
*    author:  lazyhash(yashkundu)
*    created: 04 Sep, 2024 | 21:29:14
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

int n, k;
string a, b;

vector<pair<int, char>> ops;
 
void solve() {
    cin >> n >> k;
    cin >> a >> b;
    
    if(a==b) {
        cout << "0\n";
        return;
    }

    int ind = -1;
    int cnt = 0;


    for(int i=0;i<n;) {
        int j = i;
        while(j<n && b[j]==b[i]) j++;
        if(j-i>cnt) {
            cnt = j-i;
            ind = i;
        }
        i = j;
    }

    // debug(cnt, ind);

    if(cnt<k) {
        cout << "-1\n";
        return;
    }

    ops.clear();


    for(int i=0;i<ind;i++) {
        ops.push_back({i+1, b[i]});
    }

    for(int i=n-1;i>ind+cnt-1;i--) {
        // debug(i);
        ops.push_back({i-k+2, b[i]});
    }

    for(int i=ind;i+k-1<=ind+cnt-1;i++) {
        ops.push_back({i+1, b[i]});
    }

    cout << (int)ops.size() << "\n";
    for(auto p: ops) {
        cout << p.first << " " << p.second << "\n";
    }




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