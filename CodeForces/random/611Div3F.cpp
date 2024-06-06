/**
*   author: lazyhash(yashkundu)
*   created: 05 May, 2024 | 16:30:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
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
int a[N];
bool vis[N];

vector<pair<int,int>> edges;

int n;

void solve() {
    cin >> n;
    for(int i=0;i<n-1;i++) {
        cin >> a[i];
    }
    fill(vis, vis+n+1, 0);
    set<int> st;
    for(int i=1;i<=n;i++) {
        st.insert(i);
    }
    vis[a[0]] = 1;
    st.erase(a[0]);




    for(int i=0;i<n-1;) {
        int j = i+1;
        int biggest = *st.rbegin();
        while(j<n-1 && !vis[a[j]] && a[j]!=biggest) {
            edges.push_back({a[j-1], a[j]});
            vis[a[j]] = 1;
            st.erase(a[j]);
            j++;
        }
        edges.push_back({a[j-1], biggest});
        vis[biggest] = 1;
        st.erase(biggest);
        i = j;
    }

    cout << a[0] << "\n";
    for(auto p: edges) {
        cout << p.first << " " << p.second << "\n";
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