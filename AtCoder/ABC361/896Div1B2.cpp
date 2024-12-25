/**
*    author:  lazyhash(yashkundu)
*    created: 06 Jul, 2024 | 20:26:00
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
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

const int MAXN = int(2e5)+10;

int cntnor[33][2], cntspec[33][2];
int a[MAXN];

int n;

ll tot = 0;
int el;
int del;
int del2;
int lsb, msb, sign;
 
void solve() {
    cin >> n;
    for(int i=0;i<32;i++) for(int j=0;j<2;j++) {
        cntnor[i][j] = 0;
        cntspec[i][j] = 0;
    }

    tot = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        tot += a[i];
    }


    if(tot%n) {
        cout << "No\n";
        return;
    }

    el = tot/n;

    for(int i=0;i<n;i++) {
        del = abs(a[i] - el);
        // debug(a[i]-el);
        if(a[i]==el) continue;
        msb = 31 - __builtin_clz(del);
        lsb = __builtin_ctz(del);
        if((1<<(msb+1))-(1<<lsb)!=del) {
            cout << "No\n";
            return;
        }
        sign = (a[i]<el)?0:1;
        if(lsb==msb) {
            cntspec[lsb][sign]++;
        } else {
            cntnor[msb+1][sign]++;
            cntnor[lsb][1^sign]++;
        }
    }


    for(int i=0;i<32;i++) {
        del = abs(cntnor[i][0]-cntnor[i][1]);
        sign = (cntnor[i][0]>=cntnor[i][1])?0:1;
        del2 = cntspec[i][0] + cntspec[i][1];
        if(del2<del || (del2%2!=del%2)) {
            cout << "No\n";
            return;
        }
        del = (cntspec[i][sign] - (del2-del)/2);
        if(del<0) sign ^= 1;
        cntnor[i+1][sign] += abs(del);
    }

    cout << "Yes\n";




    
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