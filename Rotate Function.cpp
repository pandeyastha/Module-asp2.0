-----------------
F(K)= F(K-1) +sum -N*(arr[N-K])    F(0)=constant calculated
-----------------

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        int sum=0;
        int f0=0;
        int size=nums.size();
        for(int i=0;i<size;++i){
            sum+=nums[i];
            f0+=nums[i]*i;
        }
        int mx=f0;
        vector<int>dp(size,INT_MIN);
        dp[0]=f0;
        for(int i=1;i<size;++i){
            dp[i]=dp[i-1] +sum-size*(nums[size-i]);
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};
-------------------------------------------------------------------------------------------------------------------------------
// reduce space complexity since you need current and prev  :. Ditch the whole array , use 2 var

--------------------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        int sum=0,f0=0,size=nums.size();
        for(int i=0;i<size;++i){
            sum+=nums[i];
            f0+=nums[i]*i;
        }
        int mx=f0;
        int first=f0;
        int second=0;
        for(int i=1;i<size;++i){
            second=first +sum-size*(nums[size-i]);
            mx=max(mx,second);
            first=second;
        }
        return mx;
    }
};
