class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        int n = 1;
        stack<string> st;
        st.push(tokens[0]);
        
        while(n < tokens.size()){

            if((tokens[n][0] < '0' || tokens[n][0] > '9' )&& tokens[n].size() == 1){

                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();

                if(tokens[n][0] == '+') st.push(to_string(stoi(s1) + stoi(s2)));
                else if(tokens[n][0] == '-') st.push(to_string(stoi(s2) - stoi(s1)));
                else if(tokens[n][0] == '*') st.push(to_string(stoi(s1) * stoi(s2)));
                else if(tokens[n][0] == '/') st.push(to_string(stoi(s2) / stoi(s1)));
                
            }else st.push(tokens[n]);

            n++;

        }

        return stoi(st.top());
    }
};
