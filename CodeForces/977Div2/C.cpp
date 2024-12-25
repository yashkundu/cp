/**
*    author:  lazyhash(yashkundu)
*    created: 06 Oct, 2024 | 12:12:21
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

const int MAXN = (int)2e5+10;

const int inf = (int)1e9+10;

int mp[MAXN];
int ind[MAXN];

set<int> st[MAXN];

int cnt = 0;

int n, m, q;
vector<int> a, b;

int s, cur;


bool goodind(int x) {
    if(x>1 && ind[x]<ind[x-1]) return false;
    if(x<n && ind[x]>ind[x+1]) return false;
    return true; 
}



void update(int x, int val) {
    if(ind[x]==val) return;
    for(int i=-1;i<=1;i++) {
        int nx = x+i;
        if(nx>=1 && nx<=n) {
            if(goodind(nx)) cnt--;
        }
    }
    ind[x] = val;
    for(int i=-1;i<=1;i++) {
        int nx = x+i;
        if(nx>=1 && nx<=n) {
            if(goodind(nx)) cnt++;
        }
    }
}




 
void solve() {
    cin >> n >> m >> q;

    for(int i=1;i<=n;i++) st[i].clear();

    a.resize(n);
    b.resize(m);

    for(int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]] = i+1;
    }
    for(int i=0;i<m;i++) {
        cin >> b[i];
        b[i] = mp[b[i]];
        st[b[i]].insert(i);
    }

    // debug(b);

    for(int i=1;i<=n;i++) {
        if(st[i].empty()) ind[i] = inf;
        else ind[i] = *st[i].begin();
    }

    // debug(ind[1], ind[2], ind[3], ind[4]);

    cnt = 0;
    for(int i=1;i<=n;i++) if(goodind(i)) cnt++;


    if(cnt==n) cout << "YA\n";
    else cout << "TIDAK\n";


    // debug(cnt);


    while(q--) {
        cin >> s >> cur;
        cur = mp[cur];
        s--;
        int prev = b[s];
        if(prev!=cur) {
            st[prev].erase(s);
            int val = inf;
            if(!st[prev].empty()) val = *st[prev].begin();
            update(prev, val);
            st[cur].insert(s);
            val = min(ind[cur], s);
            update(cur, val);
            b[s] = cur;
        } 
        // debug(q, cnt);
        // debug(ind[1], ind[2], ind[3], ind[4]);
        if(cnt==n) cout << "YA\n";
        else cout << "TIDAK\n";
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