/**
*   author: lazyhash(yashkundu)
*   created: 27 Apr, 2024 | 11:30:40
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


vector<int> a, b;
vector<int> na, nb;
 
int n, m;

ll inf = 1e18;


ll calc(vector<int> &a, vector<int> &b, vector<int> &na, vector<int> &nb) {
    // make a[i]>=b[i]

    ll diff = 0;

    for(int i=0;i<n;i++) {
        na[i] = a[i];
        nb[i] = b[i];
        int left = max(0, m-nb[i]);
        nb[i] = max(0, nb[i]-m);
        na[i] -= left;
        diff += (na[i]-nb[i]);
    }

    if(diff<0) return inf;

    for(int i=0;i<n;i++) {
        // make diff as closer to zero as possible
        // a[i], b[i] na[i], nb[i]
        int num = min(na[i], b[i]-nb[i]);
        ll goodNum = min(diff/2, 1LL*num);
        diff -= 2*goodNum;
        na[i] -= goodNum;
        nb[i] += goodNum;
    }

    return diff;

} 


void solve() {

    cin >> n >> m;
    a.resize(n);
    b.resize(n);
    na.resize(n);
    nb.resize(n);

    for(int i=0;i<n;i++) {
        cin >> a[i] >> b[i];
    }

    ll diff1 = calc(a, b, na, nb);
    ll diff2 = calc(b, a, nb, na);

    bool isOpposite = false;

    if(diff2<diff1) isOpposite = true;
    if(!isOpposite) calc(a, b, na, nb);


    cout << (isOpposite?diff2:diff1) << "\n";
    for(int i=0;i<n;i++) {
        cout << a[i]-na[i] << " " << b[i]-nb[i] << "\n";
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