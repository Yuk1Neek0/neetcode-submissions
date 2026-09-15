class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        unordered_map<string,vector<string>> subres;
        for( string s : strs ){

            int charNums[26] = {0};
            for(char c : s) charNums[c - 'a'] ++;

            string key;
            for(int i = 0; i < 26; i ++){

                key.push_back('a' + i);    
                key.push_back(charNums[i]);

            }

            subres[key].push_back(s);

        }

        for( auto p : subres ){

            res.push_back(p.second);

        }

        return res;

    }
};
