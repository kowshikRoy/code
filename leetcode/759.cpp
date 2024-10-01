/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-28
 * Task: 759 
 */

#include<bits/stdc++.h>
using namespace std;

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> event;
        for(auto x: schedule) {
            for(auto in: x) {
                event[in.start] += 1;
                event[in.end] -= 1;
            }
        }

        int count = 0, start = -1;
        vector<Interval> ret;
        for(auto x: event) {
            if(start != -1 && count == 0) {
                ret.push_back({start, x.first});
            }
            count += x.second;
            if(count == 0) start = x.first;
        }
        return ret;
    }
};

