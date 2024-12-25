/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jun, 2024 | 11:22:49
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

const int MAXN = 18;
int a[MAXN];
bool isSet[MAXN];

vector<pair<int, int>> moves;


void convert(int l, int r) {
    int k = r-l;
    for(int len=k,i=l;len>0;len--,i++) {
        convert(i, i+len-1);
        if(len>1)
            moves.push_back({i+1, i+len-1});
    }
    moves.push_back({l, r});
}

void convertBasic(int l, int r) {
    for(int i=l;i<=r;i++) if(a[i]) {
        moves.push_back({i, i});
        a[i] = 0;
    }
    convert(l, r);
}


int n;
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    int mxSum = 0;
    int mxMask = -1;

    int curSum = 0;

    for(int mask=0;mask<(1<<n);mask++) {
        curSum = 0;
        for(int i=0,f=1;i<n;i++,f<<=1) {
            isSet[i] = (mask&f);
        }
        int j=0;
        for(int i=0;i<n;) {
            while(j<n && isSet[j]==isSet[i]) j++;
            if(j-i>1) curSum += (j-i)*(j-i);
            else curSum += max(1, a[i]);
            i = j;
        }
        if(curSum>mxSum) {
            mxSum = curSum;
            mxMask = mask;
        }
    }

    for(int i=0,f=1;i<n;i++,f<<=1) isSet[i] = (mxMask&f);


    int j = 0;
    for(int i=0;i<n;) {
        while(j<n && isSet[j]==isSet[i]) j++;
        if(j-i>1) convertBasic(i, j-1);
        else if(a[i]==0) convertBasic(i, i);
        i = j;
    }

    cout << mxSum << " " << (int)moves.size() << "\n";
    for(auto p: moves) cout << p.first+1 << " " << p.second+1 << "\n";

    

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/