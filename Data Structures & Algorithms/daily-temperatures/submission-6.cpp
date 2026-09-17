class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>> st;
        vector<int> res(temperatures.size() , 0);
        st.push({temperatures[0],0});

        for(int i = 1 ; i < temperatures.size(); i++){

            while(!st.empty() && temperatures[i] > st.top().first ){

                int d = st.top().second;
                st.pop();
                res[d] = i - d;

            }
            st.push({temperatures[i],i});
            
        }

        return res;

    }
};
