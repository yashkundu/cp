/**
*    author:  lazyhash(yashkundu)
*    created: 17 Nov, 2024 | 20:57:18
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <bitset>
#include <deque>
 
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

const int MAXM = 10001;

using btset = bitset<MAXM>;


int n, m;
deque<pair<int, btset>> v;

int a;


 
void solve() {
    cin >> n >> m;

    
    v.clear();


    btset start;
    start.set(0);

    btset pf_or = start;
    btset last = start;

    btset lastzero = start;

    bool haszero = false;

    
    for(int i=0;i<n;i++) {
        cin >> a;
        if(a==0) {
            last = pf_or;
            haszero = true;
            lastzero = last;
            v.clear();
        } else if(a==1) {
            last = last | (last<<1);
        } else {
            btset tmp = last;
            int cur = a;
            last = (last<<a);
            for(int i=v.size()-1;i>=0;i--) {
                a *= v[i].first;
                if(a>MAXM) break;
                last |= (v[i].second<<a);
            }
            if(haszero) last |= lastzero;
            v.push_back({cur, tmp});
        }
        // debug(i, bool(last[0]));
        pf_or |= last;
        while(v.size()>13) v.pop_front();
    }

    if(last[m]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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