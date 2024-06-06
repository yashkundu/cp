/**
*   author: lazyhash(yashkundu)
*   created: 30 Mar, 2024 | 20:50:15
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
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
 
void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> v(x);
    for(int i=0;i<x;i++) cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> odds, evens;


    int extras = 0;
    for(int i=0;i<x-1;i++) {
        int del = v[i+1] - v[i] - 1;
        if(del==1) extras++;
        else if(del){
            if(del&1) odds.push_back(del);
            else evens.push_back(del);
        }
    }
    int del = n - (v[x-1] - v[0] - 1) - 2;
    if(del==1) extras++;
    else if(del) {
        if(del&1) odds.push_back(del);
        else evens.push_back(del);
    }

    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    int curTot = x;

    int ptr = 0;
    while(y>0 && ptr<odds.size()) {
        if(y<odds[ptr]/2) {
            curTot += y;
            extras += y;
            y = 0;
            break;
        }
        y -= odds[ptr]/2;
        curTot += odds[ptr]/2;
        extras += (odds[ptr]+1)/2;
        ptr++;
    }

    ptr = 0;
    while(y>0 && ptr<evens.size()) {
        if(y<evens[ptr]/2) {
            curTot += y;
            extras += y;
            y = 0;
            break;
        }
        y -= evens[ptr]/2;
        curTot += evens[ptr]/2;
        extras += evens[ptr]/2;
        ptr++;
    }

    cout << extras + (curTot-2) << "\n";


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