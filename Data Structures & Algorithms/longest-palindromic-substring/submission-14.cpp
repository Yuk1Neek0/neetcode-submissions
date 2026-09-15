class Solution {
public:
    string longestPalindrome(string s) {
        int res = 1;
        
        int finall = 0, finalr = 0;
        int mid = 0;

        while(mid < s.length()){

            int l = mid - 1, r = mid + 1;
            if(l >= 0 && r < s.length()){

                int len = 1;
                while( l >= 0 && r < s.length() && s[l] == s[r]){
                    
                    len += 2;
                    if(res < len){

                        res = len;
                        finall = l;
                        finalr = r; 

                    }
                    l --;
                    r ++;
                    

                }

            }
            l = mid - 1, r = mid + 2;
            if(mid + 1 < s.length() && s[mid] == s[mid + 1]){

                int len = 2;
                if(res < len){

                        res = len;
                        finall = mid;
                        finalr = mid + 1; 

                    }
                while( l >= 0 && r < s.length() && s[l] == s[r]){

                    len += 2;
                    if(res < len){

                        res = len;
                        finall = l;
                        finalr = r; 

                    }
                    l --;
                    r ++;
                    

                }

            }

            mid ++;

        }

        return s.substr(finall, finalr - finall + 1);

    }
};
