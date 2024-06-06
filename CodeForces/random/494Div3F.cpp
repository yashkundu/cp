/**
*   author: lazyhash(yashkundu)
*   created: 17 May, 2024 | 12:32:32
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
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


const int N = 301;
int w[N], a[N];

int n;
int cntr = 0;
map<string, int> mp;


vector<int> prefixFunction(int *a, int n) {
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1;i<n;i++) {
        int j = pi[i-1];
        while(j>0 && a[j]!=a[i]) j = pi[j-1];
        if(a[j]==a[i]) j++;
        pi[i] = j;
    }
    return pi;
}

 
void solve() {
    cin >> n;

    int tot = 0;

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        if(mp.find(s)==mp.end()) mp[s] = cntr++;
        a[i] = mp[s];
        w[i] = s.size();
        tot += s.size();
    }

    tot += (n-1);

    int maxDiff = 0;

    // to be yes or not to be yes
    for(int i=0;i<n;i++) {
        int wSum = 0;
        for(int j=i;j<n;j++) {
            
            // [i, j]
            wSum += w[j];
            vector<int> pi = prefixFunction(a+i, j-i+1);
            int cnt = 1;
            int ptr = 0;
            for(int k=j+1;k<n;k++) {
                if(a[i+ptr]!=a[k] && ptr>0) ptr = pi[ptr-1];
                if(a[i+ptr]==a[k]) ptr++;
                if(ptr==j-i+1) {
                    cnt++;
                    ptr = 0;
                }
            }
            if(cnt>1) maxDiff = max(maxDiff, (wSum -1)*cnt);
        }
    }

    tot -= maxDiff;
    cout << tot << "\n";




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