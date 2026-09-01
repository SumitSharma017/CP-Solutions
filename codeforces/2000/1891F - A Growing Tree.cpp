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

struct SegmentTree {
    int n;
    vector<ll> lazy;

    SegmentTree(int n) : n(n),lazy(4*n,0) {}

    void rangeAdd(int node,int l,int r,int ql,int qr,ll val) {
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr) {
            lazy[node]+=val;
            return;
        }
        int mid=l+(r-l)/2;
        rangeAdd(2 * node, l, mid, ql, qr, val);
        rangeAdd(2 * node + 1, mid + 1, r, ql, qr, val);
    }

    ll pointQuery(int node, int l, int r, int idx) {
        if(l==r) return lazy[node];
        int mid=l+(r-l)/2;
        if(idx<=mid) return lazy[node]+pointQuery(2*node, l, mid, idx);
        else return lazy[node] + pointQuery(2*node+1,mid+1,r,idx);
    }

    void rangeAdd(int l, int r,ll val) {
        if(l>r) return;
        rangeAdd(1,1,n,l,r,val);
    }

    ll pointQuery(int idx) {
        return pointQuery(1, 1, n, idx);
    }
};

// ================= SIEVE (COMMENTED) =================
// vll prm(10000001, 0);
// void SieveOfEratosthenes(ll n) {
//     for (ll p = 2; p * p <= n + 1; p++) {
//         if (prm[p] == 0) {
//             prm[p] = p;
//             for (ll i = p * p; i <= n; i += p)
//                 if (prm[i] == 0) prm[i] = p;
//         }
//     }
// }

void dfs(int u,int p,int& time,vector<vector<int>>& adj, vector<int>&tin, vector<int>& tout){
    tin[u]=++time;
    for(auto it : adj[u]) if(it!=p) dfs(it,u,time,adj,tin,tout);
    tout[u]=time;
}

// euler tour+seg tree(lazy)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        // first build tree with only 1 queries, then euler tour se tin aur tout then segment tree with lazy prop se update, wrong extra will be minus
        int q;
        cin>>q;
        vector<vector<int>>adj(q+2);
        vector<pair<int,pii>>seco;
        int cur=1;
        forn(i,q){
            int c;
            cin>>c;
            if(c==1){
                int v;
                cin>>v;
                cur++;
                adj[v].pb(cur);
                adj[cur].pb(v);
                seco.pb({1,{cur,-1}});
            }else {
                int a,b;
                cin>>a>>b;
                seco.pb({2,{a,b}});
            }
        }
        SegmentTree st(cur+1);
        vector<int>tin(q+2),tout(q+2);
        int time=0;
        dfs(1,-1,time,adj,tin,tout);
        for(auto it : seco){
            int type=it.fi;
            if(type==1){
                ll wrong=st.pointQuery(tin[it.se.fi]);
                st.rangeAdd(tin[it.se.fi],tin[it.se.fi],-wrong);
            }else st.rangeAdd(tin[it.se.fi],tout[it.se.fi],it.se.se);
        }
        forsn(i,1,cur+1) cout<<st.pointQuery(tin[i])<<" ";
        cout<<endl;
        
    }

    return 0;
}