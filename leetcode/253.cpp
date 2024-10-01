/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 253 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,int>> events;
        for(auto in: intervals) {
            events.push_back({in[0], 1});
            events.push_back({in[1], -1});
        }
        sort(events.begin(), events.end());
        int sum = 0, ans = 0;
        for(auto k: events) {
            sum += k.second;
            ans = max(ans, sum);
        }
        return ans;
    }
};

