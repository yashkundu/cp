/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jun, 2024 | 17:56:28
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

const int MAXN = 1e5+10;
const ll inf = 2e18+10;


int b, x;
int n, q;
ll k;
ll tot = 0;
int sz;

vector<pair<int, vector<int>>> ops;




 
void solve() {
    cin >> n >> q;
    ops.clear();

    for(int i=0;i<n;i++) {
        cin >> b >> x;
        if(b==1) {
            if(ops.empty() || ops.back().first!=1) ops.push_back({1, {x}});
            else ops.back().second.push_back(x);
        } else {
            ops.push_back({2, {x}});
        }
    }

    sz = ops.size();    

    while(q--) {
        cin >> k;
        tot = 0;
        int ind = 0;
        while(ind<sz) {
            if(ops[ind].first==1) {
                tot += ops[ind].second.size();
            } else {
                if(tot > inf/(ops[ind].second[0]+1)) {
                    k = (k-1)%tot+1;
                    ind--;
                    break;
                }
                tot *= ops[ind].second[0]+1;
            }
            if(tot>=k) break;
            ind++;
        }
        // debug(ind);
        int ans = -1;

        while(true) {
            if(ops[ind].first==1) {
                if(tot-k+1<=ops[ind].second.size()) {
                    ans = ops[ind].second[ops[ind].second.size()-1-(tot-k)];
                    break;
                } else {
                    tot -= (int)ops[ind].second.size();
                }
            } else {
                // debug(tot/(ops[ind].second[0]+1), q, tot, ops[ind].second[0]+1, ind);
                k = (k-1)%(tot/(ops[ind].second[0]+1)) + 1;
                tot /= (ops[ind].second[0]+1);
            }
            ind--;
        }
        
        cout << ans << " ";
    }

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