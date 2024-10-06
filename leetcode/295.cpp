/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-15
 * Task: 295
 */

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
 public:
  /** initialize your data structure here. */
  priority_queue<int> MaxHeap;
  priority_queue<int, vector<int>, greater<int>> MinHeap;
  MedianFinder() {}

  void balance() {
    while (MaxHeap.size() > 1 + MinHeap.size()) {
      int x = MaxHeap.top();
      MaxHeap.pop();
      MinHeap.push(x);
    }
    while (MaxHeap.size() < MinHeap.size()) {
      int x = MinHeap.top();
      MinHeap.pop();
      MaxHeap.push(x);
    }
  }

  void addNum(int num) {
    if (MaxHeap.empty() || MaxHeap.top() >= num)
      MaxHeap.push(num);
    else
      MinHeap.push(num);
    balance();
  }

  double findMedian() {
    if (MaxHeap.size() == MinHeap.size())
      return (MaxHeap.top() + MinHeap.top()) / 2.0;
    else
      return MaxHeap.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main() { return 0; }
