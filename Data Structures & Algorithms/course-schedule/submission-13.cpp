class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int finished = 0;
        unordered_map<int,vector<int>> mapping;
        vector<int> p(numCourses,0);
        queue<int> ready;
        for(int i = 0; i< prerequisites.size(); i++){

            mapping[prerequisites[i][1]].push_back(prerequisites[i][0]);
            p[prerequisites[i][0]] ++;

        }

        for(int i = 0; i < numCourses; i++){

            if(p[i] == 0) ready.push(i);
 
        }

        while(! ready.empty()){

            int size = ready.size();

            for(int i = 0; i < size; i++ ){

                int c = ready.front();
                ready.pop();
                finished ++;
                for(int n : mapping[c]){

                    p[n] --;
                    if(p[n] == 0) ready.push(n);

                }

            }

        }

        if(finished != numCourses) return false;
        for(int n : p){

            if(n != 0) return false;

        }
        return true;


    }
  
};
