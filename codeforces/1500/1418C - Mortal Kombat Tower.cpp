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

ll f(int idx,int turn,vector<vector<int>>& dp,vector<int>& v){
    if(idx>=v.size()) return 0;
    if(dp[idx][turn]!=-1) return dp[idx][turn];
    ll cur=INF;
    if(turn%2==0){
        cur=v[idx]+f(idx+1,1-turn,dp,v);
        if(idx+1<v.size()) cur=min(cur,v[idx]+v[idx+1]+f(idx+2,1-turn,dp,v));
    }else cur=min(f(idx+1,1-turn,dp,v),f(idx+2,1-turn,dp,v));
    
    return dp[idx][turn]=cur;
}
int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>v(n);
        forn(i,n) cin>>v[i];
        vector<vector<int>>dp(n,vector<int>(2,-1));
        cout<<f(0,0,dp,v)<<endl;

    }

    return 0;
}