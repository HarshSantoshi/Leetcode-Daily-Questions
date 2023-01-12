class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        //Min heap using priority queue
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<N;i++){
            pq.push(arr[i]);
        }
        
        
        int ans =0;
    //Run till only one element is left in queue
        while(pq.size()>=2){
            int first = pq.top();
            
            pq.pop();
            int second = pq.top();
            
            pq.pop();
            pq.push(first+second);
          
            ans+=first+second;
           
        }
        return ans;
        
    }
};

