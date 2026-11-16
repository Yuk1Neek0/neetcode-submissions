class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;

        vector<int> res(temperatures.size(),0);
        st.push(0);
        for(int i = 1; i < temperatures.size(); i ++){

            while(!st.empty() && temperatures[i] > temperatures[st.top()]){

                int d = st.top();
                int t = temperatures[st.top()];
                st.pop();

                res[d] = i - d;

            }
            st.push(i);

        }
        return res;
    }
};
