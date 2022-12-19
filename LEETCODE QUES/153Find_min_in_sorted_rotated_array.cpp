class Solution {
public:
int solve(vector<int>&nums , int start , int end){
    while(start<end){
        if(nums[start]<nums[end]){
            return start;
        }
        int mid = (start +end)/2;
        if(nums[mid]>=nums[start]){
            start =mid+1;
        }
        else{
            end=mid;
        }
    }
    return start;
}
    int findMin(vector<int>& nums) {
        int n= nums.size();
       int ans = solve(nums,0,n-1);
       return nums[ans];
    }
};
