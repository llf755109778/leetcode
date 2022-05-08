////
//// Created by 75510 on 2022/3/22.
////
//#include "bits/stdc++.h"
//using namespace std;
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int n = nums.size();
//        int left = 0; // 左第一个0
//        int right = 0; // 0后第一个非0
//        while (right < n) {
//            if (nums[right]) { // 非0 交换 确保0在后 ，否则 只移动 right
//                swap(nums[left], nums[right]);
//                left++;
//            }
//            right++;
//        }
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
//
//        Solution().moveZeroes(nums);
//
//        string out = integerVectorToString(nums);
//        cout << out << endl;
//    }
//    return 0;
//}