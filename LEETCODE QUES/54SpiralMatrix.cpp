class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>ans;
    
    int l = 0 , r = n-1, t=0,b=m-1;
    int direction = 1;
    while(l<=r && t<=b){
    //left to right(l to r)
    //r--
    if(direction==1){
        int left =l;
         while(left<=r){
        ans.push_back(matrix[t][left]);
        left++;
    }
    t++;
    direction =2; 
    }

    //top to bottom(t to b)
    else if(direction==2){
        int top =t;
  
        while(top<=b){
        ans.push_back(matrix[top][r]);
        top++;
    }
    r--;
    direction =3;
    }
    

    //right to left(r to l)
    else if(direction==3){
         int right = r;
   
        while(right>=l){
        ans.push_back(matrix[b][right]);
        right--;
    }
    b--;
    direction=4;
    
    }
   


    //bottom to top(b to t)
else if(direction==4){
    int bottom = b;
  
         while(bottom>=t){
        ans.push_back(matrix[bottom][l]);
        bottom--;
    }
    l++;   
    direction=1;
}    
    }
        return ans;
    }
};
