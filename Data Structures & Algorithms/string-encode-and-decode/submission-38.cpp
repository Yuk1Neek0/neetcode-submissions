class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string &s : strs){

            encoded.append(to_string(s.length()));
            encoded.push_back('#');
            encoded.append(s);

        }
        return encoded;

    }

    vector<string> decode(string s) {

        if(s == "") return {};
        int i = 0;
        vector<string> decoded;
        while(i < s.length()){

            int size = 0;
            while(s[i] >= '0' && s[i] <= '9'){

                size *= 10;
                size += s[i] - '0';
                i++;
            }
            i ++;
            decoded.push_back(s.substr(i,size));
            i += size;

        }
        return decoded;
    }   
};
