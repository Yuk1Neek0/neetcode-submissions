class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        map<int,int> posspd;
        int res;
        
        res = 0;
        for(int i = 0; i < position.size(); i++ ){

            posspd [position[i]] = speed[i];

        }
        double mintime = 0.0 ;

        for(auto it = posspd.rbegin(); it != posspd.rend(); it ++){

            double time = (target - it -> first) * 1.0 / it -> second;
            if(time > mintime) {
                mintime = time;
                res++;
            }

        } 
        
        return res;
    }
};
