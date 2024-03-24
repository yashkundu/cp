/**
*   author: lazyhash(yashkundu)
*   created: 20 Apr, 2023 | 08:29:35
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
vector<int> cnt(N, 0);
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) {
        cin >> x;
        if(x<N) cnt[x]++;
    }
    int mx = 0;
    while(cnt[mx]) mx++;
    int l = 0;
    while(l<n && a[l]!=mx+1) l++;
    int r = n-1;
    while(r>=0 && a[r]!=mx+1) r--;
    if(l<=r) {
        for(int i=l;i<=r;i++) if(a[i]<mx) {
            cnt[a[i]]--;
            if(!cnt[a[i]]) {
                for(int i=0;i<n;i++) if(a[i]<N) cnt[a[i]] = 0;
                cout << "No\n";
                return;
            }
        }
        for(int i=0;i<n;i++) if(a[i]<N) cnt[a[i]] = 0;
        cout << "Yes\n";
        return;
    } else {
        int sum = 0;
        for(int i=0;i<mx;i++) {
            if(cnt[i]>1) {
                for(int i=0;i<n;i++) if(a[i]<N) cnt[a[i]] = 0;
                cout << "Yes\n";
                return;
            }
            sum += cnt[i];
        }
        if(sum<n) {
            for(int i=0;i<n;i++) if(a[i]<N) cnt[a[i]] = 0;
            cout << "Yes\n";
            return;
        } else {
            for(int i=0;i<n;i++) if(a[i]<N) cnt[a[i]] = 0;
            cout << "No\n";
            return;
        }
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