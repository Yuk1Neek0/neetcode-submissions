class Solution {
public:
    bool isValid(string s) {

        if(s.length() %2 != 0 ) return false;
        unordered_map<char,char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        stack<char> st;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
 
                st.push(s[i]);

            }
            else{

                if(st.empty()) return false;
                char top = st.top();
                st.pop();

                if(map[s[i]] != top) return false;
            }

        }
        
        if(st.empty()) return true;
        else
        return false;
    }
};
