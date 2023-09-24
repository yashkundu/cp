/**
*   author: lazyhash(yashkundu)
*   created: 23 Aug, 2023 | 10:27:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
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


 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int pCnt = 0, nCnt = 0;
    int maxPos = 0, minNeg = 0;
    int maxPInd = -1, minNInd = -1;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]>0) {
            pCnt++;
            if(a[i]>maxPos) {
                maxPos = a[i];
                maxPInd = i;
            }
        } else if (a[i]<0) {
            nCnt++;
            if(a[i]<minNeg) {
                minNeg = a[i];
                minNInd = i;
            }
        }
    }

    vector<pair<int, int>> ans;


    if(maxPInd!=-1 && minNInd!=-1) {
        if(abs(pCnt-nCnt)>=5) {
            int flag = pCnt>nCnt;
            int fInd = flag?maxPInd:minNInd;
            for(int i=0;i<5;i++) {
                ans.emplace_back(fInd, fInd);
                a[fInd] += a[fInd];
            }
            for(int i=0;i<n;i++) {
                if((flag?a[i]<0:a[i]>0)) {
                    ans.emplace_back(i, fInd);
                    a[i] += a[fInd];
                }
            }
        } else {
            int flag = maxPos+minNeg>=0;
            int fInd = (flag)?maxPInd:minNInd;
            for(int i=0;i<n;i++) {
                if((flag?a[i]<0:a[i]>0)) {
                    ans.emplace_back(i, fInd);
                    a[i] += a[fInd];
                }
            }
        }
    }

    bool isSomePos = any_of(a.begin(), a.end(), [](int x) {return x>0;});
    bool isSomeNeg = any_of(a.begin(), a.end(), [](int x) {return x<0;});
    assert(!(isSomePos&isSomeNeg));


    if(isSomePos) {
        for(int i=1;i<n;i++) {
            ans.emplace_back(i, i-1);
        }
    }
    if(isSomeNeg) {
        for(int i=n-2;i>=0;i--) {
            ans.emplace_back(i, i+1);
        }
    }

    cout << ans.size() << "\n";
    for (auto tp: ans) cout << tp.first+1 << " " << tp.second+1 << "\n";

    // all will have same parity now, do n-1 more operations




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