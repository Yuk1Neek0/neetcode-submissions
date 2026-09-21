class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){

            if(tokens[i].length() == 1 && (tokens[i][0] > '9' || tokens[i][0] <'0')){

                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if(tokens[i] == "+") st.push(num1 + num2);
                else if(tokens[i] == "-") st.push(num1 - num2);
                else if(tokens[i] == "*") st.push(num1 * num2);
                else st.push(num1 / num2);
                
            }
            else st.push(stoi(tokens[i]));

        }

        return st.top();

    }
};
