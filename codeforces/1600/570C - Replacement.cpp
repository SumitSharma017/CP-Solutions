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

    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int ans=0,cur=0;
    s='1'+s+'1';
    forsn(i,1,n+2){
        if(s[i]=='.') s[i]='0';
        else s[i]='1';
    }

    forn(i,n+2){
        if(s[i]=='0') cur++;
        else if(cur>0) {
            ans+=cur-1;
            cur=0;
        }
    }
    if(cur>0) ans+=cur-1;
    while(m--){
        int idx;
        char ch;
        cin>>idx>>ch;
        if(ch=='.'){
            ch='0';
            if(s[idx]=='0') cout<<ans<<endl;
            else{
                if(s[idx-1]=='0') ans++;
                if(s[idx+1]=='0') ans++;
                cout<<ans<<endl;
            }
        }else{
            ch='1';
            if(s[idx]=='1') cout<<ans<<endl;
            else{
                if(s[idx+1]=='0') ans--;
                if(s[idx-1]=='0') ans--;
                cout<<ans<<endl;
            }
        }
        s[idx]=ch;
    }

    return 0;
}