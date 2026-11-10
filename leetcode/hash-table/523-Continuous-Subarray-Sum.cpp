class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>seen;
        seen[0]=-1;
        int pref=0;
        for(int i=0;i<n;i++){
            pref=(pref+nums[i])%k;
            if(seen.find(pref)==seen.end()) seen[pref]=i;
            else if(seen[pref]<i-1) return true;
        }
        return false;

    }
};