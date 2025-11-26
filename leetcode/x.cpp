#include <queue>
#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
  int id;
  int value;
  bool operator<(const Node& other) const {
    return value > other.value;
  }
};

class Solution {
public:
    using PIS = pair<int,string>;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for(auto s: words) cnt[s] ++;
        priority_queue<PIS, vector<PIS>, greater<PIS>> pq;
        for(auto [ks,v]: cnt) {
            pq.push({v,ks});
            if(pq.size() > k) pq.pop();
        }
        vector<string> ans;
        while(pq.size()) {
            auto [v, k] = pq.top();
            ans.push_back(k);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
  priority_queue<Node, vector<Node> > pq; // min heap
  for(int i = 0; i < 10; i ++) {
    int value = rand() % 100;
    printf("value = %d\n", value);
    pq.push({i, value});
    auto node = pq.top();
    printf("pq.top() = %d: %d\n", node.id, node.value);

  }
}