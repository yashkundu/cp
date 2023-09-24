/**
*   author: lazyhash(yashkundu)
*   created: 22 Apr, 2023 | 11:18:58
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
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
    int k;
    cin >> k;
    string str;
    cin >> str;
    int n = str.size();
    
    while(k-->0) {
        int l = 0, r = -1;
        int sum = 0, pre = -1;
        for(int i=0;i<n;i++) {
            if(sum==0) pre = i;
            sum += (str[i]=='('?1:-1);
            if(sum==0) {
                if(i-pre+1>r-l+1) {
                    l = pre; r = i;
                }
            }
        }
        if(r-l+1>2) {
            assert((r-l+1)%2==0);
            string sTemp = (l>0?str.substr(0, l):"");
            sTemp += "()";
            sTemp += str.substr(l+1, r-l-1);
            sTemp += (r<n-1?str.substr(r+1, n-1-r):"");
            str = sTemp;
        }
    }

    // debug(str);
    ll ans = 0;
    int bal = 0;
    for(int i=0;i<n;i++) {
        if(str[i]=='(') ans += bal;
        bal += (str[i]=='('?1:-1);
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/