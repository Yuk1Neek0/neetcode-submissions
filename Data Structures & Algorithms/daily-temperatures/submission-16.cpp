class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); i ++){

            if(st.empty() || temperatures[i] <= temperatures[st.top()]) st.push(i);
            else{

                while(!st.empty() && temperatures[i] > temperatures[st.top()]){

                    int day = st.top();
                    st.pop();
                    res[day] = i - day;

                }
                st.push(i);
                
            }

        }
        return res;
    }
};
