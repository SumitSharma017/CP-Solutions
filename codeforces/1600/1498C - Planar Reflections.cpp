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

ll dp[1001][1001][2];

ll f(ll val,ll hit,ll d,ll n,ll k){
    if(val==0) return 0;
    if(hit<0 || hit>=n) return 1;
    if(dp[val][hit][d]!=-1) return dp[val][hit][d];
    ll cur=0;
    if(d==1){
        cur=(cur+f(val,hit+1,d,n,k))%MOD;
        cur=(cur+f(val-1,hit-1,1^d,n,k))%MOD;
    }else{
        cur=(cur+f(val-1,hit+1,1^d,n,k))%MOD;
        cur=(cur+f(val,hit-1,d,n,k))%MOD;
    }
    return dp[val][hit][d]=cur;
}

int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        cout<<f(k,0,1,n,k)<<endl;

    }

    return 0;
}