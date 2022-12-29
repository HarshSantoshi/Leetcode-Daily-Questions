class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        vector<vector<int>>res;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
       
        for(int i=0;i<nums.size();i++){
            vector<int>p;
            if(map[nums[i]]!=-1){
                p.push_back (map[nums[i]] );
                p.push_back(nums[i]);
                map[nums[i]]=-1;
                res.push_back(p);
            }
        }
        sort(res.begin(),res.end(), greater<>());
        for(int i=0;i<k;i++){
            ans.push_back(res[i][1]);
        }
        return ans;
    }
};
