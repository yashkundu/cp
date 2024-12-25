/**
*    author:  lazyhash(yashkundu)
*    created: 11 Jul, 2024 | 09:07:40
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric> 

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

const int MAXN = int(2e5)+10;

int n, k;
int a[MAXN];

vector<int> v;
int res = 0;
int b1, b2 = 0;


int fetch(int i, int j) {
    res = 0;
    for(int num=k-1,f=(1<<(k-1));num>=0;num--,f=(f>>1)) {
        b1 = (a[i]&f)!=0;
        b2 = (a[j]&f)!=0;
        if(b1==b2) res += f;
    }
    return res;
}


int calcX(int i, int j) {
    res = 0;
    for(int num=k-1,f=(1<<(k-1));num>=0;num--,f=(f>>1)) {
        b1 = (a[i]&f)!=0;
        b2 = (a[j]&f)!=0;
        if(b1==b2 && b1==0) {
            res += f;
        }
    }
    return res;
}


pair<int, pair<int, int>> calc(vector<int> &v, int k) {
    vector<int> ones, zeros;
    for(int ind: v) {
        if((a[ind]>>k)&1) ones.push_back(ind);
        else zeros.push_back(ind);
    }
    if(v.size()==2 || k==-1) return {fetch(v[0], v[1]), {v[0], v[1]}};

    pair<int, pair<int, int>> p = {-1, {-1, -1}};
    if(ones.size()>1) p = max(p, calc(ones, k-1));
    if(zeros.size()>1) p = max(p, calc(zeros, k-1));
    return p;
}



void solve() {
    cin >> n >> k;
    
    for(int i=0;i<n;i++) cin >> a[i];
    
    v.resize(n);
    iota(v.begin(), v.end(), 0);

    auto p = calc(v, k-1);

    int x = calcX(p.second.first, p.second.second);

    cout << p.second.first+1 << " " << p.second.second+1 << " " << x << "\n";



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