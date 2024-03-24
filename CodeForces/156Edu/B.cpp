/**
*   author: lazyhash(yashkundu)
*   created: 15 Oct, 2023 | 20:58:53
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
 
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

const ld del = 1e-12;

bool isInsideTheCircle(int x, int y, int cx, int cy, ld r) {
    ll dis = 1LL*(x-cx)*(x-cx) + 1LL*(y-cy)*(y-cy);
    return dis<=r*r;
}
 
void solve() {
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    ld lo = 0, hi = 4e3;
    auto checkW = [&](ld w) {
        if(isInsideTheCircle(0, 0, ax, ay, w) && isInsideTheCircle(px, py, ax, ay, w)) return true;
        if(isInsideTheCircle(0, 0, bx, by, w) && isInsideTheCircle(px, py, bx, by, w)) return true;
        if(!isInsideTheCircle(0, 0, ax, ay, w) && !isInsideTheCircle(0, 0, bx, by, w)) return false;
        if(!isInsideTheCircle(px, py, ax, ay, w) && !isInsideTheCircle(px, py, bx, by, w)) return false;
        ll dis = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
        return dis <= 4*w*w;
    };
    while(hi-lo>del) {
        ld mid = (lo+hi)/2.0;
        if(checkW(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    ld ans = lo+(hi-lo)/2;
    cout << setprecision(15) <<  ans << "\n";
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