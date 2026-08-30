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
        vll pref(n),suff(n);
        pref[0]=v[0];
        int cur=0;
        for(int i=1;i<n;i++){
            pref[i]=v[cur]-(i-cur);
            if(pref[i]<v[i]) cur=i;
        }
        suff[n-1]=v[n-1];
        cur=n-1;
        for(int i=n-2;i>=0;i--){
            suff[i]=v[cur]-(cur-i);
            if(suff[i]<v[i]) cur=i;
        }
        ll ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,v[i]+pref[i]+suff[i]);
        }
        cout<<ans<<endl;


    }

    return 0;
}