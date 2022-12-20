class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>res;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res.push_back(matrix[i][j]);
            }
        }

        sort(res.begin() , res.end());
        return res[k-1];
    }
};
