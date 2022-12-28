#define ll long long 
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        //code here
        vector<ll int>ans;
        if(n==0)return ans;
        vector<ll int>leftProduct(n,0);
        vector<ll int>rightProduct(n,0);
        rightProduct[n-1]=1;
        //nums = 1 2 3 4
        //RightProduct = 24 12 4 1
        for(ll int i=n-2;i>=0;i--){
            rightProduct[i]=rightProduct[i+1]*nums[i+1];
        }
        leftProduct[0]=1;
        for(ll int i=1;i<n;i++){
           leftProduct[i]=leftProduct[i-1]*nums[i-1];
        }
        //LeftProduct = 1 1 2 6
        
        for(ll int i=0;i<n;i++){
            ll int product = leftProduct[i]*rightProduct[i];
            ans.push_back(product);
        }
        return ans;
    }
};
