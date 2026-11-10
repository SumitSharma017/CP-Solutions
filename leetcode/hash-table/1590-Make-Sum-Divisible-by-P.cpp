class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>seen;
        seen[0]=-1;
        int cur=0, sum=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++) sum=(sum+nums[i])%k;
        for(int i=0;i<n;i++){
            cur=(cur+nums[i])%k;
            seen[cur]=i;
            if(seen.find((cur-sum+k)%k)!=seen.end()) ans=min(ans,i-seen[(cur-sum+k)%k]);
        }
        return ans!=INT_MAX?(ans==n?-1:ans):-1;
    }
};