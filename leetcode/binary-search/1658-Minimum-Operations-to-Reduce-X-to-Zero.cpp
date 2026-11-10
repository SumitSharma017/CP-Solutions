class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        map<int,int>suff;
        int cur=0;
        suff[cur]=n;
        for(int i=n-1;i>=0;i--){
            cur+=nums[i];
            if(suff.find(cur)==suff.end()) suff[cur]=i;
        }
        int ans=INT_MAX;
        cur=0;
        if(suff.find(x-cur)!=suff.end()) ans=min(ans,n-suff[x-cur]);
        for(int i=0;i<n;i++){
            cur+=nums[i];
            if(cur>x) break;
            if(suff.find(x-cur)!=suff.end() && suff[x-cur]>i ) ans=min(ans,i+1+n-suff[x-cur]);
        }
        return ans==INT_MAX?-1:ans;
    }
};