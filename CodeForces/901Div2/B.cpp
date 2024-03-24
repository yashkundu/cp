/**
*   author: lazyhash(yashkundu)
*   created: 30 Sep, 2023 | 20:48:19
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

int findMin(vector<int> &v) {
    int n = v.size();
    int minInd = -1;
    int minEl = 1e9+100;
    for(int i=0;i<n;i++) {
        if(v[i]<minEl) {
            minEl = v[i];
            minInd = i;
        }
    }
    return minInd;
}

int findMax(vector<int> &v) {
    int n = v.size();
    int maxInd = -1;
    int maxEl = 0;
    for(int i=0;i<n;i++) {
        if(v[i]>maxEl) {
            maxEl = v[i];
            maxInd = i;
        }
    }
    return maxInd;
}
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> ans(4, 0);
    vector<int> a(n), b(m);
    ll sumA = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sumA += a[i];
    }
    for(int &x: b) cin >> x;

    for(int round=1;round<=4;round++) {
        if(round&1) {
            int minIndA = findMin(a);
            int maxIndB = findMax(b);
            if(a[minIndA]>=b[maxIndB]) {
                ans[round-1] = sumA;
                continue;
            }
            sumA += (b[maxIndB]-a[minIndA]);
            int tmp = b[maxIndB];
            b[maxIndB] = a[minIndA];
            a[minIndA] = tmp;
            ans[round-1] = sumA;
        } else {
            int minIndB = findMin(b);
            int maxIndA = findMax(a);
            if(b[minIndB]>=a[maxIndA]) {
                ans[round-1] = sumA;
                continue;
            }
            sumA += (b[minIndB]-a[maxIndA]);
            int tmp = a[maxIndA];
            a[maxIndA] = b[minIndB];
            b[minIndB] = tmp;
            ans[round-1] = sumA;
        }
    }

    if(k<=4) {
        cout << ans[k-1] << "\n";
        return;
    }

    if(k&1) {
        cout << ans[2] << "\n";
    } else {
        cout << ans[3] << "\n";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/