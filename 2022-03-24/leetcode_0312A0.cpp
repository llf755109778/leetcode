////
//// Created by 75510 on 2022/3/24.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    int maxCoins(vector<int>& nums) {
//        return help1(nums);
//    }
//
//    /****
//     * 区间dp
//     * @param nums
//     * @return
//     */
//    int help1(vector<int>& nums){
//        int n = nums.size();
//        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
//        vector<int> val(n + 2);
//        val[0] = val[n + 1] = 1;
//        for (int i = 1; i <= n; i++) {
//            val[i] = nums[i - 1];
//        }
//        for (int i = n - 1; i >= 0; i--) {
//            for (int j = i + 2; j <= n + 1; j++) {
//                for (int k = i + 1; k < j; k++) {
//                    int sum = val[i] * val[k] * val[j];
//                    sum += rec[i][k] + rec[k][j];
//                    rec[i][j] = max(rec[i][j], sum);
//                }
//            }
//        }
//        return rec[0][n + 1];
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
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        vector<int> nums = stringToIntegerVector(line);
//
//        int ret = Solution().maxCoins(nums);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}