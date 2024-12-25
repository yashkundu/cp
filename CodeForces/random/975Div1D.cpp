/**
*    author:  lazyhash(yashkundu)
*    created: 01 Dec, 2024 | 12:24:29
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <algorithm>
 
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
vector<pair<int, int>> v;
vector<int> par, sz;
vector<bool> codd, ceven;
int oddmx = 0;
int evensegs = 0;


int mx;


int find(int v) {
    if(par[v]==v) return v;
    return par[v] = find(par[v]);
}

bool isevenseg(int v) {
    v = find(v);
    int odd = codd[v], even = ceven[v];
    if(sz[v]%2==0 && (codd[v]||ceven[v])) return true;
    return false;
}


void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(isevenseg(a)) evensegs--;
    if(isevenseg(b)) evensegs--;
    if(codd[a]) oddmx--;
    if(codd[b]) oddmx--;
    par[b] = a;
    if(sz[a]%2==0) {
        ceven[a] = ceven[a] || ceven[b];
        codd[a] = codd[a] || codd[b];
    } else {
        ceven[a] = ceven[a] || codd[b];
        codd[a] = codd[a] || ceven[b];
    }
    sz[a] += sz[b];
    if(isevenseg(a)) evensegs++;
    if(codd[a]) oddmx++;
}

void make(int ind, int el) {
    par[ind] = ind;
    sz[ind] = 1;
    if(el==mx) {
        codd[ind] = 1;
        oddmx++;
    }
}

int getsize(int v) {
    v = find(v);
    return sz[v];
}

bool exists(int ind) {
    if(ind<0 || ind>=n) return false;
    if(getsize(ind)) return true;
    return false;
}



 
void solve() {
    cin >> n;
    v.resize(n);
    par.resize(n);
    sz.resize(n);
    codd.resize(n);
    ceven.resize(n);

    oddmx =  evensegs = 0;

    iota(par.begin(), par.end(), 0);
    fill(sz.begin(), sz.end(), 0);
    fill(codd.begin(), codd.end(),0);
    fill(ceven.begin(), ceven.end(), 0);

    mx = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i].first;
        v[i].second = i;
        mx = max(mx, v[i].first);
    }

    sort(v.rbegin(), v.rend());

    // debug(v);

    int ans = 0;
    int num = 0;



    for(auto [el, ind]: v) {
        make(ind, el);
        if(exists(ind-1) && exists(ind+1)) {
            num -= (getsize(ind-1)+1)/2 + (getsize(ind+1)+1)/2;
            merge(ind-1, ind);
            merge(ind, ind+1);
            num += (getsize(ind)+1)/2;
        } else if(exists(ind-1)) {
            num -= (getsize(ind-1)+1)/2;
            merge(ind-1, ind);
            num += (getsize(ind)+1)/2;
        } else if(exists(ind+1)) {
            num -= (getsize(ind+1)+1)/2;
            merge(ind, ind+1);
            num += (getsize(ind)+1)/2;
        } else {
            num++;
        }
        int del = 0;
        if(!evensegs && !oddmx) del = 1;
        ans = max(ans, mx+el+num-del);
        // debug(el, ind, num, evensegs, oddmx, ans);

    }


    cout << ans << "\n";





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