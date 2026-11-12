class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> degree(26,-1);
        unordered_map<int,vector<int>> dict;

        for(string& s : words)
            for(char & c : s) degree[c - 'a'] = 0;

        for(int i = 0 ; i < words.size() - 1; i ++){

            string word1 = words[i], word2 = words[i + 1];
            int index = 0;
            bool is_find = false;
            while(index < word1.length() && index < word2.length()){

                if(word1[index] != word2[index]){

                    is_find = true;
                    dict[word1[index] - 'a'].push_back(word2[index] - 'a');
                    degree[word2[index] - 'a'] ++;
                    break;
                }
                index ++;
            }

            if(is_find == false && word1.length() > word2.length()) return "";

        } 
        queue<int> que;
        for(int i = 0; i < degree.size(); i++)
            if(degree[i] == 0) que.push(i); 
        string res = "";
        while(!que.empty()){

            char c = que.front() + 'a';
            que.pop();
            res.push_back(c);
            for(int i = 0; i < dict[c - 'a'].size(); i ++){

                degree[dict[c - 'a'][i]] --;
                if(degree[dict[c - 'a'][i]] <= 0) que.push(dict[c - 'a'][i]);

            }

        }

        for(int i = 0; i < degree.size(); i++)
            if(degree[i] != -1 && degree[i] != 0) return "";
        return res; 
    }
};
