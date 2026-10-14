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
        int n,m;
        cin>>n>>m;
        vector<int>deg(n+1,0);
        vector<vector<int>>adj(n+1);
        forn(i,m){
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bool ans=true;
        forsn(i,1,n+1) if(deg[i]==0) ans=false;
        if(!ans){
            cout<<"Brain Melt"<<endl;
            continue;
        }
        ans=true;
        //forsn(i,1,n+1) if(deg[i]!=1) ans=false;
        vector<bool>vis(n+1,false);
        queue<int>q;
        q.push(1);
        vis[1]=true;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            for (int v:adj[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        bool co=true;
        forsn(i,1,n+1) if(!vis[i]) co=false;
        forsn(i,1,n+1) if(deg[i]>1) for(auto it:adj[i]) if(deg[it]>1) ans=false;
        if(co && ans) cout<<2<<endl;
        else cout<<"Many"<<endl;
        // if(ans){
        //     cout<<2<<endl;
        //     continue;
        // }else cout<<"Many"<<endl;

    }

    return 0;
}