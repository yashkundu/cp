/**
*    author:  lazyhash(yashkundu)
*    created: 12 Jul, 2024 | 10:51:40
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

int n;
vector<int> a;

int cnt[10], ncnt[10];

 
void solve() {
    cin >> n;
    a.resize(n);

    fill(cnt, cnt+10, 0);
    

    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int typ = -1;
    int left = 0;

    for(int j=0;j<2;j++) {
        cout << "- 0" << endl;
        fill(ncnt, ncnt+10, 0);
        for(int i=0;i<n;i++) {
            cin >> a[i];
            ncnt[a[i]]++;
        }

        for(int i=1;i<=9;i++) {
            if(ncnt[i]>cnt[i]) {
                typ = i;
                break;
            }
        }
        if(typ!=-1) {
            break;
        }
    }

    for(int i=0;i<n;i++) {
        if(a[i]==typ) left++;
    }

    cout << "- " << n - left << " ";
    for(int i=0;i<n;i++) {
        if(a[i]!=typ) cout << (i+1) << " ";
    }
    cout << endl;

    for(int i=0;i<left;i++) {
        cin >> a[i];
    }
    
    for(int i=0;i<left;i++) {
        if(a[i]!=typ) {
            cout << "! " << (i+1) << endl;
            return;
        }
    }

    cout << "- 0" << endl;

    for(int i=0;i<left;i++) cin >> a[i];

    for(int i=0;i<left;i++) {
        if(a[i]!=typ) {
            cout << "! " << (i+1) << endl;
            return;
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