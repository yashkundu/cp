/**
*    author:  lazyhash(yashkundu)
*    created: 03 Jul, 2024 | 20:35:39
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

const int MAXN = int(2e5) + 10;

int p[MAXN];

int n;
vector<int> del;
set<int> st;

int check(int num, int x, int y) {
    int res = 0;
    st.insert(x);
    if(*st.rbegin()==num+1) res++;
    st.insert(y);
    if(*st.rbegin()==num+2) res++;
    st.erase(x);
    st.erase(y);
    return res;
}


int calcDel(int num, int x, int y) {
    return check(num, y, x) - check(num, x, y);
}


int maxSum(vector<int> &v) {
    int sz = v.size();
    int max_end = 0;
    int ans = 0;

    for(int i=0;i<sz;i++) {
        max_end = max(max_end + v[i], v[i]);
        ans = max(ans, max_end);
    }
    return ans;
}


 
void solve() {
    cin >> n;
    p[0] = 0;
    for(int i=1;i<=n;i++) cin >> p[i];


    int mxDel = 0;

    del.clear();
    st.clear();
    st.insert(0);
    for(int i=0;i+2<=n;i+=2) {
        del.push_back(calcDel(i, p[i+1], p[i+2]));
        st.insert(p[i+1]);
        st.insert(p[i+2]);
    }
    
    mxDel = max(mxDel, maxSum(del));

    del.clear();
    st.clear();
    st.insert(0);
    st.insert(p[1]);

    for(int i=1;i+2<=n;i+=2) {
        del.push_back(calcDel(i, p[i+1], p[i+2]));
        st.insert(p[i+1]);
        st.insert(p[i+2]);
    }

    mxDel = max(mxDel, maxSum(del));


    st.clear();
    st.insert(0);

    for(int i=1;i<=n;i++) {
        st.insert(p[i]);
        if(*st.rbegin()==i) mxDel++;
    }

    cout << mxDel << "\n";






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