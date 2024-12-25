/**
*    author:  lazyhash(yashkundu)
*    created: 10 Jun, 2024 | 15:52:10
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 

const int N = 1e5+10;
string s[N];
int type[N];

bool badNum[N]={0};

int n;


int getIntVal(string s) {
    if(s.empty()) return -1;
    for(char ch: s) {
        if(!isdigit(ch)) return -1;
    }
    if(s.size()>0 && s[0]=='0') return -1;
    return stoi(s);
}


 
void solve() {
    
    cin >> n;
    int cntEx = 0, cntReg = 0;

    for(int i=0;i<n;i++) {
        cin >> s[i] >> type[i];
        if(type[i]) cntEx++;
        else cntReg++;
    }

    
    vector<int> remEx, remReg;
    vector<int> badEx, badReg;


    for(int i=0;i<n;i++) {
        if(type[i]) {
            // example
            int val = getIntVal(s[i]);
            if(val==-1) continue;
            if(val>=1 && val<=cntEx) {
                badNum[val] = true;
            }  
            if(val>cntEx && val<=cntEx+cntReg) {
                badReg.push_back(i);
                badNum[val] = true;
            }
        }  else {
            // regular
            int val = getIntVal(s[i]);
            if(val==-1) continue;
            if(val>=1 && val<=cntEx) {
                badEx.push_back(i);
                badNum[val] = true;
            }
            if(val>cntEx && val<=cntEx+cntReg) {
                badNum[val] = true;
            }
        }
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/