class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //T.C=O(N*M)  S.C=O(N*M)
        // vector<int>res;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         res.push_back(matrix[i][j]);
        //     }
        // }

        // sort(res.begin() , res.end());
        // return res[k-1];






        //T.C=O(nlogn) S.C =O(1)
        int n  = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low<high){
            int mid = low + (high-low)/2;
            int count =0;
            for (int i=0;i<n;i++){
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
                // upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if(count<k){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};
