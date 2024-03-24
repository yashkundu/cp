/**
*   author: lazyhash(yashkundu)
*   created: 03 Feb, 2024 | 23:27:47
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
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

const int N = 2e5+10;
int a[N];
map<int, int> mp, mp2;


void reduceOrRemoveFromMap(map<int, int> &m, int x) {
    m[x]--;
    if(!m[x]) m.erase(x);
}

 
void solve() {
    int n;
    cin >> n;


    mp.clear();
    mp2.clear();
    for(int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]]++;
    }


    auto it1 = mp.begin();
    auto it2 = mp.begin();
    it2++;


    for(;it2!=mp.end();it1++, it2++) {
        mp2[it2->first-it1->first]++;
    }


    int q;
    cin >> q;
    while(q--) {
        int i, x;
        cin >> i >> x;
        i--;
        if(a[i]!=x) {
            // remove a[i] first
            mp[a[i]]--;
            if(!mp[a[i]]) {
                // the item is deleted

                // adjust the values of dels in mp2
                auto itR = mp.upper_bound(a[i]);
                if(itR!=mp.end()) {
                    // reduce that delta from m2
                    reduceOrRemoveFromMap(mp2, itR->first-a[i]);
                }
                auto itL = mp.find(a[i]);
                if(itL!=mp.begin()) {
                    itL--;
                } else {
                    itL = mp.end();
                }

                if(itL!=mp.end()) {
                    // reduce delta
                    reduceOrRemoveFromMap(mp2, a[i]-itL->first);
                }

                if(itL!=mp.end() && itR!=mp.end()) {
                    mp2[itR->first-itL->first]++;
                }


                mp.erase(a[i]);
            }

            a[i] = x;

            mp[x]++;
            if(mp[x]==1) {
                // a new element is added

                auto itR = mp.upper_bound(x);
                auto itL = mp.find(x);
                if(itL!=mp.begin()) {
                    itL--;
                } else {
                    itL = mp.end();
                }

                if(itR!=mp.end() && itL!=mp.end()) {
                    // reduce from mp2
                    reduceOrRemoveFromMap(mp2, itR->first-itL->first);
                }

                if(itR!=mp.end()) {
                    mp2[itR->first-x]++;
                }
                if(itL!=mp.end()) {
                    mp2[x - itL->first]++;
                }
            }

        }
        int maxDel = (mp2.empty()?0:(mp2.rbegin()->first));
        int ans = mp.rbegin()->first + maxDel;
        std::cout << ans << " ";
    }

    std::cout << "\n";

    /*
        3
        2 4 8
        6 4 8
        6 10 8
        6 10 1
    */




    
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/