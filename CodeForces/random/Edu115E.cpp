/**
*   author: lazyhash(yashkundu)
*   created: 21 Mar, 2024 | 20:45:31
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


const int N = 1e3+10;
bool a[N][N];
int n, m;

bool isGood(int x, int y) {
    return x>=1 && x<=n && y>=1 && y<=m && !a[x][y];
}



ll calc(int i, int j) {
    int cnt1 = 0;
    bool f = true;
    int x = i, y = j;
    while(isGood(x, y)) {
        if(f) y++;
        else x++;
        cnt1++;
        f = !f;
    }
    x = i; y = j;
    f = true;
    int cnt2 = 0;
    while(isGood(x, y)) {
        if(f) x--;
        else y--;
        cnt2++;
        f = !f;
    }

    ll sum = 1LL*cnt1*cnt2;

    // second type
    cnt1 = cnt2 = 0;
    x = i; y = j;
    f = true;
    while(isGood(x, y)) {
        if(f) x++;
        else y++;
        cnt1++;
        f = !f;
    }
    x = i; y = j;
    f = true;
    while(isGood(x, y)) {
        if(f) y--;
        else x--;
        cnt2++;
        f = !f;
    }
    sum += 1LL*cnt1*cnt2;
    return sum-1;
} 



 
void solve() {
    int q;
    cin >> n >> m >> q;
    ll curAns = 0;

    for(int i=1;i<=n;i++) {
        int x = i, y = 1;
        int cnt = 0;
        bool f = true;
        while(isGood(x, y)) {
            if(f) x++;
            else y++;
            cnt++;
            f = !f;
        }
        curAns += 1LL*cnt*(cnt-1)/2;
    }

    for(int j=1;j<=m;j++) {
        int x = 1, y = j;
        int cnt = 0;
        bool f = true;
        while(isGood(x, y)) {
            if(f) y++;
            else x++;
            cnt++;
            f = !f;
        }
        curAns += 1LL*cnt*(cnt-1)/2;
    }

    curAns += 1LL*n*m;

    while(q--) {
        int x, y;
        cin >> x >> y;
        if(!a[x][y]) {
            ll del = calc(x, y);
            curAns -= del;
            a[x][y] = 1;
        } else {
            a[x][y] = 0;
            ll del = calc(x, y);
            curAns += del;
        }
        cout << curAns << "\n";
    }


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