    /**
    * Definition of Interval:
    * class Interval {
    * public:
    *     int start, end;
    *     Interval(int start, int end) {
    *         this->start = start;
    *         this->end = end;
    *     }
    * }
    */

    class Solution {
    public:
        int minMeetingRooms(vector<Interval>& intervals) {
            if(intervals.size() <= 1) return intervals.size();
            sort(intervals.begin(),intervals.end(),[](const Interval &a, const Interval &b){return a.start < b.start;});
            priority_queue<int, vector<int>, greater<int>> ends;
            ends.push(intervals[0].end);
            for(int i = 1; i < intervals.size(); i ++){

                int start = intervals[i].start;
                int end = intervals[i].end;

                if(start >= ends.top()) ends.pop();
                ends.push(end);
            }
            return ends.size();
        }
    };
