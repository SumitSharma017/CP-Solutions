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

    ll n,m;
    cin>>n>>m;
    vll v(n);
    forn(i,n) cin>>v[i];
    ll ans=1;
    ll cur=1;
    forsn(i,1,n){
        if(v[i]!=v[i-1]) cur++;
        ans+=cur;
    }
    cur=ans;
    forsn(i,1,n){
        if(v[i]!=v[i-1]) cur-=(n-i+1);
        else cur--;
        ans+=cur;
    }
    while(m--){
        ll i,x;
        cin>>i>>x;
        i--;
        if(i!=0 && v[i]!=v[i-1]) ans-=i*(n-i);
        if(i!=n-1 && v[i+1]!=v[i]) ans-=(i+1)*(n-(i+1));
        v[i]=x;
        if(i!=0 && x!=v[i-1]) ans+=i*(n-i);
        if(i!=n-1 && x!=v[i+1]) ans+=(i+1)*(n-(i+1));
        cout<<ans<<endl;
		}
    return 0;
}