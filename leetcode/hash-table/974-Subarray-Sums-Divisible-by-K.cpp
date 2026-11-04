class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        nums[0]=((nums[0]%k)+k)%k;
        for(int i=1;i<n;i++) nums[i]=(((nums[i]+nums[i-1])%k)+k)%k;
        map<int,int>mp;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            ans+=mp[nums[i]];
            mp[nums[i]]++;
        }
        return ans;
    }
};
