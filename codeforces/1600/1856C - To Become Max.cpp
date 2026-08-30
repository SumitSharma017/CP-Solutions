#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define forn(i,e) for(ll i=0;i<e;i++)
#define forsn(i,s,e) for(ll i=s;i<e;i++)
#define rforn(i,s) for(ll i=s;i>=0;i--)
#define vll vector<long long>
#define CIGARETTES ios_base::sync_with_stdio(false);
#define AFTER cin.tie(0);
#define SEX cout.tie(0);

const int INF = 1e9;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;

int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vll v(n);
        forn(i,n) cin>>v[i];
        int l=*max_element(v.begin(),v.end());
        int r=l+k,ans=0;
        
        auto f=[&](int mx){
            forn(i,n){
                ll cost=0,cur=mx,idx=i;
                while(idx<n && v[idx]<cur){
                    cost+=(cur-v[idx]);
                    cur--;
                    idx++;
                }
                if(idx<n && cost<=k) return true;
            }
            return false;
        };
        while(l<=r){
            ll m=(l+r)/2;
            if(f(m)){
                ans=m;
                l=m+1;
            }else r=m-1;
        }
        cout<<ans<<endl;
    }

    return 0;
}