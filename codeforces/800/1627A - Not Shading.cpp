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
        ll n,m,r,c;
        cin>>n>>m>>r>>c;
        vector<string> s(n);

        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        bool psbl=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='B')psbl=true;
            }
        }

        if(!psbl){
            cout<<-1<<'\n';
            continue;
        }

        if(s[r-1][c-1]=='B'){
            cout<<0<<'\n';
            continue;
        }

        psbl=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='B'){
                    if((i+1)==r||(j+1)==c)psbl=true;
                }
            }
        }

        if(psbl)cout<<1<<'\n';
        else cout<<2<<'\n';
    }

    return 0;
}