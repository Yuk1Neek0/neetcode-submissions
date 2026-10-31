class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> dict;
        int missing = t.length();
        for(char &c : t) dict[c] ++;
        string res = "";
        int l = 0, r = 0;
        while(r < s.length()){

            if(dict.contains(s[r])){

                dict[s[r]] --;                
            }
            r++;

            while(l < r){

                if(!dict.contains(s[l])){

                    l++;

                }else{

                    if(dict[s[l]] >= 0) break;
                    dict[s[l]] ++;
                    l++;

                }

            }
            bool is_find = true;
                for(auto const& d : dict){

                    if(d.second > 0){

                        is_find = false;
                        break;

                    }

                }
                if(is_find){

                    if(res == "" || res.length() > r - l) res = s.substr(l , r - l);

                }


            }
            return res;

    }
    
};
// x y y z x