class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size(); 
        int col = mat[0].size();
        if(rows*col!=r*c){
            return mat;
        }
        vector<int>data;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                data.push_back(mat[i][j]);
            }
        }
        vector<vector<int>>ans(r,vector<int>(c,0));
        int k=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               ans[i][j]=data[k];
               k++;
            }
        }
        return ans;
        
    }
};

//Best optimized approach
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size(); 
        int col = mat[0].size();
        if(rows*col!=r*c){
            return mat;
        }
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<rows*col;i++){
            ans[i/c][i%c]=mat[i/col][i%col];      
        }
        return ans;
    }
};