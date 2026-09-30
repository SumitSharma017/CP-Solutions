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
const int N=1e7+2;
vll SPF(N);

void pre(){
    forn(i,N) SPF[i]=i;
    for(int i=2;i*i<N;i++){
        if(SPF[i]==i){
            for(int j=i;j<N;j+=i) if(SPF[j]==j) SPF[j]=i;
        }
    }
}

int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    pre();
    while (t--) {
        ll x,y;
        cin>>x>>y;
        // if(abs(x-y)==1){
        //     cout<<-1<<endl;
        //     continue;
        // }
        // if(__gcd(x,y)!=1){
        //     cout<<0<<endl;
        //     continue;
        // }
        // ll ans=0;
        // while(__gcd(x,y)==1){
        //     x++;
        //     y++;
        //     ans++;
        // }
        // cout<<ans<<endl;
        ll diff=y-x;
        vll pr;
        while(diff!=1){
            ll div=SPF[diff];
            pr.pb(div);
            while(diff%div==0) diff/=div;
        }
        if(pr.size()==0){
            cout<<-1<<endl;
            continue;
        }
        ll ans=INFLL;
        forn(i,pr.size()) ans=min(ans,(x+pr[i]-1)/pr[i]*pr[i]-x);
        cout<<ans<<endl;

    }

    return 0;
}