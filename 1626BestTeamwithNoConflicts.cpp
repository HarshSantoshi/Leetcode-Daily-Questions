class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>>nums(n);
        for(int i=0;i<n;i++){
            nums[i]={-ages[i],-scores[i]};
        }

        //sorted in decreasing order
        sort(nums.begin(), nums.end());
        int dp[n];
        memset(dp,0,sizeof(dp));
      
        int maxSum = 0;
        for(int i=0;i<n;i++){
          for(int j=i;j>=0;j--){
              if(-nums[i].second<=-nums[j].second){
                  dp[i]=max(dp[i], dp[j]-nums[i].second);
              }
          }
          maxSum = max(maxSum , dp[i]);
        }
        return maxSum;
    }
};
