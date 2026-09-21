class Solution {
public:

    string encode(vector<string>& strs) {

        string s = "";
        for(auto const &str : strs){

            s += to_string(str.length());
            s += '*';
            s += str;

        }
        return s;

    }

    vector<string> decode(string s) {

        if(s.length() == 0) return {};
        vector<string> res;
        int i = 0;
        while(i < s.length()){

            int num = 0;
            while(s[i] >= '0' && s[i] <= '9'){

                num*= 10;
                num += s[i] - '0';
                i++;

            }

            res.push_back(s.substr(i + 1,num));
            i += num + 1;

        }

        return res;

    }
};
