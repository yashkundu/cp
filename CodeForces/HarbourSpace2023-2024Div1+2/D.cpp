/**
*   author: lazyhash(yashkundu)
*   created: 22 Sep, 2023 | 00:01:45
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
 
void solve() {
    int n;
    cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n, 0));

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<n;j++) a[i][j] = (s[j]=='1');
    }

    vector<int> diagL(2*n-1, 0), tDiagL(2*n-1, 0),  diagR(2*n-1, 0), tDiagR(2*n-1, 0);
    vector<int> left(n, 0), tLeft(n, 0), right(n, 0), tRight(n, 0);

    int cnt = 0;


    for(int i=0;i<n;i++) {
        fill(tDiagL.begin(), tDiagL.end(), 0);
        fill(tDiagR.begin(), tDiagR.end(), 0);
        fill(tLeft.begin(), tLeft.end(), 0);
        fill(tRight.begin(), tRight.end(), 0);
        for(int j=0;j<n;j++) {
            int numTransitions = diagR[i+j] - left[j] + diagL[n-1+i-j] - right[j];
            int curVal = a[i][j];
            curVal ^= (numTransitions&1);
            if(curVal) {
                cnt++;
                tDiagR[i+j]++;
                tDiagL[n-1+i-j]++;
                tLeft[j]++;
                tRight[0]++;
                tRight[j]--;
            }
        }
        for(int i=1;i<2*n-1;i++) {
            tDiagL[i] += tDiagL[i-1];
            tDiagR[i] += tDiagR[i-1];
        }
        for(int i=1;i<n;i++) {
            tLeft[i] += tLeft[i-1];
            tRight[i] += tRight[i-1];
        }
        for(int i=0;i<2*n-1;i++) {
            diagL[i] += tDiagL[i];
            diagR[i] += tDiagR[i];
        }
        for(int i=0;i<n;i++) {
            left[i] += tLeft[i];
            right[i] += tRight[i];
        }
    }

    cout << cnt << "\n";


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