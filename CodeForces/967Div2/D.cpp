/**
*    author:  lazyhash(yashkundu)
*    created: 20 Aug, 2024 | 21:20:05
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <map>
 
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



set<pair<int, int>> mnst, mxst;
set<int> lstst;
map<int, int> lstmp;
map<int, bool> taken;

vector<int> ans;
int sz;
 
void solve() {
    cin >> n;
    a.resize(n+1);
    mnst.clear(); mxst.clear(); lstst.clear(); lstmp.clear(); taken.clear();

    ans.clear();


    for(int i=1;i<=n;i++) cin >> a[i];


    for(int i=n;i>0;i--) {
        if(!lstmp[a[i]]) {
            lstst.insert(i);
            lstmp[a[i]] = i;
        }
    }


    int l = *(lstst.begin());
    sz = lstst.size();

    // debug(lstst);
    // debug(sz);


    for(int i=1;i<=l;i++) {
        mxst.insert({a[i], -i});
        mnst.insert({a[i], i});
    }

    // debug(l);
    // debug(mxst);
    // debug(mnst);

    int ind = 0;

    for(int num=0;num<sz;num++) {
        // debug(num);
        int nwInd;
        int el;
        if(num&1) {
            while(true) {
                auto p = *(mnst.begin());
                mnst.erase(p);
                if(!taken[p.first]) {
                    el = p.first;
                    taken[p.first] = 1;
                    nwInd = p.second;
                    lstst.erase(lstmp[p.first]);
                    break;
                }
            }

        } else {
            while(true) {
                auto p = *(mxst.rbegin());
                mxst.erase(p);
                if(!taken[p.first]) {
                    el = p.first;
                    taken[p.first] = 1;
                    nwInd = abs(p.second);
                    lstst.erase(lstmp[p.first]);
                    break;
                }
            }
        }
        // debug(el);
        ans.push_back(el);
        int mnLst = *lstst.begin();
        // debug(mnLst, nwInd);
        for(int k=l+1;k<=mnLst;k++) {
            mxst.insert({a[k], -k});
            mnst.insert({a[k], k});
        }
        l = mnLst;

        for(int k=ind+1;k<=nwInd;k++) {
            // debug(k);
            mxst.erase({a[k], -k});
            mnst.erase({a[k], k});
        }

        ind = nwInd;
        // debug(mxst, mnst);

    }

    cout << ans.size() << "\n";
    for(int x: ans) cout << x << " ";
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