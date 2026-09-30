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

    ll u,v;
    cin>>u>>v;
    if(u>v || (u%2)!=(v%2)){
        cout<<-1<<endl;
        return 0;
    }
    if(u==v){
        if(u){
            cout<<1<<endl;
            cout<<u<<endl;
        }else cout<<0<<endl;
        return 0;
    }
    // a+b=(a^b)+2(a&b);
    // v=u+2x;
    // 2x=v-u;
    // x=(v-u)/2;
    ll x=(v-u)/2;
    ll a=0,b=0,can=1;
    for(int i=60;i>=0;i--){
        if(x&(1ll<<i)){
            if(u&(1ll<<i)){
                can=false;
                break;
            }
        }
    }
    if(can){
        cout<<2<<endl;
        cout<<u+x<<" "<<x<<endl;
    }else{
        cout<<3<<endl;
        cout<<u<<" "<<x<<" "<<x<<endl;
    }

    return 0;
}
/*
1010

0010
0100

1000
0101

*/