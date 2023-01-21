

class Solution {
public:
   
    void solve(vector<int> nums, int index, vector<int> sq, set<vector<int>>& ans){
      
        if(index>=nums.size()){
            if(sq.size()>1)
                ans.insert(sq);
            return ;
        }
       
        if(sq.size()==0 || nums[index] >= sq.back()){
            sq.push_back(nums[index]);
            solve(nums, index+1, output, ans);
            sq.pop_back();
        }
        solve(nums, index+1, output, ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
       
        vector<int> output;
        set<vector<int>> ans;
        
        solve(nums, 0, output, ans);
        return vector(ans.begin(), ans.end());
    }
};
