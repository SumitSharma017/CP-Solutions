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
int binexp(int a, int b, int m){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans * 1LL * a)% MOD;
        }
        a = (a * 1LL * a) % MOD;
        b = b>>1;
    }
    return ans; 
    
}

int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vll v(n);
        forn(i,n) cin>>v[i];
        sort(v.begin(),v.end());
        vector<pair<ll,ll>>hash;
        forn(i,n){
            if(!i){
                hash.pb({v[i],1});
                continue;
            }
            if(v[i]==hash[hash.size()-1].fi) hash[hash.size()-1].se++;
            else hash.pb({v[i],1});
        }
        ll ans=0;
        int l=0,r=m-1;
        ll cur=1;
        if(r>=hash.size()){
            cout<<0<<endl;
            continue;
        } 
        forn(i,r+1) cur=(cur*hash[i].se)%MOD;
        if(hash[r].fi - hash[l].fi == m-1) ans=(ans+cur)%MOD;
        l++;
        r++;
        while(r<hash.size()){
            cur=(cur*(binexp(hash[l-1].se,MOD-2,MOD)))%MOD;
            cur=(cur*hash[r].se)%MOD;
            if(hash[r].fi - hash[l].fi == m-1) ans=(ans+cur)%MOD;
            r++;
            l++;
        }
        cout<<ans<<endl;
    }

    return 0;
}