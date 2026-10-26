class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> dict;
        for(char& c : t) dict[c] ++;
        int l = 0, r = 0;
        int bestL = 0, bestLen = 0;
        string res = "";
        while(r < s.length()){
            bestLen ++;
            if(dict.contains(s[r])) dict[s[r]] --;
            r++;
            while(l < r){

                if(!dict.contains(s[l])){

                    l ++;
                    bestL ++;
                    bestLen --;

                }
                else{

                    if(dict[s[l]] >= 0) break;
                    dict[s[l]] ++;
                    bestL ++;
                    bestLen --;
                    l++;

                }

            }
            bool is_find = true;
            for(auto const& c : dict){

                if(c.second > 0){

                    is_find = false;
                    break;

                }

            }
            if(is_find) if(res.length() == 0 || bestLen < res.length()) res = s.substr(bestL,bestLen);


        }
        return res;
    }
};
