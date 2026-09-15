class Solution {
public:

    string encode(vector<string>& strs) {
        
        string s = "";
        for(int i = 0; i < strs.size(); i++){

            s += to_string(strs[i].length()) + '#' + strs[i];

        }

        return s;
        
    }

    vector<string> decode(string s) {

        int cur = 0;
        vector<string> res;
        while(cur < s.length()){
            
            int num = 0;
            while(s[cur] != '#'){
                
                num *= 10;
                num += s[cur] - '0';
                cur++;

            }

            cur++;

            res.push_back(s.substr(cur, num));

            cur += num;

        }

        return res;

    }
};
