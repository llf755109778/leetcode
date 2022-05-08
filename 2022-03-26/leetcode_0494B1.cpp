////
//// Created by 75510 on 2022/3/26.
////
//#include "bits/stdc++.h"
//using namespace std;
///*******
// * 给你一个整数数组 nums 和一个整数 target 。
// * 向数组中的每个整数前添加'+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
// * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
// * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
// */
//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int target) {
//        vector<vector<int>> dp(nums.size(),vector<int>(5000,0));
//        int cnt;
//        dp[0][nums[0]+2000]++;
//        dp[0][-nums[0]+2000]++;
//        for(int i = 1; i < nums.size(); ++i){
//            for(int j = 3000; j >= 1000; --j){
//                if(dp[i-1][j]){
//                    dp[i][j - nums[i]] += dp[i-1][j];
//                    dp[i][j + nums[i]] += dp[i-1][j];
//                }
//            }
//        }
//        return dp[nums.size()-1][2000+target];
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
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        vector<int> nums = stringToIntegerVector(line);
//        getline(cin, line);
//        int target = stringToInteger(line);
//
//        int ret = Solution().findTargetSumWays(nums, target);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}