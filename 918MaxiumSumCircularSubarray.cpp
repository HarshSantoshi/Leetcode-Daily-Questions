class Solution {
public:
    // int maxSubarraySumCircular(vector<int>& nums) {
    //     int total_sum =0, curr_sum1 =0 , curr_sum2=0;
    //     int maxSum_subarr  =INT_MIN;
    //     int minSum_subarr = INT_MAX;
    //     for(auto i:nums){
    //         total_sum +=i;
    //         curr_sum1+=i;
    //         curr_sum2+=i;
    //         maxSum_subarr =max(maxSum_subarr  , curr_sum1);
    //         if(curr_sum1<0)curr_sum1=0;
    //         minSum_subarr = min(curr_sum2 , minSum_subarr);
    //         if(curr_sum2>0)curr_sum2=0;
    //     }
    //     if(total_sum==minSum_subarr)return maxSum_subarr;
    //     else{
    //         return max(maxSum_subarr , total_sum - minSum_subarr);
    //     }
    // }
    int maxSubarraySumCircular(vector<int>& nums) {
        int nonCircular =kadaneAlgo(nums);
        int sum =0;
         for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            nums[i]=-nums[i];
        }
        int circular = sum + kadaneAlgo(nums);
        if(circular ==0)return nonCircular;

        return max(circular , nonCircular);
     }

    int kadaneAlgo(vector<int>&nums){
        int currSum =nums[0];
        int maxSum =nums[0];
        for(int i=1;i<nums.size();i++){
            if(currSum<0)currSum =0;
            currSum+=nums[i];
            maxSum = max(maxSum , currSum);
            
        }
        return maxSum;
    }
};
