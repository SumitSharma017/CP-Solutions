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

const int N = 200005;
vector<int> po[N];

void sieve() {
    for (int i = 2; i < N; ++i) {
        if (po[i].empty()) {
            for (int j = i; j < N; j += i) {
                po[j].push_back(i);
            }
        }
    }
}

int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    sieve();
    while (t--) {
        int n,k;
        cin>>n>>k;
        vll v(n);
        forn(i,n) cin>>v[i];
        vll dp(n+1,0);
        for (int i=k+1;i<=n;i++) {
            ll cur=INFLL;
            for(int p : po[i]) cur=min(cur,1ll+1ll*p*dp[i/p]);
            dp[i]=cur;
        }

        ll ans=0;
        forn(i,n) ans+=dp[v[i]];
        cout<<ans<<endl;

    }

    return 0;
}