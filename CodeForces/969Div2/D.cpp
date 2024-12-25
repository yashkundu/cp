/**
*    author:  lazyhash(yashkundu)
*    created: 30 Aug, 2024 | 21:27:52
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(1e5)+10;

vector<int> g[MAXN];

int n;
string s;
int u, v;

int freq[3];

void dfs(int v, int p) {
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
    }
    if(g[v].size()==1 && v) {
        if(s[v]=='?') freq[2]++;
        else freq[s[v]-'0']++;
    }
}

int qcnt = 0;

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<3;i++) freq[i] = 0;


    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    cin >> s;
    


    qcnt = 0;
    for(int i=0;i<n;i++) if(s[i]=='?') qcnt++;



    dfs(0, -1);



    if(s[0]!='?') {
        int x = (s[0] - '0');
        int ans = freq[x^1] + (freq[2]+1)/2;
        cout << ans << "\n";
        return;
    }

    int ans = 0;

    for(int x=0;x<2;x++) {
        ans = max(ans, freq[x^1] + freq[2]/2);
    }

    // if(freq[2]) {
    //     freq[2]--;
    //     freq[0]++;
    //     int curans = (int)1e9+10;
    //     for(int x=0;x<2;x++) {
    //         curans = min(curans, freq[x^1] + (freq[2]+1)/2);
    //     }
    //     ans = max(ans, curans);
    //     freq[0]--;
    //     freq[1]++;
    //     curans = (int)1e9+10;
    //     for(int x=0;x<2;x++) {
    //         curans = min(curans, freq[x^1] + (freq[2]+1)/2);
    //     }
    //     ans = max(ans, curans);
    //     freq[1]--;
    //     freq[2]++;
    // } 

    if(qcnt>freq[2]+1 && (qcnt-freq[2]-1)%2==1) {
        int curans = (int)1e9+10;
        for(int x=0;x<2;x++) {
            curans = min(curans, freq[x^1] + (freq[2]+1)/2);
        }
        ans = max(ans, curans);
    }


    cout << ans << "\n";





    
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