class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> p;
        p['('] = ')';
        p['['] = ']';
        p['{'] = '}';

        if(s.length() %2) return false;

        stack<int> st;
        for(char &c : s){

            if(c == ')' || c == ']' || c == '}'){

                if(st.empty()) return false;
                char t = st.top();
                st.pop();

                if(p[t] != c) return false;
            }
            else st.push(c);

        }
        return st.empty();
    }
};
