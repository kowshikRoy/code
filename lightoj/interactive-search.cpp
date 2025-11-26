#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int low = 1, high = n;
    while(low <= high) {
        int mid = low + (high - low)/2;
        cout << mid << endl;
        string verdict;
        cin >> verdict;
        if (verdict == "correct") break;
        else if(verdict == "too many tries") break;
        else if (verdict == "low") low = mid + 1;
        else high = mid - 1;
    }
}
