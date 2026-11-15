class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0,even=1,cur=0,mod=1e9+7,ans=0;
        for(int i=0;i<arr.size();i++){
            cur+=arr[i];
            if(cur%2) odd++;
            else even++;
            if(cur%2) ans=(ans+even)%mod;
            else ans=(ans+odd)%mod;
        }
        return ans;
    }
};