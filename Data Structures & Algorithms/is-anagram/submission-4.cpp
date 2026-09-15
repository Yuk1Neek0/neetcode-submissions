class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;

        unordered_map<char,int> record;

        for(int i = 0; i < s.length() ; i++){

            record[s[i]] ++;

        }

        for(int i = 0; i< s. length(); i++){

            if(record[t[i]] == 0) return false;
            record[t[i]] --;

        }
        
        return true;


    }
};
