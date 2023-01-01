class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start =0;
        int end= nums.size();

        while(end>start){
            int mid = (start + end )/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start =mid+1;
            }
            else{
                end=mid;
            }
        }
        return start;
    }
};
