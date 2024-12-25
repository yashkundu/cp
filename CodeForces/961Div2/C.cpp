/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jul, 2024 | 20:59:39
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
vector<ll> a;

ll ops = 0;
pair<ll, int> last;

const int LIM = int(1e9)+10;

int cnt = 0;
ll f = 1;

 
void solve() {
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }


    int lastone =-1;
    for(int i=n-1;i>=0;i--) {
        if(a[i]==1) {
            lastone = i;
            break;
        }
    }

    if(lastone!=-1) {
        for(int i=0;i<lastone;i++) {
            if(a[i]!=1) {
                cout << "-1\n";
                return;
            }
        }
    }

    int firstnone = -1;
    for(int i=0;i<n;i++) {
        if(a[i]!=1) {
            firstnone = i;
            break;
        }
    }

    if(firstnone==-1) {
        cout << 0 << "\n";
        return;
    }





    ops = 0;
    last = {a[firstnone], 0};

    // debug(last, firstnone);


    for(int i=firstnone+1;i<n;i++) {
        if(a[i]==last.first) {
            ops += last.second;
        }
        else if(a[i]>last.first) {
            cnt = 0;
            f = last.first;
            while(f*f<=a[i]) {
                f *= f;
                cnt++;
            }
            last = {a[i], max(0, last.second-cnt)};
            ops += last.second;
        } else {
            cnt = 0;
            f = a[i];
            while(f<last.first) {
                f *= f;
                cnt++;
            }
            last = {a[i], last.second+cnt};
            ops += last.second;
        }
    }


    cout << ops << "\n";



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