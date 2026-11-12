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
        int s=0;
        vector<int>v;
        forn(i,3){
            int a;
            cin>>a;
            v.pb(a);
            s+=a;
        }
        if(s%3){
            cout<<"NO\n";
            continue;
        }
        s=s/3;
        sort(v.begin(),v.end());
        if(v[1]==s && v[2]-v[0]==2) cout<<"YES\n";
        else cout<<"NO\n";

    }

    return 0;
}