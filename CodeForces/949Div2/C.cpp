/**
*    author:  lazyhash(yashkundu)
*    created: 10 Jun, 2024 | 10:27:12
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

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

const int N = 2e5+10;
int a[N];
 
int n; 

int first = -1, last = -1;
int ind;


vector<int> calc(int a, int b) {
    int origA = a;
    vector<int> va, vb;
    vector<int> ans;
    if(a==b) {
        ans.push_back(2*a);
        return ans;
    }
    while(a>0) {
        va.push_back(a);
        a /= 2;
    }
    while(b>0) {
        vb.push_back(b);
        b /= 2;
    }
    reverse(vb.begin(), vb.end());
    for(int i=0;i<va.size();i++) {
        auto it = lower_bound(vb.begin(), vb.end(), va[i]);
        if(it!=vb.end() && *it==va[i]) {
            // found it
            ind = it - vb.begin();
            // calculate ans
            for(int j=1;j<i;j++) ans.push_back(va[j]);
            for(int j=ind;j<vb.size()-1;j++) {
                if(vb[j]==origA) continue;
                ans.push_back(vb[j]);
            }
            break;
        }
    }
    return ans;
}

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    first = -1; 
    last = -1;

    for(int i=0;i<n;i++) {
        if(a[i]!=-1) {
            first = i;
            break;
        }
    }   

    for(int i=n-1;i>=0;i--) {
        if(a[i]!=-1) {
            last = i;
            break;
        }
    }

    if(first==-1) {
        a[0] = 1;
        for(int i=1;i<n;i++) {
            if(i&1) a[i] = 2*a[i-1];
            else a[i] = a[i-1]/2;
        }
        for(int i=0;i<n;i++) cout << a[i] << " ";
        cout << "\n";
        return;
    }




    for(int i=first-1;i>=0;i--) {
        if((first-i)&1) a[i] = 2*a[i+1];
        else a[i] = a[i+1]/2;
    }

    for(int i=last+1;i<n;i++) {
        if((i-last)&1) a[i] = 2*a[i-1];
        else a[i] = a[i-1]/2;
    }


    for(int i=first;i<last;) {
        int j = i+1;
        while(j<last && a[j]==-1) j++;
        if(j-i>1) {
            vector<int> v = calc(a[i], a[j]);
            if(j-i-1>=v.size() && (j-i-1-(int)v.size())%2==0) {
                for(int k=0;k<v.size();k++) a[i+1+k] = v[k];
                for(int k=i+1+(int)v.size();k<j;k++) {
                    if((k-i-(int)v.size())&1) a[k] = 2*a[k-1];
                    else a[k] = a[k-1]/2;
                }
            } else {
                cout << "-1\n";
                return;
            }
        } else {
            if(!(a[i]==a[j]/2 || a[j]==a[i]/2)) {
                cout << "-1\n";
                return;
            }
        }
        i = j;
    }


    for(int i=0;i<n;i++) cout << a[i] << " ";
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