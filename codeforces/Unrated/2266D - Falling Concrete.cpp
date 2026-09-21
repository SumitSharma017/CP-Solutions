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
        int n;
        cin>>n;
        vll v(n);
        forn(i,n) cin>>v[i];
        //rotation in index minus array
        vll a(n);
        forn(i,n) a[i]=v[i]-i-1;
        sort(a.begin(),a.end());
        // ll ans=0,cur=1;
        // forsn(i,1,n){
        //     if(a[i]==a[i-1]) cur++;
        //     else cur=1;
        //     ans=max(ans,cur);
        // }
        // cout<<ans<<endl;
        a.erase(unique(a.begin(),a.end()),a.end());
        ll ans=0,cur=1;
        forsn(i,1,a.size()){
            if(a[i]==a[i-1]+1) cur++;
            else cur=1;
            ans=max(ans,cur);
        }
        cout<<(ans==0?ans+1:ans)<<endl;
    }

    return 0;
}