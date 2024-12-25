/**
*    author:  lazyhash(yashkundu)
*    created: 19 Aug, 2024 | 17:29:31
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

const int MAXN = 1000+3;

bool a[MAXN][MAXN];
int pra[2*MAXN], prb[2*MAXN], sfa[2*MAXN], sfb[2*MAXN]; 

string s;


int n, m;
int tot;


bool checkPoint(int i, int j, int del) {
    int x = i+j-del;
    if(x>0 && pra[x-1]) return false;
    x = i+j+del;
    if(x<tot && sfa[x+1]) return false;
    x = i-j+m-1-del;
    if(x>0 && prb[x-1]) return false;
    x = i-j+m-1+del;
    if(x<tot && sfb[x+1]) return false;
    return true; 
}

bool check(int del) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(checkPoint(i, j, del)) return true;
        }
    }
    return false;
}



void solve() {
    for(int i=0;i<2*MAXN;i++) pra[i] = prb[i] = sfa[i] = sfb[i] = 0;

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<m;j++) {
            a[i][j] = s[j]=='B';
            if(a[i][j]) {
                pra[i+j]++;
                sfa[i+j]++;
                prb[i-j+m-1]++;
                sfb[i-j+m-1]++;
            }
        }
    }
    

    tot = n+m-2;
    for(int i=1;i<=tot;i++) {
        pra[i] += pra[i-1];
        prb[i] += prb[i-1];
    }

    for(int i=tot-1;i>=0;i--) {
        sfa[i] += sfa[i+1];
        sfb[i] += sfb[i+1];
    }

    // debug(pra[0], pra[1], pra[2], pra[3]);
    // debug(sfa[0], sfa[1], sfa[2], sfa[3]);
    // debug(prb[0], prb[1], prb[2], prb[3]);
    // debug(sfb[0], sfb[1], sfb[2], sfb[3]);


    int L = -1, R = 2*MAXN;
    while(R-L>1) {
        int mid = (L+R)/2;
        if(check(mid)) R = mid;
        else L = mid;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(checkPoint(i, j, R)) {
                cout << i+1 << " " << j+1 << "\n";
                return;
            }
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