class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      vector<vector<int>>ans;
      if(intervals.size()==0) return ans;

      if(intervals.size()==1) return intervals;

      sort(intervals.begin() ,intervals.end());
      int n = intervals.size();
      for(int i=0;i<n;i++)
      {
          if(ans.empty())
          {
              ans.push_back(intervals[i]);
          }
          else
          {
              vector<int>&v = ans.back();
              //end time
              int end = v[1];
              //Overlapping
              if(intervals[i][0]<=end)
              {
                  v[1]=max(end, intervals[i][1]);
              }
              //Not Overlapping
              else
              {
                  ans.push_back(intervals[i]);
              }
          }
      }
      return ans;
    }
};
