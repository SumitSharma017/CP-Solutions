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
#define vi vector<int>
#define CIGARETTES ios_base::sync_with_stdio(false);
#define AFTER cin.tie(0);
#define SEX cout.tie(0);

const int INF = 1e9;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int N = 400005;
vi col(N);
vector<vi>adj(N);
vi order(N);

void dfs(int u,int p,int& time,vi& tin, vi& tout){
    tin[u]=time;
    order[time]=u;
    time++;
    for(auto it : adj[u]) if(it!=p) dfs(it,u,time,tin,tout);
    tout[u]=time;
}

ll tree[4*N],lazy[4*N];
void build(int node, int l, int r) {
    lazy[node]=-1;
    if(r-l==1) {
        int u=order[l];
        tree[node]=1ll<<(col[u]-1);
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid,r);
    tree[node] =tree[node*2]|tree[node*2+1];
}

void push(int node) {
    if(lazy[node]==-1) return;
    ll mask = lazy[node];
    tree[node*2]=mask;
    tree[node*2+1]=mask;
    lazy[node*2]=mask;
    lazy[node*2+1]=mask;
    lazy[node] = -1;
}

void update(int node,int l,int r,int ql,int qr,ll mask) {
    if(qr<=l || r<=ql) return;
    if(ql<=l && r<=qr){
        tree[node]=mask;
        lazy[node]=mask;
        return;
    }
    push(node);
    int mid=(l+r)/2;
    update(node*2,l,mid,ql,qr,mask);
    update(node*2+1,mid,r,ql,qr,mask);
    tree[node] =tree[node*2]|tree[node*2+1];
}
ll query(int node,int l,int r,int ql,int qr) {
    if(qr<=l || r<=ql) return 0;
    if(ql<=l && r<=qr) return tree[node];
    push(node);
    int mid=(l+r)/2;
    return query(node*2,l,mid,ql,qr) | query(node*2+1,mid,r,ql,qr);
}

int main() {

    CIGARETTES AFTER SEX
    // euler tour + seg tree(lazy) + bitmasking
    // prettyass question
    int n,m;
    cin>>n>>m;
    forsn(i,1,n+1) cin>>col[i];
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi tin(n+1),tout(n+1);
    int time=0;
    dfs(1,-1,time,tin,tout);
    build(1,0,n);
    while(m--){
        int c;
        cin>>c;
        if(c==1){
            int v,co;
            cin>>v>>co;
            update(1,0,n,tin[v],tout[v],(1ll<<(co-1)));
        }else{
            int v;
            cin>>v;
            cout<<__builtin_popcountll(query(1,0,n,tin[v],tout[v]))<<endl;
        }
    }
    

    return 0;
}
