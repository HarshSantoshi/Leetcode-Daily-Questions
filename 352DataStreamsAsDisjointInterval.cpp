class SummaryRanges {
public:
    set<int>set;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        set.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(set.size()==0){
            return {};
        }
        vector<vector<int>>interval;
        int left =-1 , right =-1;
        for(auto value:set){
            if(left<0){
                left=right=value;
            }
            else if(value==right+1){
                right =value;
            }
            else{
                interval.push_back({left,right});
                left =right=value;
            }
        }
        interval.push_back({left,right});
        return interval;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
