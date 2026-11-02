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
        vector<int>h(2e5+5,0);
        vector<set<int>>v(n);
        forn(i,n){
            int k;
            cin>>k;
            forn(j,k){
                int c;
                cin>>c;
                v[i].insert(c);
                h[c]++;
            }
        }
        bool ans=false;
        forn(i,n){
            int cur=0;
            for(auto it : v[i]){
                if(h[it]==1) break;
                cur++;
            }
            if(cur==v[i].size()){
                ans=true;
                break;
            }
        }
        cout<<(ans?"Yes":"No")<<endl;
    }

    return 0;
}