class Solution {
public:
    bool isanagram(string x,string y){
        if(x.length()!=y.length()) return false;

        int chars[30]={0};
        for(int i=0;i<x.length();i++){
            chars[x[i]-'a']+=1;
            chars[y[i]-'a']-=1;
        }

        for(int i=0;i<26;i++){
            if(chars[i]!=0) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        int mark[strs.size()+5]={0};
        for(int i=0;i<strs.size();i++){
            vector<string> temp;
            if(mark[i]!=1){
                temp.push_back(strs[i]);
                mark[i]=1;
            }
            
            
            for(int j=0;j<strs.size();j++){
                if(isanagram(strs[i],strs[j])&&mark[j]!=1) {
                    temp.push_back(strs[j]);
                    mark[j]=1;
                }
            }
            if(temp.size()>0)
            res.push_back(temp);
        }
        return res;
    }
};
