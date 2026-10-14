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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        if(intervals.size() == 0) return true;
        sort(intervals.begin(),intervals.end(),[](const Interval &a, const Interval &b){return a.start < b.start;});

        Interval* booked = new Interval(0,0);
        booked -> start = intervals[0] . start;
        booked -> end = intervals[0] . end;

        for(int i = 1; i < intervals.size(); i++){

            int l = intervals[i] . start, r = intervals[i] . end;

            if(l >= booked -> start && l < booked -> end) return false;

            booked -> end = max(booked -> end, r);

        }
        return true;

    }
};
