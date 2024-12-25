/**
*    author:  lazyhash(yashkundu)
*    created: 21 Jun, 2024 | 22:32:06
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 5e5+10;
int cntL[MAXN] = {0}, cntR[MAXN] = {0};
ll sumL[MAXN] = {0}, sumR[MAXN] = {0};


int n;
string s;

int findPre(int x) {
    int l = 0, r = n+1;
    int mid;
    while(r-l>1) {
        mid = (l+r)>>1;
        if(cntR[mid]<x) l = mid;
        else r = mid;
    }
    return r;
}

int findSuf(int x) {
    int l = 0, r = n+1;
    int mid = 0;
    while(r-l>1) {
        mid = (l+r)>>1;
        if(cntL[n]-cntL[mid-1]<x) r = mid;
        else l = mid;
    }
    return l;
}


ll calc(int ind) {
    if(s[ind-1]=='>') {
        if(cntR[ind]>cntL[n] - cntL[ind]) {
            int p = findPre(cntR[ind] - (cntL[n] - cntL[ind]));
            return 2*((sumL[n]-sumL[ind]) - (sumR[ind]-sumR[p-1])) + ind + n + 1;
        } else {
            int p = findSuf(cntL[n]-cntL[ind] - cntR[ind]+1);
            return 2*((sumL[p]-sumL[ind]) - (sumR[ind]-sumR[0])) + ind;
        }
    } else {
        if(cntR[ind]>=cntL[n]-cntL[ind-1]) {
            int p = findPre(cntR[ind] - (cntL[n]-cntL[ind-1])+1);
            return 2*((sumL[n]-sumL[ind-1])-(sumR[ind]-sumR[p-1])) - ind + n + 1;
        } else {
            int p = findSuf(cntL[n]-cntL[ind-1] - cntR[ind]);
            return 2*((sumL[p] - sumL[ind-1]) - (sumR[ind]-sumR[0])) - ind;
        }
    }
}

 
void solve() {
    cin >> n;
    cin >> s;


    for(int i=0;i<n;i++) {
        cntL[i+1] = cntL[i] + (s[i]=='<');
        cntR[i+1] = cntR[i] + (s[i]=='>');
        sumL[i+1] = sumL[i] + i*(s[i]=='<');
        sumR[i+1] = sumR[i] + i*(s[i]=='>');
    }

    for(int i=1;i<=n;i++) {
        cout << calc(i) << " ";
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