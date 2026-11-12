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
        vector<int>v(n);
        forn(i,n) cin>>v[i];
        sort(v.begin(),v.end());
        vector<int>ans(n);
        int aage=1,pi=n-1;
        ans[0]=v[0];

        forsn(i,1,n){
            if(v[i]==v[i-1]) ans[pi--]=v[i];
            else ans[aage++]=v[i];
        }
        vector<int>done(n,0);
        int mx=0;
        forn(i,n){
            if(ans[i]>mx) done[i]=1;
            mx=max(mx,ans[i]);
        }
        mx=0;
        for(int i=n-1;i>=0;i--){
            if(ans[i]>mx) done[i]=1;
            mx=max(mx,ans[i]);
        }
        int an=0;
        forn(i,n) if(done[i]) an++;
        cout<<an<<endl;
        forn(i,n) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}