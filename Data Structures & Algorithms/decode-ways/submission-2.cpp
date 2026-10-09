class Solution {
public:
    int numDecodings(string s) {
        

        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= s.length(); i ++){
            

            for(int j = 1 ; j <= 26; j ++){

                string ch = to_string(j);
                if(i < ch.length()) break;

                bool is_same = true;
                for(int k = 0; k < ch.length(); k ++){

                    if(ch[ch.length() - 1 - k] != s[i - k - 1]){

                        is_same = false;
                        break;

                    }

                }
                if(is_same) if(dp[i - ch.length()] != -1) dp[i] += dp[i - ch.length()];

            }

        
        }
        return dp[s.length()];
    }   
};
