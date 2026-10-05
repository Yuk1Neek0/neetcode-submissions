class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int dictionary[26] = {0};
        for(char c: s) dictionary[c - 'a'] ++;
        for(char c : t){

            if(dictionary[c - 'a'] == 0) return false;
            dictionary[c - 'a'] --; 

        } 

        for(int n : dictionary) if(n != 0) return false;

        return true;
    }
};
