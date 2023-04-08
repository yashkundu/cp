/**
*   author: lazyhash(yashkundu)
*   created: 04 Mar, 2023 | 07:57:42
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 90;
int dp1[N][N] = {0};
int dp2[N][N][N] = {0};
string s;
 
int lcs(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    for(int i=0;i<=n1;i++) for(int j=0;j<=n2;j++) dp1[i][j] = 0;
    
    for(int i=1;i<=n1;i++) {
        for(int j=1;j<=n2;j++) {
            if(s1[i-1]==s2[j-1]) dp1[i][j] = 1 + dp1[i-1][j-1];
            else dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]);
        }
    }
    return dp1[n1][n2]*2;
}


int lcs(string s1, string s2, string s3) {
   
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    for(int i=0;i<=n1;i++) for(int j=0;j<=n2;j++) for(int k=0;k<=n3;k++) dp2[i][j][k] = 0;
    for(int i=1;i<=n1;i++) for(int j=1;j<=n2;j++) for(int k=1;k<=n3;k++) {
        if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]) dp2[i][j][k] = 1 + dp2[i-1][j-1][k-1];
        else dp2[i][j][k] = max({dp2[i-1][j][k], dp2[i][j-1][k], dp2[i][j][k-1]});
    }
    return dp2[n1][n2][n3]*3;
}

int checkSeq(vector<char> &seq) {
    if(seq.empty()) return 0;
    int n = s.size();
    int m = seq.size();
    int cnt = 0;
    int ptr = 0;
    for(int i=0;i<n;i++) {
        if(s[i]==seq[ptr]) ptr++;
        if(ptr==m) {
            ptr = 0;
            cnt++;
        }
    }
    return cnt;
}

int checkAllSubseq(string s) {
    int n = s.size();   
    int ans = 0;
    for(int mask=0;mask<(1<<n); mask++) {
        vector<char> seq;
        for(int j=0,k=1;j<n;j++,k*=2) {
            if(mask&k) seq.push_back(s[j]);
        }
        int cnt = checkSeq(seq);
        if(cnt>1) ans = max(ans, cnt*(int(seq.size())));
    }
    return ans;
}

 
void solve() {
    cin >> s;
    int n = s.size();

    int ans = 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i+j==n) {
        ans = max(ans, lcs(s.substr(0, i), s.substr(i, j)));
    }

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) if(i+j+k==n) ans = max(ans, lcs(s.substr(0, i), s.substr(i, j), s.substr(i+j, k)));



    int k = n/5;
    if(k<1) {
        cout << ans << "\n";
        return;
    }


    for(int j=0;j<4*k;j+=k) {
        ans = max(ans, checkAllSubseq(s.substr(j, k)));
    }
    ans = max(ans, checkAllSubseq(s.substr(4*k, n-4*k)));

    cout << ans << "\n";




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