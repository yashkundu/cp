/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jul, 2024 | 16:26:41
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

int n;
vector<int> a;
vector<int> p1, p2;
vector<int> dis;

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}
 
void solve() {
    cin >> n;
    a.clear();
    a.push_back(0);

    p1.resize(n+1);
    p2.resize(n+1);
    dis.resize(n+1);


    for(int i=1;i<=(n+1)/2;i++) {
        a.push_back(i);
        if(i!=n-i+1) a.push_back(n-i+1);
    }

    debug(a);

    int tmp;

    cout << "+ " << n+1 << endl;
    cin >> tmp;
    cout << "+ " << n+2 << endl;
    cin >> tmp;


    int ind = -1;
    for(int i=2;i<=n;i++) {
        dis[i] = query(1, i);
        if(ind==-1 || dis[i]>dis[ind]) ind = i;
    }

    debug(ind);

    for(int i=1;i<=n;i++) {
        if(i==ind) continue;
        dis[i] = query(ind, i);
    }

    p1[ind] = a[1];
    for(int i=1;i<=n;i++) {
        if(i==ind) continue;
        p1[i] = a[1+dis[i]];
    }

    p2[ind] = a[n];
    for(int i=1;i<=n;i++) {
        if(i==ind) continue;
        p2[i] = a[n-dis[i]];
    }

    cout << "! ";
    for(int i=1;i<=n;i++) cout << p1[i] << " ";
    for(int i=1;i<=n;i++) cout << p2[i] << " ";
    cout << endl;

    cin >> tmp;



    
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