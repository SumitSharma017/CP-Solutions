class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        for(int i=0;i<n;i++) hours[i]=(hours[i]>8?1:-1);
        int cur=0;
        int ans=0;
        map<int,int>seen;
        seen[0]=-1;
        for(int i=0;i<n;i++){
            cur+=hours[i];
            if(cur>0) ans=i+1;
            else if(seen.find(cur-1)!=seen.end()) ans=max(ans,i-seen[cur-1]);
            if(seen.find(cur)==seen.end()) seen[cur]=i;
        }
        return ans;
    }
};