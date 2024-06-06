
/**
*   author: lazyhash(yashkundu)
*   created: 06 May, 2024 | 07:51:55
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

const int N = 202;
int dp[N][N][2*N];

char trace[N][N][2*N];
pair<int, int> prevState[N][N][2*N];

const int inf = 1e9+10;

 
string s, t;
vector<char> ans;

void solve() {
    cin >> s >> t;

    int n1 = s.size(), n2 = t.size();

    for(int i=0;i<=n1;i++) for(int j=0;j<=n2;j++) for(int bal=0;bal<2*N;bal++) {
        dp[i][j][bal] = inf;
    }

    dp[0][0][0] = 0;

    for(int i=0;i<=n1;i++) {
        for(int j=0;j<=n2;j++)  {
            if(i==n1 && j==n2) continue;
            for(int bal=0;bal<2*N;bal++) {
                if(dp[i][j][bal]==inf) continue;
                // (
                if(bal<2*N-1) {
                    int newI = i, newJ = j;
                    if(i<n1 && s[i]=='(') newI++;
                    if(j<n2 && t[j]=='(') newJ++;
                    if(dp[newI][newJ][bal+1]>dp[i][j][bal]+1) {
                        trace[newI][newJ][bal+1] = '(';
                        dp[newI][newJ][bal+1] = dp[i][j][bal] + 1;
                        prevState[newI][newJ][bal+1] = {i, j};
                    }
                }
                // )
                if(bal>0) {
                    int newI = i, newJ = j;
                    if(i<n1 && s[i]==')') newI++;
                    if(j<n2 && t[j]==')') newJ++;
                    if((newI!=i || newJ!=j) && dp[newI][newJ][bal-1]>dp[i][j][bal]+1) {
                        trace[newI][newJ][bal-1] = ')';
                        dp[newI][newJ][bal-1] = dp[i][j][bal] + 1;
                        prevState[newI][newJ][bal-1] = {i, j};
                    }
                }
            }
        }
    }


    int x1 = n1, x2 = n2;
    int bal = -1;
    int minLen = inf;


    for(int k=0;k<2*N;k++) {
        if(dp[n1][n2][k]+k<minLen) {
            minLen = dp[n1][n2][k] + k;
            bal = k;
        }
    }

    for(int j=0;j<bal;j++) ans.push_back(')');



    while(x1 || x2 || bal) {
        char ch = trace[x1][x2][bal];
        ans.push_back(ch);
        int newX1 = prevState[x1][x2][bal].first;
        int newX2 = prevState[x1][x2][bal].second;
        x1 = newX1;
        x2 = newX2;
        if(ch=='(') bal--;
        else bal++;
    }

    for(auto it=ans.rbegin(); it!=ans.rend(); it++) {
        cout << *it;
    }
    cout << "\n";


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