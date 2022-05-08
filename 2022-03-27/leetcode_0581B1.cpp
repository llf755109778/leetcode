//
// Created by 75510 on 2022/3/27.
//
#include "bits/stdc++.h"
using namespace std;
/**
 * 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 请你找出符合题意的 最短 子数组，并输出它的长度。
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int r=0,l=1;
        int mx=nums[0];
        int mn=nums[nums.size()-1];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i]<mx){
                r=i;
            }
            mx = max(mx, nums[i]);

        }
        for(int i = nums.size() - 2; i >=0; --i){
            if(nums[i]>mn){
                l=i;
            }
            mn = min(mn, nums[i]);
        }
        return r - l + 1;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().findUnsortedSubarray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}