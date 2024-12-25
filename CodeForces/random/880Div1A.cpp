/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jul, 2024 | 12:39:50
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

int A, B, C;
int num;

ll k;

int tenp[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
 
void solve() {
    cin >> A >> B >> C;
    cin >> k;
    if(C!=max(A, B) && C!=max(A, B)+1) {
        cout << "-1\n";
        return;
    }


    for(int a=tenp[A];a<tenp[A+1];a++) {
        int b1 = max(tenp[B], tenp[C]-a);
        int b2 = min(tenp[B+1]-1, tenp[C+1]-1-a);
        if(b1>b2) continue;
        num = (b2-b1+1);
        if(num<k) {
            k -= num;
        } else {
            cout << a << " + " << b1+k-1 << " = " << a+b1+k-1 << "\n";
            return;
        }
    }

    cout << "-1\n";









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