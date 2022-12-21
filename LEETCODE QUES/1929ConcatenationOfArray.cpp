class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        //Brute Force T.C=O(N) and 2 for loops   S.C=O(N);
        // vector<int>ans;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     ans.push_back(nums[i]);
        // }
        // for(int i=n;i<2*n;i++){
        //     ans.push_back(nums[i-n]);
        // }
        // return ans;


        //T.C =O(N) and 1 for loop  S.C =O(N)
        // int n = nums.size();
        // vector<int>ans(2*n);
        
        // for(int i=0;i<n;i++){
        //     ans[i]=nums[i];
        //     ans[i+n]=nums[i];
        // }
        // return ans;

        //Optimised T.C=O(N) and S.C =O(1);

        int n = nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
