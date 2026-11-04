class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++) if(!nums[i]) nums[i]=-1;
        int cur=0;
        map<int,int>mp;
        mp[0]=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            if(mp.find(cur)==mp.end()) mp[cur]=i;
            else ans=max(ans,i-mp[cur]);
        }
        return ans;

    }
};