class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans =0;
        if(n==0)return 0;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(strs[j-1][i] >strs[j][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
