#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<ll, ll>
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

    int n;
    cin>>n;
    vll a(n),b(n);
    forn(i,n) cin>>a[i];
    forn(i,n) cin>>b[i];
    map<float,int>mp;
    map<pii,ll>mp2;
    int c=0;
    forn(i,n) {
        if(a[i]==0 && b[i]==0) c++;
        else if(a[i]){
            ll g=__gcd(a[i],b[i]);
            a[i]/=g;
            b[i]/=g;
            if(a[i]<0){
                a[i]*=-1;
                b[i]*=-1;
            }
            mp2[{-b[i],a[i]}]++;
        }
    }
    ll ans=0;
    for(auto &it : mp2) ans=max(ans,it.se);
    cout<<ans+c<<endl;

    return 0;
}