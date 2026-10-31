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
const int MOD = 998244353;

bool f=true;
// void dfs(int cur,int p,vector<vector<int>>& adj,vector<int>& ans, string& x,string& y,int idx){
//     int to=(x[cur])^(y[cur]);
//     if(ans[idx]==-1) ans[idx]=to;
//     else if(ans[idx]!=to) {
//         f=false;
//         return;
//     }
//     for(auto it : adj[cur]){
//         if(it!=p) dfs(it,cur,adj,ans,x,y,idx+1);
//         if(!f) return;
//     }
// }

void dfs(int cur,int p,vector<vector<int>>& adj,vector<int>& ans, string& x,string& y,int idx,int l){
    int to=((x[cur]-'0')^(y[cur]-'0')^l);
    if(ans[idx]==-1) ans[idx]=to;
    else if(ans[idx]!=to) {
        f=false;
        return;
    }
    for(auto it : adj[cur]){
        if(it!=p) dfs(it,cur,adj,ans,x,y,idx+1,(ans[idx]+(x[cur]-'0')+l)/2);
        if(!f) return;
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
        forn(i,n-1){
            int u,v;
            cin>>u>>v;
            v--;
            u--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        string x,y;
        cin>>x>>y;
        vector<int>ans(n,-1);
        f=true;
        dfs(0,-1,adj,ans,x,y,0,0);
        if(!f){
            cout<<-1<<endl;
            continue;
        }
        ll cur=1,final=0;
        forn(i,n){
            if(ans[i]==1) final=(final+cur)%MOD;
            cur=(cur*2)%MOD; 
        }
        cout<<final<<endl;
    }

    return 0;
}