class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(cost1+cost2>=costBoth){
            int done=min(need1,need2);
            ans+=1LL*costBoth*done;
            need1-=done;
            need2-=done;
            if(need1==0){
                if(cost2<=costBoth) ans+=1LL*cost2*need2;
                else ans+=1LL*costBoth*need2;
                return ans;
            }else{
                if(cost1<=costBoth) ans+=1LL*cost1*need1;
                else ans+=1LL*costBoth*need1;
                return ans;
            }
        }else{
            ans+=1LL*need1*cost1;
            ans+=1LL*need2*cost2;
            return ans;
        }

    }
};