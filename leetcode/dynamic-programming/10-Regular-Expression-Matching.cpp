
class Solution {
public:
    int dp[21][21];
    bool f(int i,int j,string& s,string& p) {
        if(j<0) return i<0;
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
        bool ans = false;
        if (p[j]=='*'){
            ans=f(i,j-2,s,p);
            if(i>=0 && (s[i]==p[j-1] || p[j-1]=='.')) ans=ans||f(i-1,j,s,p);
        }
        else if(i>=0 && (s[i]==p[j] || p[j]=='.')) ans=f(i-1,j-1,s,p);   
        return dp[i+1][j+1]=ans;
    }

    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return f(s.size()-1,p.size()-1,s,p);
    }
};
