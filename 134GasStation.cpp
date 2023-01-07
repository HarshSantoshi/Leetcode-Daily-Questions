class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = cost.size();
        int extra = 0; 
        int extra_fuel = 0; 
        int start = 0; 
        
        for(int i = 0; i < n; i++){
            extra_fuel += gas[i] - cost[i];
            extra += gas[i] - cost[i];
            if(extra < 0){ 
                extra = 0; 
                start = i + 1; 
            }
        }
        return (extra_fuel < 0) ? -1 : start;
    }
};
