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

ll ans=0;
pii dfs(int cur,int par,vector<vector<int>>&adj,string& x){
    int cw=0,cb=0;
    for(auto it : adj[cur]) {
        if(it!=par) {
            pii abc=dfs(it,cur,adj,x);
            cw+=abc.fi;
            cb+=abc.se;
        }
    }
    if(x[cur-1]=='W') cw++;
    else cb++;
    if(cw==cb) ans++;
    return {cw,cb};
}
int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<vector<int>>adj(n+1);
        forn(i,n-1){
            int u;
            cin>>u;
            adj[i+2].pb(u);
            adj[u].pb(i+2);
        }
        string x;
        cin>>x;
        ans=0;
        dfs(1,-1,adj,x);
        cout<<ans<<endl;

    }

    return 0;
}