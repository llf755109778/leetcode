////
//// Created by 75510 on 2022/3/20.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        return help2(nums);
//    }
//
//
//    int help1(vector<int>& nums) {
//        vector <int> maxF(nums), minF(nums);
//        for (int i = 1; i < nums.size(); ++i) {
//            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
//            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
//        }
//        return *max_element(maxF.begin(), maxF.end());
//    }
//
//
//    int help2(vector<int>& nums) {
//        int len = nums.size(), mx = nums[0], nowMax = 1, nowMin = 1, tmp;
//
//        for(int i = 0; i < len; i++) {
//            // 遇到负数，最大值 和 最小值 一定会发生互换（题解中列出所有情况的规律总结）
//            if(nums[i] < 0) {
//                tmp = nowMax;
//                nowMax = nowMin;
//                nowMin = tmp;
//            }
//
//            // 看乘了 nums[i] 后，还是不是最大值或最小值，是的话才乘 nums[i]
//            nowMax = max(nowMax * nums[i], nums[i]);
//            nowMin = min(nowMin * nums[i], nums[i]); // 维持一个最小数，因为最小数乘负数的话 肯定是最大的
//
//            // 看是否要更新返回的最大值
//            mx = max(nowMax, mx);
//        }
//
//        return mx;
//    };
//
//
//    int help3(vector<int>& nums) {
//
////        reverse_nums = nums[::-1]
////        for i in range(1, len(nums)):
////        nums[i] *= nums[i - 1] or 1
////        reverse_nums[i] *= reverse_nums[i - 1] or 1
////        return max(nums + reverse_nums)
//        return 1;
//    }
//
//
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
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        vector<int> nums = stringToIntegerVector(line);
//
//        int ret = Solution().maxProduct(nums);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}
//
