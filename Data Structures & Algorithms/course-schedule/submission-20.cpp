class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> degree(numCourses,0);
        unordered_map<int,vector<int>> dict;

        for(int i = 0; i < prerequisites.size(); i++){

            int pc = prerequisites[i][0];
            int c = prerequisites[i][1];
            degree[c] ++;
            dict[pc].push_back(c);

        }

        queue<int> que;
        for(int i = 0; i < degree.size(); i++)
            if(degree[i] == 0) que.push(i);
        
        while(!que.empty()){

            int c = que.front();
            que.pop();

            for(int i = 0; i < dict[c].size(); i++){

                degree[dict[c][i]] --;
                if(degree[dict[c][i]] == 0) que.push(dict[c][i]);

            }

        }

        for(int i = 0; i < degree.size(); i ++)
            if(degree[i] != 0) return false;

        return true;

    }
};
