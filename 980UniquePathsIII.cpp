class Solution {
public:
int ans =0;
void solve(vector<vector<int>>grid , int i , int j , int count){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        return;
    
    if(grid[i][j] == -1 || grid[i][j]==3 )
        return ;
    
    if(grid[i][j] == 2 && count == 0){

        ans++;
        return ;
    }
    if(grid[i][j]==2 )
        return ;
    
    
    grid[i][j]=3;

    solve(grid,i, j+1 ,count-1 );
    solve(grid,i+1 , j ,count-1 );
    solve(grid,i-1 ,j ,count-1 );
    solve(grid,i , j-1 ,count-1 );
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startx=0 ,starty=0;
        int count =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){

                if(grid[i][j]==1){
                    startx=i;
                    starty=j;
                }
                if(grid[i][j]==0){
                    count++;
                }
            }
        }

        solve(grid, startx , starty , count+1);
        return ans;
        
    }
};
