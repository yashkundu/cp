/**
*    author:  lazyhash(yashkundu)
*    created: 12 Oct, 2024 | 20:24:29
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

int query(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    int x;
    cin >> x;
    if(x==-1) exit(0);
    return x;
}


int n;
vector<int> p;


int accm(int a, int b, int ind) {
    int x = 0;
    for(int j=0;j<3;j++) {
        x= x+query(a, b, ind+j);
    }
    return x;
}



void calc(int gind, int bind) {
    int x1 = accm(gind, gind+1, bind);
    int x2 = accm(gind, gind+2, bind);


    if(x1==3 & x2==3) {
        p[gind] = p[gind+1] = p[gind+2] = 1;
    } else if(x1==3) {
        p[gind] = p[gind+1] = 1;
        p[gind+2] = 0;
    } else if(x2==3) {
        p[gind] = p[gind+2] = 1;
        p[gind+1] = 0;
    }  else {
        p[gind+1] = p[gind+2] = 1;
        p[gind] = 0;
    }

    int good = -1;
    for(int i=0;i<3;i++) if(p[gind+i]==1) good = gind+i;

    if(!query(good, bind, bind+1)) {
        p[bind] = p[bind+1] = 0;
        p[bind+2] = query(good, bind, bind+2);
    } else if(!query(good, bind, bind+2)) {
        p[bind] = p[bind+2] = 0;
        p[bind+1] = 1;
    } else {
        p[bind+1] = p[bind+2] = 0;
        p[bind] = 1;
    }
}

 
void solve() {
    cin >> n;

    p.resize(n+1);
    for(int i=1;i<=n;i++) p[i] = -1;

    int good = -1, bad = -1;

    for(int i=1;i<=n;i+=3) {
        int x = query(i, i+1, i+2);
        if(x) good = i;
        else bad = i;
    }

    calc(good, bad);

    good = -1, bad = -1;

    for(int i=1;i<=n;i++) {
        if(p[i]==1) good = i;
        else if(p[i]==0) bad = i; 
    }

    for(int i=1;i<=n;i++) {
        if(p[i]==-1) p[i] = query(good, bad, i);
    }

    int cnt = 0;
    for(int i=1;i<=n;i++) if(!p[i]) cnt++;

    cout << "! " << cnt << " ";
    for(int i=1;i<=n;i++) if(!p[i]) cout << i << " ";
    cout << endl;


    
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