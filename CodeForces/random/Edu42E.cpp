/**
*   author: lazyhash(yashkundu)
*   created: 19 May, 2024 | 19:17:56
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
ll x[N];
char c[N];

const int inf = 2e9+100;


ll calcRange(int l, int r, bool bothPresent) {
    if(l+1==r) return x[r] - x[l];
    vector<int> bytes, bers;
    for(int i=l+1;i<r;i++) {
        if(c[i]=='B') bytes.push_back(i);
        else bers.push_back(i);
    }
    if(bytes.empty() || bers.empty()) {
        if(!bothPresent) return x[r] - x[l];
        if(bytes.empty()) swap(bytes, bers);
        ll mxLen = max(x[bytes[0]]-x[l], x[r] - x[bytes.back()]);
        for(int i=0; i+1<bytes.size();i++) mxLen = max(mxLen, x[bytes[i+1]] - x[bytes[i]]);
        return 2*(x[r]-x[l]) - mxLen;
    }
    ll tot = (x[r]-x[l]);
    ll mxLen1 = max(x[bytes[0]]-x[l], x[r]-x[bytes.back()]);
    for(int i=0;i+1<bytes.size();i++) mxLen1 = max(mxLen1, x[bytes[i+1]]-x[bytes[i]]);
    ll mxLen2 = max(x[bers[0]]-x[l], x[r] - x[bers.back()]);
    for(int i=0;i+1<bers.size();i++) mxLen2 = max(mxLen2, x[bers[i+1]]-x[bers[i]]);
    return min(2*tot, 3*tot - mxLen1 - mxLen2);
}

 
int n;

void solve() {
    cin >> n;
    set<char> st;
    for(int i=0;i<n;i++) {
        cin >> x[i];
        cin >> c[i];
        st.insert(c[i]);
    }

    ll ans = 0;
    vector<int> dis;
    for(int i=0;i<n;i++) if(c[i]=='P') dis.push_back(i);

    for(int i=0;i+1<dis.size();i++) {
        ans += calcRange(dis[i], dis[i+1], st.size()==3);
    }

    if(dis.size()==0) {
        vector<int> bytes, bers;
        for(int i=0;i<n;i++) 
            if(c[i]=='B') bytes.push_back(i);
            else bers.push_back(i);

        for(int i=0;i+1<bytes.size();i++) ans += x[bytes[i+1]] - x[bytes[i]];
        for(int i=0;i+1<bers.size();i++) ans += x[bers[i+1]] - x[bers[i]];
    } else {
        vector<int> bytes, bers;
        for(int i=0;i<dis[0];i++) if(c[i]=='B') bytes.push_back(i);
        else bers.push_back(i);
        for(int i=0;i+1<bytes.size();i++) ans += x[bytes[i+1]] - x[bytes[i]];
        for(int i=0;i+1<bers.size();i++) ans += x[bers[i+1]] - x[bers[i]];
        if(bytes.size()) ans += x[dis[0]] - x[bytes.back()];
        if(bers.size()) ans += x[dis[0]] - x[bers.back()];

        bytes.clear();
        bers.clear();
        for(int i=dis.back()+1;i<n;i++) if(c[i]=='B') bytes.push_back(i);
        else bers.push_back(i);
        for(int i=0;i+1<bytes.size();i++) ans += x[bytes[i+1]] - x[bytes[i]];
        for(int i=0;i+1<bers.size();i++) ans += x[bers[i+1]] - x[bers[i]];
        if(bytes.size()) ans += x[bytes[0]] - x[dis.back()];
        if(bers.size()) ans += x[bers[0]] - x[dis.back()];
    }

    cout << ans << "\n";


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