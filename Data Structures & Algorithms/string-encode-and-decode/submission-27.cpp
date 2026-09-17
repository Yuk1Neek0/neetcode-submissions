class Solution {
public:

    string encode(vector<string>& strs) {

        string s;
        for(string n : strs){

            s += to_string(n.length());
            s += '*';
            s += n;
 
        }
        return s;

    }

    vector<string> decode(string s) {

        int n = 0;
        if(s.length() == 0) return {};

        n = 0;
        vector<string> ss;
        while(n < s.length()){

            int k = 0, l = n;
            while(s[n] != '*'){

               n++;

            }
            k = stoi(s.substr(l, n - l));
            n++;

            ss.push_back(s.substr(n ,k));
            n = n + k;

        }

        return ss;

    }
};
