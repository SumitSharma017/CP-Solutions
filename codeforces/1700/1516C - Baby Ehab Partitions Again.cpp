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

    int n;
    cin>>n;
    vll v(n);
    int sum=0;
    forn(i,n) {
        cin>>v[i];
        sum+=v[i];
    }
    if(sum%2) cout<<0<<endl;
    else{
        vector<bool> dp(sum/2+1,false);
        dp[0]=true;
        forn(i,n){
            for(int j=sum/2;j>=v[i];j--) if(dp[j-v[i]]) dp[j]=true;
        }
        if(dp[sum/2]==false) cout<<0<<endl;
        else{
            int odd=-1;
            forn(i,n) if(v[i]%2) odd=i;
            if(odd!=-1){
                cout<<1<<endl;
                cout<<odd+1<<endl;
            }else{
                while(odd==-1){
                    forn(i,n){
                        v[i]/=2;
                        if(v[i]%2) odd=i;
                    }
                }
                cout<<1<<endl;
                cout<<odd+1<<endl;
            }
        }
    }



    return 0;
}