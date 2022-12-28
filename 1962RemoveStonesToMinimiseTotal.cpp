
class Solution {
public:

    int minStoneSum(vector<int>& piles, int k) {
       //Store in max heap
       priority_queue<int>pq(piles.begin(),piles.end());

       int sum = 0;
       while(k>0){
           int a = pq.top();
           pq.pop();
           pq.push(a-a/2);
           k--;
       }
       while(!pq.empty()){
           sum+=pq.top();
           pq.pop();
       }
       return sum;
    }
};
