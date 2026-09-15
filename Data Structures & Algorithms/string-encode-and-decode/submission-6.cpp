class Solution {
public:

    string encode(vector<string>& strs) {

        if(strs.size() == 0) return "";
        string s = "";
        for(int i = 0; i <strs.size(); i++){

            s += to_string(strs[i].length()) + '#' + strs[i]; 

        }

        return s;

    }

    vector<string> decode(string s) {

        vector<string> res;
        if(s.length() == 0) return res;

        int index = 0;
        while(index < s.length()){

            int num = 0;
            while(s[index] != '#'){

                num *= 10;
                num += s[index] - '0';
                index++;

            }

            index++;
        string ss = "";
        for(int i = 0; i< num ; i ++){

            ss += s[index];
            index ++;

        }
        res.push_back(ss);

        }
        return res;
    }
};
