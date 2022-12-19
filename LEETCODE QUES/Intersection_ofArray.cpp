#include<unordered_map>
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>freq ;
        for(int i=0;i<nums1.size();i++){
            freq[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(freq[nums2[i]]>0){
                    ans.push_back(nums2[i]);
                    freq[nums2[i]]--;    
            }
        }
        return ans;
    }
};