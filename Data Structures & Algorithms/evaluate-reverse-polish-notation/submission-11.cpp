class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i ++){

            if(tokens[i][0] == '+'){

                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 + num2);

            }
            else if(tokens[i][0] == '-' && tokens[i].length() == 1){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            }
            else if(tokens[i][0] == '*'){

                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 * num2);

            }
            else if(tokens[i][0] == '/'){

                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 / num1);

            }
            else{
                bool is_neg = false;
                int num = 0;
                for(int j = 0 ;j < tokens[i].length(); j ++){

                    if(tokens[i][j] == '-'){

                        is_neg = true;
                        continue;

                    }

                    num *= 10;
                    num += tokens[i][j] - '0';
                }
                if(is_neg) num*= -1;
                st.push(num);

            }

        }
        return st.top();
    }
};
