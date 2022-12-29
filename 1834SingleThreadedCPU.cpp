class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        //Priority Queue (Min heap)
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<>>pq;
        int N = tasks.size();
        long time =0;
        //Adding index for each value
        for(int i=0;i<N;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin() , tasks.end());
        int i=0;
        while(i<N || !pq.empty()){
            if(pq.empty()){
                time = max(time , (long)tasks[i][0]);
            }
            while(i<N && time>=tasks[i][0]){
                pq.push({tasks[i][1] , tasks[i][2]});
                i++;
            }
            pair<long,long>top = pq.top();
            pq.pop();
            time+=top.first;
            ans.push_back(top.second);
        }
        return ans;
        
    }
};
