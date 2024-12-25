/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jun, 2024 | 16:55:47
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

int n;
string s;
set<int> st; 

void inv(string &s, int ind) {
    if(s[ind]=='0') s[ind] = '1';
    else s[ind] = '0';
}


bool checkInv(string s, int k) {
    st.clear();

    int cnt = 0;
    for(int i=0;i<n;i++) {
        cnt = st.size();
        if(cnt&1) inv(s, i);
        if(i+k<n && s[i]=='0') {
            inv(s, i);
            st.insert(i+k-1);
        }
        st.erase(i);
    }

    for(int i=n-k;i<n;i++) {
        if(s[i]!=s[n-k]) return false;
    }
    return true;
}

void solve() {
    cin >> n;
    cin >> s;

    for(int k=n;k>0;k--) {
        if(checkInv(s, k)) {
            cout << k << "\n";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/