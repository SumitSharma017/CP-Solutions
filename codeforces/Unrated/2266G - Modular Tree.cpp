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
ll dfs(int u,int par,vector<vector<int>>& adj,vector<bool>& vis, vll& a,vll& b){
    vis[u]=true;
    ll cur=0,s=b[u];
    for(auto it : adj[u]){
        if(!vis[it]){
            cur+=a[it];
            ll gc=dfs(it,u,adj,vis,a,b);
            if(gc!=b[it]) s=__gcd(s,gc);
        }
    }
    s=__gcd(cur,s);
    ans+=b[u]+a[u]%s-s;
    return s;
}

int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vll a(n),b(n);
        forn(i,n) cin>>a[i];
        forn(i,n) cin>>b[i];
        vector<vector<int>>adj(n+1);
        forn(i,n-1){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<bool>vis(n+1,false);
        dfs(0,-1,adj,vis,a,b);
        cout<<ans<<endl;
        ans=0;
    }

    return 0;
}
