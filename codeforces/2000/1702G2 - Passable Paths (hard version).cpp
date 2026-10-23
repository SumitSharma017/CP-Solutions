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

int n;
int tim=0;
void tt(int u,int par, vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout){
    tim++;
    tin[u]=tim;
    for(auto it : adj[u]) if(it!=par) tt(it,u,adj,tin,tout);
    tout[u]=tim;
}

void de(int u,int par,int cur, vector<vector<int>>& adj, vector<int>& depth){
    depth[u]=cur;
    for(auto it : adj[u]) if(it!=par) de(it,u,cur+1,adj,depth);
}

vector<vector<int>>up;
void dfs(int u,int par,vector<vector<int>>& adj){
    up[u][0]=par;
    for(int j=1;j<20;j++) up[u][j]=up[up[u][j-1]][j-1];
    for(auto it : adj[u]) if(it!=par) dfs(it,u,adj);
}

int lca(int u,int v, vector<vector<int>>& up, vector<int>& depth){
    if(u==v) return u;
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    for(int i=0;i<20;i++) if(diff&(1ll<<i)) u=up[u][i];
    if(u==v) return u;
    for(int j=19;j>=0;j--) {
        if(up[u][j]!=up[v][j]) {
            u=up[u][j];
            v=up[v][j];
        }
    }
    return up[u][0];
}

bool is_anc(int a,int b,vector<int>& tin, vector<int>& tout){
    return tin[a]<=tin[b] && tout[a]>=tout[b];
}

int main() {

    CIGARETTES AFTER SEX

    cin>>n;
    up.resize(n+1,vector<int>(20));
    vector<vector<int>>adj(n+1);
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int>tin(n+1),tout(n+1),depth(n+1);
    tt(1,0,adj,tin,tout);
    de(1,0,1,adj,depth);
    dfs(1,0,adj);
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        vector<int>p(k);
        forn(i,k) cin>>p[i];
        vector<pii>cc(k);
        forn(i,k){
            cc[i].fi=p[i];
            cc[i].se=depth[p[i]];
        }
        sort(cc.begin(),cc.end(),[](pii a,pii b){
            return a.se>b.se;
        });
        int a=cc[0].fi;
        int b=-1;
        forsn(i,1,k) {
            if(lca(a,cc[i].fi,up,depth)!=cc[i].fi){
                b=cc[i].fi;
                break;
            } 
        }
        if(b==-1){
            cout<<"YES"<<endl;
            continue;
        }
        bool ans=true;
        forn(i,k){
            if(!(is_anc(cc[i].fi,a,tin,tout) || is_anc(cc[i].fi,b,tin,tout)) || depth[cc[i].fi]<depth[lca(a,b,up,depth)]){
                ans=false;
                break;
            }
        }
        cout<<(ans?"YES":"NO")<<endl;
    }


    return 0;
}