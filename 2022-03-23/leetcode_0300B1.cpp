////
//// Created by 75510 on 2022/3/23.
////
//#include "bits/stdc++.h"
//using namespace std;
///******
// * 最长上升子序列
// */
//
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        return help1(nums);
//    }
//
//    /******
//     * dp
//     */
//    int help1(vector<int>& nums) {
//        int n = (int)nums.size();
//        if (n == 0) {
//            return 0;
//        }
//        vector<int> dp(n, 0);
//        for (int i = 0; i < n; ++i) {
//            dp[i] = 1;
//            for (int j = 0; j < i; ++j) {
//                if (nums[j] < nums[i]) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//        }
//        return *max_element(dp.begin(), dp.end());
//    }
//
//    /*****
//     * 二分+贪心
//     * @param nums
//     * @return
//     */
//    int help2(vector<int>& nums) {
//        int len = 1, n = (int)nums.size();
//        if (n == 0) {
//            return 0;
//        }
//        vector<int> d(n + 1, 0);
//        d[len] = nums[0];
//        for (int i = 1; i < n; ++i) {
//            if (nums[i] > d[len]) {
//                d[++len] = nums[i];
//            } else {
//                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
//                while (l <= r) {
//                    int mid = (l + r) >> 1;
//                    if (d[mid] < nums[i]) {
//                        pos = mid;
//                        l = mid + 1;
//                    } else {
//                        r = mid - 1;
//                    }
//                }
//                d[pos + 1] = nums[i];
//            }
//        }
//        return len;
//    }
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
//        int ret = Solution().lengthOfLIS(nums);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}