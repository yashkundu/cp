/**
*    author:  lazyhash(yashkundu)
*    created: 12 Jul, 2024 | 09:24:50
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


int dis[1<<10];

int n, m;
string s, s1, s2;
int d;
int inmsk;
vector<pair<int, pair<int, int>>> meds;
const int inf = int(1e9)+10;

set<pair<int, int>> st;



int convert(string s) {
    int msk = 0;
    for(int i=n-1,f=1;i>=0;i--,f=(f<<1)) {
        if(s[i]=='1') msk += f;
    }
    return msk;
}


 
void solve() {
    cin >> n >> m;
    cin >> s;
    inmsk = convert(s);

    meds.clear();
    for(int i=0;i<m;i++) {
        cin >> d >> s1 >> s2;
        meds.push_back({d, {convert(s1), convert(s2)}});
    }


    for(int i=0;i<(1<<n);i++) dis[i] = inf;
    st.clear();

    dis[inmsk] = 0;
    st.insert({0, inmsk});

    while(!st.empty()) {
        auto [_, msk] = *st.begin();
        st.erase(st.begin());
        for(auto p: meds) {
            int nmsk = (msk^(msk&p.second.first)) | p.second.second;
            if(dis[nmsk]>dis[msk]+p.first) {
                st.erase({dis[nmsk], nmsk});
                dis[nmsk] = dis[msk] + p.first;
                st.insert({dis[nmsk], nmsk});
            }
        }
    }

    if(dis[0]==inf) dis[0] = -1;    
    cout << dis[0] << "\n";


    




    





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