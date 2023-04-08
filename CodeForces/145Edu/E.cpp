/**
*   author: lazyhash(yashkundu)
*   created: 25 Mar, 2023 | 16:51:18
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


const int N = 1e4+2;
const int A = 1e3+2;
const int inf = 1e9;

vector<int> v(N, 0);
vector<vector<int>> ind1(N, vector<int>(A, inf)), ind2(N, vector<int>(A, inf));
vector<int> pre1(N, 0), pre2(N, 0);
vector<vector<int>> ans(A, vector<int>(A, 0));
vector<pair<int, int>> r1(N, {-1,  -1}), r2(N, {-1, -1});




int n, a, b;
 
void solve() {
    
    cin >> n >> a >> b;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        pre1[i+1] = pre1[i] - v[i];
        pre2[i+1] = pre2[i] + v[i];
    }

    for(int i=0;i<=n;i++) {
        int ptr1 = 0, ptr2 = 0;
        ind1[i][ptr1] = i;
        ind2[i][ptr2] = i;
        int sum1 = 0, sum2 = 0;
        for(int j=i;j<n;j++) {
            sum1 = sum1 - v[j];
            sum2 = sum2 + v[j];
            while(ptr1<min(sum1, A-1)) {
                ind1[i][++ptr1] = j+1;
            }
            while(ptr2<min(sum2, A-1)) {
                ind2[i][++ptr2] = j+1;
            }
        }
    }

    for(int sum=0;sum<=a+b;sum++) {
        pair<int, int> p1 = {sum - min(b, sum), min(b, sum)};
        pair<int, int> p2 = {min(a, sum), sum - min(a, sum)};
        
        r1[n] = p1;
        r2[n] = p2;
        for(int i=n-1;i>=0;i--) {
            // for p1
            int x1 = min(ind1[i][max(1, p2.first-p1.first)], ind2[i][max(1, p1.second-p1.second)]);
            int x2 = min(ind1[i][max(1, p2.first-p2.first)], ind2[i][max(1, p1.second-p2.second)]);
            if(x1==inf) {
                r1[i] = {p1.first+pre1[n]-pre1[i], p1.second+pre2[n]-pre2[i]};
            }
            else if(p1.first+pre1[x1]-pre1[i]>=p2.first) {
                r1[i] = r2[x1];
            } else {
                r1[i] = r1[x1];
            }
            if(x2==inf) {
                r2[i] = {p2.first+pre1[n]-pre1[i], p2.second+pre2[n]-pre2[i]};
            }
            else if(p2.first+pre1[x2]-pre1[i]>=p2.first) {
                r2[i] = r2[x2];
            } else {
                r2[i] = r1[x2];
            }
        }

        for(int x=0;x<=a;x++) {
            if(x>sum || sum-x>b) continue;
            int y = sum - x;
            int ind = min(ind1[0][p2.first-x], ind2[0][p1.second-y]);
            if(ind==inf) {
                ans[x][y] = x + pre1[n]-pre1[0];
                continue;
            }
            if(x+pre1[ind]-pre1[0]>=p2.first) {
                ans[x][y] = r2[ind].first;
            } else {
                ans[x][y] = r1[ind].first;
            }
        }

    }


    for(int i=0;i<=a;i++) {
        for(int j=0;j<=b;j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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