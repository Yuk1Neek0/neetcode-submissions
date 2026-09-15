class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        if(strs.size() <=0 ) return s;

        for(string ss : strs){
            s += to_string(ss.length()) + '#' + ss;
        }

        return s;
    }

    vector<string> decode(string s) { 

        if(s.empty()) return {};
        vector<string> res;
        int i=0;
        for(;i < s.length(); i++){
            
            int j=i;
            string num = "";
            for(; j < s.length(); j++){
                
                if(s[j] == '#') break;
                num.push_back(s[j]);

            }

            string ss = "";
            i = j + stoi(num);
            for(int k = 1; k <= stoi(num); k++ ){
                
                ss += s[j + k];

            }

            res.push_back(ss);
        }
        
        return res;
    }
};
