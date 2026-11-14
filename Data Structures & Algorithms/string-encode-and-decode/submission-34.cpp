class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s : strs){

            encoded.append(to_string(s.length()));
            encoded.push_back('#');

            encoded.append(s);

        }
        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> res;
        int i = 0;
        while(i < s.length()){
            int size = 0;
            while(s[i] >= '0' && s[i] <= '9'){

                size *= 10;
                size += (s[i] - '0');
                i++;
            }

            i++;
            res.push_back(s.substr(i,size));
            i += size;

      }
        
        return res;
    }
};
