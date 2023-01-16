class Solution {
  public:
  #define ll long long
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<ll>res(n,-1);
        
        stack<ll>st;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top();
            }
            st.push(arr[i]);
        }
        return res;
        
    }
};
