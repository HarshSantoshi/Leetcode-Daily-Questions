class Solution{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector<int>next(long long arr[],int n){
        vector<int>nextArr(n,0);
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){
                s.pop();
            }
          
            nextArr[i]=s.top();
            s.push(i);
        }
        return nextArr;
    }
    vector<int>prev(long long arr[],int n){
        vector<int> prevArr(n,0);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){
                s.pop();
            }
           
            prevArr[i]=s.top();
            s.push(i);
        }
        return prevArr;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long maxArea =-1;

        vector<int>nextSmaller(n);
        nextSmaller= next(arr,n);
        vector<int> prevSmaller(n);
        prevSmaller= prev(arr,n);
        for(int i=0;i<n;i++){
            int next = nextSmaller[i];
            int prev = prevSmaller[i];
            if(next == -1){
                next=n;
            }
            long long currArea = arr[i]*(next - prev -1);
            maxArea = max (maxArea , currArea) ;
        }
        return maxArea;
    }
};
