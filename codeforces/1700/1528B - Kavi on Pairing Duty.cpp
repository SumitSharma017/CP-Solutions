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

int main() {

    CIGARETTES AFTER SEX

    int n;
    cin>>n;
    vll dp(n+1,-1);
    vll sum(n+1,0);
    forsn(i,1,n+1){
        for(int j=2*i;j<n+1;j+=i) sum[j]++;
    }
    dp[0]=0;
    if(n>=1) dp[1]=1;
    if(n>=2) dp[2]=3;
    int pr=4;
    for(int i=3;i<=n;i++){
        dp[i]=(pr+sum[i]+1)%MOD;
        pr=(pr+dp[i])%MOD;
    }
    cout<<dp[n]<<endl;

    return 0;
}