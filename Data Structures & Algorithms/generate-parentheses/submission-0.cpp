class Solution {
private:

    vector<string> res;
    string s = "";
    char par[2] = {'(',')'};

public:
    vector<string> generateParenthesis(int n) {
        
        backtrack(n,0,0);
        return res;

    }

    void backtrack(int n, int opennum, int closenum){

        if( opennum < closenum ) return;

        if(opennum + closenum == n * 2){

            if(opennum != closenum ) return;

            res.push_back(s);
            return;

        }

        for(int i = 0; i < 2 ; i ++){

           
            if (i == 0){

                s.push_back(par[i]);
                backtrack(n , opennum + 1, closenum);
                s.pop_back();

            }
            else{

                s.push_back(par[i]);
                backtrack(n , opennum, closenum + 1);
                s.pop_back();

            }

        }

    }

};
