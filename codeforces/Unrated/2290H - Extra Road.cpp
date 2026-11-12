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

// void dfs(int u,int par,vector<vector<int>>& adj,vector<int>& vis){
//     vis[u]=1;
//     for(auto it : adj[u]) if(it!=par) dfs(it,u,adj,vis);
// }
int ans=0;
void dfs(int u,int par,vector<vector<int>>& adj, vector<int>& sz){
    sz[u]=1;
    priority_queue<int>pq;
    for(auto it : adj[u]){
        if(it!=par){
            dfs(it,u,adj,sz);
            sz[u]+=sz[it];
            pq.push(sz[it]);
        }
    }
    if(pq.size()) pq.pop();
    if(u!=0){
        if(pq.size()) ans=max(ans,pq.top());
    }else{
        if(pq.size()>1){
            pq.pop();
            ans=max(ans,pq.top());
        }
    }
}

int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        forn(i,n-1){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        // int ans=-1;
        // forn(i,n){
        //     if(!vis[i]){
        //         ans++;
        //         dfs(i,-1,adj,vis);
        //     }
        // }
        // cout<<ans<<endl;
        // root to leaf
        // 2 compon gtg
        // child only 1 comp
        // ans=n-max((3rd largest),(second of child?))
        ans=0;
        vector<int>sz(n);
        dfs(0,-1,adj,sz);
        cout<<n-ans<<endl;
    }

    return 0;
}