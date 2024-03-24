/**
*   author: lazyhash(yashkundu)
*   created: 29 Apr, 2023 | 19:16:22
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
    int n, k;
    cin >> n >> k;
    vector<int> x(k), c(k);
    for(int i=0;i<k;i++) cin >> x[i];
    for(int i=0;i<k;i++) cin >> c[i];

    vector<char> ans;
    ans.push_back('a');
    ans.push_back('b');
    ans.push_back('c');

    vector<char> v = {'a', 'b', 'c'};


    int ind = 3, cur = 3;
    char curChar = 'd';
    int ptr = 0;
    for(int i=0;i<k;i++) {
        assert(x[i]>=ind);
        if(cur+x[i]-ind<c[i]) {
            cout << "No\n";
            return;
        }
        int num = c[i]-cur;
        debug(ind, cur, num, x[i], c[i]);
        for(int j=ind;j<x[i]-num;j++) {
            ans.push_back(v[(ptr++)%3]);
            ind++;
        }
        debug(ind, cur, num, x[i], c[i]);
        for(int j=ind;j<x[i];j++) {
            ans.push_back(curChar);
            cur++;
            ind++;
        }
        curChar++;
        debug(ans);
    }

    while(ans.size()<n) ans.push_back(v[(ptr++)%3]);

    cout << "Yes\n";
    for(char &c: ans) cout << c;
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/