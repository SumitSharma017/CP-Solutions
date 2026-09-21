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
        int n;
        cin>>n;
        string s;
        cin>>s;
        ll ans=0;
        int idx=-1;
        forn(i,n){
            if(s[i]=='1'){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            cout<<0<<endl;
            continue;
        }
        if(idx==0){
            forn(i,n) if(s[i]=='0')ans++;
            cout<<ans<<endl;
            continue;
        }
        vll pref(n+1,0);
        forn(i,n) pref[i+1]=pref[i]+(s[i]=='1');
        ans=n;
        for(int i=idx;i<=n;i++) ans=min(ans, pref[i]+n-i-(pref[n]-pref[i]));
        cout<<ans<<endl;
    }

    return 0;
}