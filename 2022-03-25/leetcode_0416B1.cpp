////
//// Created by 75510 on 2022/3/25.
////
//#include "bits/stdc++.h"
//using namespace std;
//
/***********
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 */
//class Solution {
//public:
//
//    bool canPartition(vector<int>& nums) {
//        return help2(nums);
//    }
//
//    /**********
//     * 常规dp
//     * @param nums
//     * @return
//     */
//    bool help1(vector<int>& nums) {
//        int n = nums.size();
//        if (n < 2) {
//            return false;
//        }
//        int sum = accumulate(nums.begin(), nums.end(), 0);
//        int maxNum = *max_element(nums.begin(), nums.end());
//        if (sum & 1) {
//            return false;
//        }
//        int target = sum / 2;
//        if (maxNum > target) {
//            return false;
//        }
//        vector<vector<int>> dp(nums.size(),vector<int>(target + 1, 0));
//        for (int i = 0; i < n; i++) {
//            dp[i][0] = true;
//        }
//        dp[0][nums[0]] = true;
//
//        for(int i = 1; i < nums.size(); ++i){
//            int num = nums[i];
//            // dp[i][num] = 1;
//            for(int j = 1; j <= target; ++j){
//                dp[i][j] = dp[i-1][j];
//                if (j >= num) {
//                    dp[i][j] = dp[i-1][j] | dp[i-1][j - num];
//                }
//            }
//        }
//        return dp[n-1][target];
//    }
//
//    /*******
//     * 空间优化dp 注意：target -> 0
//     * @param nums
//     * @return
//     */
//    bool help2(vector<int>& nums) {
//        if(nums.size()<=1) return false;
//        long long sum=0;
//        for(auto &n:nums) sum+=n;
//        if(sum&1) return false;
//        sum=sum>>1;
//        vector<bool> dp(sum+1,0);
//        dp[0]=1;
//        for(auto &n:nums){
//            for(int i=sum;i>0;i--){
//                if(i>=n){
//                    dp[i]=dp[i-n] || dp[i];
//                }
//            }
//        }
//        return dp[sum];
//    }
//};
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
//string boolToString(bool input) {
//    return input ? "True" : "False";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        vector<int> nums = stringToIntegerVector(line);
//
//        bool ret = Solution().canPartition(nums);
//
//        string out = boolToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}