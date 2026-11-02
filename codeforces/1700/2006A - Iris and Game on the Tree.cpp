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

int one=0,zero=0,ques=0,mid=0;
void dfs(int cur,int par,vector<vector<int>>& adj, string& s){
    if(cur!=1 && adj[cur].size()==1){
        if(s[cur-1]=='1') one++;
        else if(s[cur-1]=='0') zero++;
        else ques++;
        return;
    }else if(cur!=1 && s[cur-1]=='?') mid++;
    for(auto it : adj[cur]) if(it!=par) dfs(it,cur,adj,s);
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
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        string s;
        cin>>s;
        zero=0,one=0,ques=0,mid=0;
        dfs(1,-1,adj,s);
        ll ans=0;
        if(s[0]=='?') {
            ans+=max(zero,one);
            ans+=((ques+(one==zero && mid%2))/2);
            cout<<ans<<endl;
            continue;
        }
        else if(s[0]=='1') ans+=zero;
        else ans+=one;
        ans+=(ques+1)/2;
        cout<<ans<<endl;
        
    }

    return 0;
}