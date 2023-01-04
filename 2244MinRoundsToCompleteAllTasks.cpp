class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        int n = tasks.size();
        int count =1;
        int ans =0;
        for(int i=1;i<n;i++){
            if(tasks[i-1]==tasks[i]){
                count++;
            }
            else{
                if(count<2){
                    return -1;
                }
                else{
                    if(count%3==0){
                        ans+=count/3;
                    }
                    else{
                        ans+=count/3+1;
                    }
                   
                }
                count=1;
            }
        }
        if(count<2){
            return -1;
        }
        else{
            if(count%3==0){
                ans+=count/3;
            }
            else{
                ans+=count/3+1;
            }
        }
        return ans;
    }
};
