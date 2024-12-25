/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jul, 2024 | 20:35:11
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
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

int n;
vector<int> a;

ll sum = 0;

void process() {
    for(int i=0;i<n;i++) sum += a[i];
    set<int> s1, s2;

    for(int i=0;i<n;i++) {
        bool inone = s1.find(a[i])!=s1.end();
        bool intwo = s2.find(a[i])!=s2.end();
        if(!inone && !intwo) {
            s1.insert(a[i]);
        } else if(inone) {
            s1.erase(a[i]);
            s2.insert(a[i]);
        }
        if(s2.empty()) a[i] = 0;
        else a[i] = *s2.rbegin();
    }
}

 
void solve() {
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];

    sum = 0;
    process();
    process();



    for(int i=0;i<n;) {
        if(a[i]==0) {
            i++;
            continue;
        }
        int j = i;
        while(j<n && a[i]==a[j]) j++;
        sum += 1LL*a[i]*(j-i)*(n-j);
        sum += 1LL*(j-i)*(j-i+1)/2*a[i];
        i = j;
    }

    cout << sum << "\n";

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