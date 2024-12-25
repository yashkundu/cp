/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jun, 2024 | 13:20:56
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

const int MAXN = 3e5+10;
int a[MAXN], b[MAXN];
bool dead[MAXN];
vector<int> curDead, newDead;

set<int> st;

int n;

bool checkDead(int ind) {
    int del = 0;
    auto it = st.lower_bound(ind);
    if(it!=st.begin()) {
        del += a[*prev(it)];
    }
    if(next(it)!=st.end()) {
        del += a[*next(it)];
    }
    if(del>b[ind]) return true;
    return false;
}

void solve() {
    cin >> n;
    fill(dead, dead+n, 0);
    curDead.clear();
    newDead.clear();
    st.clear();



    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    // debug(n, a[0], a[1], b[0], b[1]);
    // debug(st);
    // debug(curDead, newDead);
    // debug(dead[0], dead[1]);


    for(int i=0;i<n;i++) {
        int del = 0;
        if(i>0) del += a[i-1];
        if(i<n-1) del += a[i+1];
        if(del>b[i]) {
            curDead.push_back(i);
            dead[i] = 1;
        }
    }

    for(int i=0;i<n;i++) if(!dead[i]) st.insert(i);


    cout << curDead.size() << " ";


    for(int j=0;j<n-1;j++) {
        for(int x: curDead) {
            auto it = st.lower_bound(x);
            if(it!=st.end() && !dead[*it] && checkDead(*it)) {
                dead[*it] = 1;
                newDead.push_back(*it);
            }
            if(it!=st.begin() && !dead[*prev(it)] && checkDead(*prev(it))) {
                dead[*prev(it)] = 1;
                newDead.push_back(*prev(it));
            }
        }
        for(int x: newDead) st.erase(x);
        cout << newDead.size() << " ";
        swap(curDead, newDead);
        newDead.clear();
    }

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/