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
        ll n,a,b;
        cin>>n>>a>>b;
        vll v(n);
        forn(i,n) cin>>v[i];
        // ll ans=0, cur=0;
        // vll conquered;
        // ll curidx=0;
        // forn(i,n){
        //     if(conquered.size() && a*abs(cur-conquered[curidx])<=b*abs(cur-v[i])){
        //         ans+=a*abs(cur-conquered[curidx]);
        //         cur=conquered[curidx];
        //         curidx++;
        //         i--;
        //     }else{
        //         ans+=b*abs(v[i]-cur);
        //         conquered.pb(v[i]);
        //     }
        // }
        // cout<<ans<<endl;
        if(n==1){
            cout<<b*v[0]<<endl;
            continue;
        }
        ll cur=v[n-1]*b+v[n-2]*a;
        ll ans=cur;
        vll pref(n);
        for(int i=n-1;i>0;i--) pref[i]=v[i]-v[i-1];
        pref[0]=v[0];
        for(int i=n-2;i>=0;i--){
            cur-=a*pref[i];
            cur+=b*pref[i]*(n-i-1);
            ans=min(ans,cur);
        }
        cout<<ans<<endl;
    }

    return 0;
}