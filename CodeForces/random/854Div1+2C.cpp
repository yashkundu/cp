/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jul, 2024 | 15:28:45
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

string s;
string a, r; 

int n;

map<char, int> mp;
string ans;

void solve() {
    cin >> s;
    a.clear(); r.clear();

    mp.clear();
    
    n = s.size();
    for(int i=0;i<n;i++) mp[s[i]]++;

    while(!mp.empty()) {
        auto [ch, num] = *mp.begin();
        mp.erase(mp.begin());
        for(int i=0;i<num/2;i++) {
            a += ch;
            r += ch;
        }
        if(num&1) {
            if(mp.empty()) {
                a += ch;
            } else if(mp.size()==1) {
                auto [ch2, num2] = *mp.begin();
                mp.erase(mp.begin());
                for(int i=0;i<(num2+1)/2;i++) a += ch2;
                a += ch;
                for(int i=0;i<num2/2;i++) a += ch2;
            } else {
                r += ch;
                while(!mp.empty()) {
                    auto [ch3, num3] = *mp.begin();
                    mp.erase(mp.begin());
                    for(int i=0;i<num3;i++) a += ch3;
                }
            }
        }
    }

    reverse(r.begin(), r.end());
    ans = a + r;
    
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/