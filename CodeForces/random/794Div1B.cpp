/**
*    author:  lazyhash(yashkundu)
*    created: 24 Aug, 2024 | 15:54:25
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

int a, b, c, d;
string s;
vector<pair<int, int>> evens, odds, newEvens;
int n;
 
int ca = 0, cb = 0;

void solve() {
    cin >> a >> b >> c >> d;
    cin >> s;

    evens.clear(); odds.clear();
    newEvens.clear();

    n = s.size();
    ca = cb = 0;
    for(int i=0;i<n;i++) {
        if(s[i]=='A') ca++;
        else cb++;
    }

    if(ca!=a+c+d || cb!= b+c+d) {
        cout << "NO\n";
        return;
    }


    for(int i=0;i<n;) {
        int j = i+1;
        while(j<n && s[j]!=s[j-1]) j++;
        if(j-i>1) {
            if((j-i)%2==1) odds.push_back({i, j-1});
            else evens.push_back({i, j-1});
        }
        i = j;
    }

    // debug(evens);
    // debug(odds);

    sort(evens.begin(), evens.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second-p1.first<p2.second-p2.first;
    });

    for(int i=0;i<evens.size();i++) {
        auto p = evens[i];
        int sz = p.second-p.first+1;
        int del;
        if(s[p.first]=='A') {
            del = min(sz/2, c);
            c -= del;
        } else {
            del = min(sz/2, d);
            d -= del;
        }
        p.first += 2*del;
        if(p.second-p.first>0) {
            newEvens.push_back({p.first, p.second});
        }
    }


    // debug(c, d);
    // debug(newEvens);

    for(int i=0;i<newEvens.size();i++) {
        auto p = newEvens[i];
        int sz = p.second-p.first+1;
        int del;
        if(s[p.first]=='A') {
            del = min(sz/2-1, d);
            d -= del;
        } else {
            del = min(sz/2-1, c);
            c -= del;
        }
    }

    // debug(c,d);

    int cnt = 0;
    for(auto p: odds) {
        cnt += (p.second-p.first)/2;
    }

    if(cnt>=c+d) {
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