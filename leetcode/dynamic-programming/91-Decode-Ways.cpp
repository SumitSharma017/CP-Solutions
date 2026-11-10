class Solution {
public:
    int dp[101];
    int f(int idx, string& s){
        int ans=0; 
        if(idx==s.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        if(s[idx]!='0') ans+=f(idx+1,s);
        if(idx<s.size()-1){
            int cur=(s[idx]-'0')*10+(s[idx+1]-'0');
            if(cur>=10 && cur<=26) ans+=f(idx+2,s);
        }
        return dp[idx]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s);
    }
};