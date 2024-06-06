/**
*   author: lazyhash(yashkundu)
*   created: 25 Mar, 2024 | 08:22:16
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <map>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


map<int, int> cnt;
string s;
int n;


void appendChar(string &s, int idx) {
    s += (char)('a'+idx);
}

void fillUp(string &s, map<int, int> &cnt) {
    for(auto p: cnt) {
        for(int j=0;j<p.second;j++) appendChar(s, p.first);
    }
}



string createAABStr() {
    // aab | ab ac ad af ag ay yyzzzzz


    map<int, int> newCnt(cnt);
    string newS = "";
    auto it = newCnt.begin();
    appendChar(newS, it->first);
    appendChar(newS, it->first);
    it->second -= 2;
    it++;
    appendChar(newS, it->first);
    it->second--;
    if(it->second==0) newCnt.erase(it);

    // newCnt.begin()->second | n - 3 - newCnt.begin()->second
    int mnCnt = newCnt.begin()->second;
    int mnIdx = newCnt.begin()->first;
    int others = n - 3 - mnCnt;

    if(mnCnt>others+1) {
        return "";
    }

    newCnt.erase(newCnt.begin());

    for(auto p: newCnt) {
        for(int j=0;j<p.second; j++) {
            // a p.first
            if(mnCnt) {
                appendChar(newS, mnIdx);
                mnCnt--;
            }
            appendChar(newS, p.first);
        }
    }

    assert(mnCnt<=1);
    if(mnCnt) appendChar(newS, mnIdx);
    return newS;
}


string createABStr() {
    // ab | ac

    map<int, int> newCnt(cnt);
    string newS = "";
    auto it = newCnt.begin();
    appendChar(newS, it->first);
    it->second--;
    it++;
    appendChar(newS, it->first);
    it->second--;

    it++;
    if(it!=newCnt.end()) {
        auto it2 = newCnt.begin();
        for(int j=0;j<it2->second;j++) {
            appendChar(newS, it2->first);
        }
        it2->second = 0;
        appendChar(newS, it->first);
        it->second--;
        fillUp(newS, newCnt);
        return newS;
    }

    it--;
    for(int j=0;j<it->second;j++) appendChar(newS, it->first);
    it--;
    for(int j=0;j<it->second;j++) appendChar(newS, it->first);
    return newS;
}

 
void solve() {
    cin >> s;

    n = s.size();

    cnt.clear();

    int mnIdx = 26;
    for(int i=0;i<n;i++) {
        mnIdx = min(mnIdx, s[i]-'a');
        cnt[s[i]-'a']++;
    }

    for(auto it = cnt.begin(); it!=cnt.end(); it++) {
        if(it->second==1) {
            string newS = "";
            appendChar(newS, it->first);
            it->second--;
            fillUp(newS, cnt);
            cout << newS << "\n";
            return;
        }
    }



    if(cnt[mnIdx]<=2) {
        sort(s.begin(), s.end());
        cout << s << "\n";
        return;
    }

    if(cnt[mnIdx]==n) {
        cout << s << "\n";
        return;
    }

    string newS = createAABStr();
    if(newS!="") {
        cout << newS << "\n";
        return;
    }

    newS = createABStr();
    cout << newS << "\n";
    return;


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