#include "letter_combinations_of_a_phone_number.h"

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <functional>


std::vector<std::string> Solution::letterCombinations(std::string digits) {
    if (digits.empty()) return {};
    std::vector<std::string> ans;
    std::unordered_map<char, std::string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    std::function<void(int, std::string)> f = [&](int i, std::string s) {
        if (i == digits.length()) {
            ans.push_back(s);
            return;
        }
        for(auto c: mp[digits[i]]) {
            f(i + 1, s + c);
        }
    };
    f(0, "");
    return ans;
}
