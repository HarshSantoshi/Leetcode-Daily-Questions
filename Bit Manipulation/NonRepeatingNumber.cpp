class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int>ans;
        int n = nums.size();
        int ele=nums[0];
        for(int i=1;i<nums.size();i++){
            ele=nums[i]^ele;
        }
        int first=0;
        int second=0;
        int rightMost_setbit = ele & ~(ele-1);
      
        for(int i=0;i<n;i++){
            if(nums[i]&rightMost_setbit){
                first^=nums[i];
                
            }
            else{
                
                second^=nums[i];
            }
        }
        ans.push_back(first);
        ans.push_back(second);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
    
};