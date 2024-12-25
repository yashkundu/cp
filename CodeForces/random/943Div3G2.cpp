/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jun, 2024 | 13:39:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5+5;
const int SQRT = 400;
const int MAXM = 500;
int ans[MAXN];


int occCnt[MAXM+1];


int n, l, r;
string s;
vector<int> pi;

void prefFunc(string &s) {
    pi.resize(n);
    pi[0] = 0;
    int j = pi[0];
    for(int i=1;i<n;i++) {
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
    }
}

int cnt = 0;
int curj = 0;

int maxOcc(int k) {
    if(k==0) return 0;
    cnt = 0;
    curj = 0;
    for(int i=0;i<n;i++) {
        while(curj>0 && s[i]!=s[curj]) curj = pi[curj-1];
        if(s[i]==s[curj]) curj++;
        if(curj==k) {
            cnt++;
            curj = 0;
        }
    }
    return cnt;
}

int L, R;
int mid;


int findAns(int k) {
    L = 0;
    R = 2e5;
    while(L<R) {
        mid = (L+R+1)/2;
        if(maxOcc(mid)>=k) L = mid;
        else R = mid - 1;
    }
    return L;
}


 
void solve() {
    cin >> n >> l >> r;
    cin >> s;
    prefFunc(s);

    for(int i=0;i<=MAXM;i++) occCnt[i] = maxOcc(i);

    for(int i=1;i<SQRT;i++) ans[i] = findAns(i);

    int j = MAXM;
    for(int i=SQRT;i<=n;i++) {
        while(j>0 && occCnt[j]<i) j--;
        ans[i] = j;
    }

    for(int i=l;i<=r;i++) cout << ans[i] << " ";
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