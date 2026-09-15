class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> p;
        p[')'] = '(';
        p['}'] = '{';
        p[']'] = '[';
        stack<char> st;

        for(char c : s){

            if(c == '(' || c == '{' || c == '[') st.push(c);
            else{

                if(st.empty()) return false;
                char stpop = st.top();
                st.pop();

                if(p[c] != stpop) return false;

            }

        }
        if(!st.empty()) return false;

        return true;
    }
};
