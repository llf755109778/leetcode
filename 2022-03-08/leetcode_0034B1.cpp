////
//// Created by 75510 on 2022/3/8.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//
//class Solution {
//public:
//    int binarySearch(vector<int>& nums, int target, bool lower) {
//        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
//        while (left <= right) {
//            int mid = (left + right) / 2;
//            if (nums[mid] > target || (lower && nums[mid] >= target)) {
//                right = mid - 1;
//                ans = mid;
//            } else {
//                left = mid + 1;
//            }
//        }
//        return ans;
//    }
//
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int leftIdx = binarySearch(nums, target, true);
//        int rightIdx = binarySearch(nums, target, false) - 1;
//        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
//            return vector<int>{leftIdx, rightIdx};
//        }
//        return vector<int>{-1, -1};
//    }
//};
//
//void trimLeftTrailingSpaces(string &input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//    }));
//}
//
//void trimRightTrailingSpaces(string &input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), input.end());
//}
//
//vector<int> stringToIntegerVector(string input) {
//    vector<int> output;
//    trimLeftTrailingSpaces(input);
//    trimRightTrailingSpaces(input);
//    input = input.substr(1, input.length() - 2);
//    stringstream ss;
//    ss.str(input);
//    string item;
//    char delim = ',';
//    while (getline(ss, item, delim)) {
//        output.push_back(stoi(item));
//    }
//    return output;
//}
//
//int stringToInteger(string input) {
//    return stoi(input);
//}
//
//string integerVectorToString(vector<int> list, int length = -1) {
//    if (length == -1) {
//        length = list.size();
//    }
//
//    if (length == 0) {
//        return "[]";
//    }
//
//    string result;
//    for(int index = 0; index < length; index++) {
//        int number = list[index];
//        result += to_string(number) + ", ";
//    }
//    return "[" + result.substr(0, result.length() - 2) + "]";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        vector<int> nums = stringToIntegerVector(line);
//        getline(cin, line);
//        int target = stringToInteger(line);
//
//        vector<int> ret = Solution().searchRange(nums, target);
//
//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}