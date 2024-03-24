/**
*   author: lazyhash(yashkundu)
*   created: 15 Aug, 2023 | 15:06:00
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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> v;

    for(int i=0;i<n;i++) {
        if(!a[i]) {
            v.push_back(0);
            continue;
        }
        int j = i;
        int x = a[i];
        while(j<n && a[j]) {
            j++;
            x = max(x, a[j]);
        }
        v.push_back(x);
        i = j-1;
    }

    // 0 0 0 1 0 2 0 0 1 0 2 0 2

    int curFlow = 0;
    bool isZeroLeft = false;
    int ans = 0;
    for(int i=0;i<v.size();i++) {
        if(v[i]) {
            curFlow = v[i];
            ans++;
            if(isZeroLeft) {
                isZeroLeft = false;
                curFlow--;
            }
            continue;
        }
        if(curFlow) {
            curFlow = 0;
            isZeroLeft = false;
            continue;
        }
        if(isZeroLeft) {
            ans++;
            continue;
        }
        isZeroLeft = true;
    }


    if(isZeroLeft) ans++;

    cout << ans << "\n";



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