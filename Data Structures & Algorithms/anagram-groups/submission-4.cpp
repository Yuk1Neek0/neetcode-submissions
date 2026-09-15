class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> res;
        for(int i = 0; i < strs.size(); i++){

            int count[26] = {0};
            for(int j = 0; j < strs[i].length(); j++){

                count[strs[i][j] - 'a'] ++;

            }

            string key;
            for(int j = 0 ; j < 26; j++){

                key += to_string('a' + j) + to_string(count[j]);

            }

            map[key].push_back(strs[i]);
        }
        
        for( auto const n : map ){

            res.push_back( n.second ); 

        }

        return res;
    }
};
