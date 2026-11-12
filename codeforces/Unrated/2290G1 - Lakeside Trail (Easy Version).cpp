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
        // lol bs
        ll n,k;
        cin>>n>>k;
        vll v(n),l(n),r(n);
        forn(i,n) cin>>v[i];
        ll lp=0,rp=0;
        forn(i,n) rp=max(rp,abs(v[i]-v[(i+1)%n]));
        while(lp<rp){
            ll mid=lp+(rp-lp)/2;
            l=v;
            r=v;
            forsn(i,1,n) l[i]=max(v[i],l[i-1]-mid);
            forn(i,n) l[i]=max(v[i],l[(i-1+n)%n]-mid);
            for(int i=n-2;i>=0;i--) r[i]=max(v[i],r[i+1]-mid);
            for (int i=n-1;i>=0;i--) r[i]=max(v[i],r[(i+1)%n]-mid);
            ll cur=0;
            forn(i,n){
                cur+=max(l[i],r[i])-v[i];
                if(cur>k) break;
            }
            if(cur<=k) rp=mid;
            else lp=mid+1;
        }
        cout<<lp<<endl;
    }

    return 0;
}