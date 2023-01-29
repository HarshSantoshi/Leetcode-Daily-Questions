class LFUCache {
    int count ;
    int maxSize ;
    int minFreq;
    unordered_map<int,pair<int,int>>keyValueCount;
    unordered_map<int,list<int>>freqKeyList;
    unordered_map<int,list<int>::iterator>keyList;

public:
    LFUCache(int capacity) {
       count=0;
       maxSize =capacity;
    }
    
    int get(int key) {
        //If key is not present
        if(keyValueCount.count(key)==0)return -1;

        freqKeyList[keyValueCount[key].second].erase(keyList[key]);
        keyValueCount[key].second++;
        freqKeyList[keyValueCount[key].second].push_back(key);
        keyList[key]=--freqKeyList[keyValueCount[key].second].end();
        if(freqKeyList[minFreq].size()==0){
            minFreq++;
        }
        return keyValueCount[key].first;
    }
    
    void put(int key, int value) {
       if(maxSize==0)return;
       //Check if key is already present
       int alreadyStored = get(key);
       //Key already present
       if(alreadyStored!=-1){
           keyValueCount[key].first = value;
           return ;
       }
       //If max capacity is already achieved
       if(count>=maxSize){
           keyValueCount.erase(freqKeyList[minFreq].front());
           keyList.erase(freqKeyList[minFreq].front());
           freqKeyList[minFreq].pop_front();
           count--;
       }
       //If key is not present and count<maxSize
       keyValueCount[key]= {value , 1 };
       freqKeyList[1].push_back(key);
       
       keyList[key]=--freqKeyList[1].end();
      
       minFreq =1;
       count++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
