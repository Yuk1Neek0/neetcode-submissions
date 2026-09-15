class Solution {
public:
    bool isValid(string s) {
        
        if(s.length()%2 == 1) return false;

        stack<int> st;
        unordered_map<char,char> menu = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        for(char c : s){

            if( menu.count(c) ){

                if(!st.empty() && (st.top() == menu[c]) ){

                    st.pop();

                } else return false;

            }else st.push(c);

        }
        return st.empty();
    }
};
