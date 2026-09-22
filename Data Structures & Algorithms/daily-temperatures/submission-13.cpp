class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack<pair<int,int>> st;

       vector<int> res(temperatures.size(),0);

       for(int i = 0; i < temperatures.size(); i++){

            if(st.empty()){

                st.push({temperatures[0],0});
                continue;

            }

            while(!st.empty() && temperatures[i] > st.top().first){

                res[st.top().second] = i - st.top().second;
                st.pop();

            }
            
            st.push({temperatures[i],i});
       }

        return res;
    
    }
};
