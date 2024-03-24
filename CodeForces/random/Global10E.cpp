/**
*   author: lazyhash(yashkundu)
*   created: 20 Feb, 2024 | 23:19:30
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
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ll val = 0;
            if(i+j!=0 && i%2==1) val = 1LL<<(i+j-1);
            cout << val << " ";
        }
        cout << "\n";
    }
    cout.flush();


    int q;
    cin >> q;
    while(q--) {
        ll sum;
        cin >> sum;
        int x = 0, y = 0;
        cout << x+1 << " " << y+1 << "\n";
        while(x!=n-1 || y!=n-1) {
            // choose the next move
            ll del = 1LL<<(x+y);
            if(((sum&del)!=0 && x%2==0) || ((sum&del)==0 && x%2!=0)) x++;
            else y++;
            if(sum&del) sum -= del;
            cout << x+1 << " " << y+1 << "\n";
        }
        cout.flush();
    }

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/