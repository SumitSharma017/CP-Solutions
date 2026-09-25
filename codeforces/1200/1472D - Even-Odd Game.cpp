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
        vll v(n);
        forn(i,n) cin>>v[i];
        sort(v.rbegin(),v.rend());
        ll a=0,b=0;
        forn(i,n){
            if(i%2){
                if(v[i]%2) b+=v[i];
            }else if(v[i]%2==0) a+=v[i];
        }
        if(a>b) cout<<"Alice"<<endl;
        else if(a<b) cout<<"Bob"<<endl;
        else cout<<"Tie"<<endl;
    }

    return 0;
}