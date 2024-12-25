/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jun, 2024 | 15:03:50
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

const int N = 2e5+10;
int p[N];

int n;
ll k;
 
void solve() {
    cin >> n;
    cin >> k;

    ll tot = 0;
    int num = (n+1)/2;
    if(n%2==0) {
        tot = 1LL*num*num*2;
    } else {
        tot = 1LL*num*(num-1)*2;
    }

    if(k%2==1 || k>tot) {
        cout << "No\n";
        return;
    }

    for(int i=1;i<=n;i++) p[i] = i;
    
    int ptr = 1;
    int len = 0;

    while(k!=0) {
        len = n - 2*(ptr-1);
        if(k<=2*(len-1)) {
            swap(p[ptr], p[ptr+k/2]);
            break;
        }
        swap(p[ptr], p[n-ptr+1]);
        k -= 2*(len-1);
        ptr++;
    }

    cout << "Yes\n";
    for(int i=1;i<=n;i++) cout << p[i] << " ";
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