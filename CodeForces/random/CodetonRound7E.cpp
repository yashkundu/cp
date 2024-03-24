/**
*   author: lazyhash(yashkundu)
*   created: 19 Feb, 2024 | 17:51:45
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
// #include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set __gnu_pbds::tree<int, __gnu_pbds::null_type,less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> 

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


const int N = 1e6+10;
int a[N];
int ans[N];
 
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];


    ordered_set st;
    for(int i=1;i<=n;i++) {
        if(a[i]>=i) st.insert(a[i]);
    }

    // debug(st);

    for(int i=n+1;i<=2*n;i++) st.insert(i);



    for(int i=1;i<=n;i++) {
        if(a[i]>=i) {
            // sequential iterators not random access iterators
            int del = st.order_of_key(a[i]) - st.order_of_key(i);
            ans[a[i]] = a[i] - i - del;
            st.erase(a[i]);
        } else {
            int del = st.order_of_key(a[i]+n) - st.order_of_key(i);
            ans[a[i]] = a[i] + n - i - del;
            st.erase(a[i]+n);
        }
    }

    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";



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