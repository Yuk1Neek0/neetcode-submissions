class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        int res = stoi(tokens[0]);

        for(string s : tokens){

            if(s == "+" || s == "-" || s == "*" || s == "/"){

                if(s == "+"){

                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.pop();

                    res = n2 + n1;
                    st.push(res);

                }

                if(s == "-"){

                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.pop();

                    res = n2 - n1;
                    st.push(res);

                }

                if(s == "*"){

                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.pop();

                    res = n2 * n1;
                    st.push(res);

                }

                if(s == "/"){

                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.pop();

                    res = n2 / n1;
                    st.push(res);

                }

            }
            else{

                st.push(stoi(s));

            }

        }
        return res;

    }
};
