/**
*   author: lazyhash(yashkundu)
*   created: 14 Jan, 2024 | 17:10:32
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

const int N = 1e5+10;
int a[N];

int gcd(int a, int b) {
    return (b==0)?a:gcd(b, a%b);
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> twosBlocks, onesBlockMiddle;
    int onesBlock = 0, onesBlockEdges = 0;

    bool allOnes = true;
    for(int i=0;i<n;i++) allOnes = allOnes && a[i]==1;

    if(allOnes) {
        int reduced = min(k-1, n-1);
        cout << (n-1) - reduced << "\n";
        return;
    }

    if(a[0]==1) {
        int ptr = 0;
        while(ptr<n && a[ptr]==1) ptr++;
        onesBlockEdges += ptr;
    }

    if(a[n-1]==1) {
        int ptr = 0;
        while(ptr<n && a[n-ptr-1]==1) ptr++;
        onesBlockEdges += ptr;
    }


    for(int i=0;i<n;) {
        if(a[i]==1) {
            int j = i;
            while(j<n && a[j]==1) j++;
            if(i!=0 && j!=n) onesBlockMiddle.push_back(j-i);
            i = j;
            continue;
        }
        int j = i+1;
        while(j<n && gcd(a[j], a[j-1])==1 && a[j]!=1) j++;
        if(j-i>2) twosBlocks.push_back(j-i);
        else if(j-i==2) onesBlock++;
        i = j;
    }

    int tot = 0;
    for(int i=1;i<n;i++) if(gcd(a[i], a[i-1])==1) tot++;


    int reduced = 0;

    while(twosBlocks.size()) {
        int x = twosBlocks.back();
        twosBlocks.pop_back();
        if(x%2==0) onesBlock++;
        reduced += min(k, (x-1)/2)*2;
        k -= min(k, (x-1)/2);
    }

    sort(onesBlockMiddle.rbegin(), onesBlockMiddle.rend());

    while(onesBlockMiddle.size()) {
        int x = onesBlockMiddle.back();
        onesBlockMiddle.pop_back();
        if(x<=k) reduced += x+1;
        else reduced += k;
        k -= min(k, x);
    }

    int ones = onesBlock + onesBlockEdges;
    reduced += min(k, ones);

    cout << tot - reduced << "\n";



    
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