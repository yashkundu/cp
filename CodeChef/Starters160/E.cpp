/**
*    author:  lazyhash(yashkundu)
*    created: 16 Nov, 2024 | 13:59:52
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 501;

int cnt[MAXN][MAXN];
int arr[MAXN];
int tot[MAXN];

int n, m;
int a, b, del;

int d1, x1, d2, x2;
int d;
 
void solve() {
    cin >> n >> m;
    for(int i=0;i<m;i++) for(int j=0;j<m;j++) cnt[i][j] = 0;
    for(int i=0;i<m;i++) tot[i] = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[j];
            arr[j]--;
            tot[arr[j]] += m-j-1;
        }
        for(int j=0;j<m;j++) {
            for(int k=j+1;k<m;k++) {
                cnt[arr[j]][arr[k]]++;
            }
        }
    }


    for(int i=0;i<m;i++) {
        for(int j=i+1;j<m;j++) {
            a = i; b = j;
            if(tot[b]>tot[a] || (tot[a]==tot[b] && b<a)) swap(a, b);
            del = tot[a]-tot[b];
            if(a<b) del++;
            d1 = d2 = 0;
            x1 = x2 = -1;
            for(int k=0;k<m;k++) {
                if(k==a || k==b) continue;
                d = cnt[a][k] - cnt[b][k];
                if(d>d1) {
                    d2 = d1;
                    x2 = x1;
                    d1 = d;
                    x1 = k;
                } else if(d>d2) {
                    d2 = d;
                    x2 = k;
                }
            }
            if(d1+d2>=del) {
                int num = 1;
                if(d2>0) num++;
                cout << num << "\n";
                cout << x1+1;
                if(num>1) cout << " " << x2+1;
                cout << "\n";
                return;
            }
        }
    }

    cout << "-1\n";



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