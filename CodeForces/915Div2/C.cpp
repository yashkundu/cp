/**
*   author: lazyhash(yashkundu)
*   created: 25 Dec, 2023 | 10:43:50
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

const int N = 2e5+10;
int mx[N];
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    mx[n-1] = n-1;
    for(int i=n-2;i>=0;i--) {
        if(s[i]>=s[mx[i+1]]) mx[i] = i;
        else mx[i] = mx[i+1];
    }
    mx[n] = n;

    vector<int> lls;
    int x = mx[0];
    while(x<n) {
        lls.push_back(x);
        x = mx[x+1];
    }

    int m = lls.size();

    int ptr = 0;
    for(int i=0;i<m;i++) {
        if(s[lls[i]]==s[mx[0]]) ptr = i;
    }


    int ans = m -1 - ptr;


    vector<int> newLls;
    for(int i=m-1;i>ptr;i--) newLls.push_back(lls[i]);
    for(int i=0;i<=ptr;i++) newLls.push_back(lls[i]);

    string newS = s;

    for(int i=0;i<m;i++) {
        newS[lls[i]] = s[newLls[i]];
    }

    

    debug(newS);

    bool isGood = true;
    for(int i=0;i<n-1;i++) {
        if(newS[i]>newS[i+1]) isGood = false;
    }

    if(!isGood) ans = -1;
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