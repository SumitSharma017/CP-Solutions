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
        ll n,k;
        cin>>n>>k;
        vll v(n);
        forn(i,n) cin>>v[i];
        // ll ans=0;
        // forn(i,n){
        //     ans+=min(i,k+1)*v[i];
        // }
        // cout<<((ans&1)?"Alice":"Bob")<<endl;
        vector<int>pa(n);
        pa[0]=1;
        int cur=1;
        forsn(i,1,n){
            pa[i]=(cur+1)%2;
            if(i-k>=0) cur=(pa[i-k]==0);
        }
        int ans=0;
        forn(i,n) if(v[i]%2 && pa[i]) ans++;
        if(ans%2) cout<<"Alice\n";
        else cout<<"Bob\n";
    }

    return 0;
}