class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        int i=0;
        while(i<asteroids.size()){
            if(st.empty()){
                st.push(asteroids[i]);
                i++;
            }
            else{
                if(asteroids[i]>0 && st.top()>0 || asteroids[i]<0 && st.top()<0 || asteroids[i]>0 && st.top()<0){
                    st.push(asteroids[i]);
                    i++;
                }
                else{
                    int top = st.top();
                    st.pop();
                    if(top==abs(asteroids[i])){
                        i++;
                    }
                    else if(top>abs(asteroids[i])){
                        st.push(top);
                        i++;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
