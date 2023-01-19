class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int K) 
    {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%K;
        }
    
        vector<int> count(K);
        count[0] = 1;
        int prefix = 0, ans = 0;
        for (int it : nums) {
            prefix = (prefix + it  + K) % K;
            ans += count[prefix];
            count[prefix]++;
        }
        return ans;
    
    }
};
