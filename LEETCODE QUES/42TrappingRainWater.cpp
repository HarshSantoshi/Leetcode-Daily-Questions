class Solution {
public:
int max(int a , int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int min(int a , int b){
    if(a>b){
        return b;
    }
    return a;
}
    int trap(vector<int>& height) {
        int n = height.size();
        int *left = new int [n];
       left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1], height[i]);
            
        }
        int *right = new int[n];
        right[n-1]=height[n-1];
        for(int i=n-2 ; i>=0;i--){
            right[i]=max(right[i+1] , height[i]);
        }
        
        int sum =0;
        for(int i=0;i<n;i++){
          sum+=min(left[i] ,right[i]) - height[i];
           
        }
        return sum;
    }
};
