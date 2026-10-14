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
        string s;
        cin>>s;
        int n =s.size();
        // int ans=1;
        // map<int,string>pref,suff;
        // string cur="";
        // cur+=s[0];
        // pref[0]=cur;
        // for(int i=1;i<n;i++){
        //     if(s[i]!=cur[cur.size()-1]) cur+=s[i];
        //     pref[i]=cur;
        // }
        // string cur2="";
        // cur2+=s[n-1];
        // suff[n-1]=cur2;
        // for(int i=n-2;i>=0;i--){
        //     if(s[i]!=cur2[0]) cur2=s[i]+cur2;
        //     suff[i]=cur2;
        // }
        // map<string,bool>seen;
        // seen[cur]=true;
        // for(int i=1;i<s.size()-1;i++){
        //     string got;
        //     if(s[i-1]==s[i+1]) {
        //         if(s[i]==s[i-1]){
        //             if(s[i]=='0') got=pref[i-1]+'1'+suff[i+1];
        //             else got=pref[i-1]+'0'+suff[i+1];
        //         }else got=pref[i-1]+suff[i+1].substr(1);
        //     }else continue;
        //     if(!seen[got]) ans++;
        //     seen[got]=true;
        // }
        // cout<<ans<<endl;
        // AHHHHHHHHHHHHHHHHHH ROIGJ AOGIHAEGPIHWRGPOIWRGPOwihgwpRO IGHERPOGIHWRP GOIHRGP OIAHHPOIGAPORIGHAPOG H ADRGHAE PGOIHR GO[
        int one=0,two=0;
        for(int i=1;i<n-1;i++){
            if(s[i-1]==s[i+1]){
                if(s[i]==s[i-1]) one++;
                else two++;
            }
        }
        //01010101
        cout<<(one>0)+(two>0)+1<<endl;
    }

    return 0;
}