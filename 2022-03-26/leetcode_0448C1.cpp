////
//// Created by 75510 on 2022/3/26.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///*************
// * 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
// * 请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
// */
//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int>& nums) {
//        for(int i = 0; i < nums.size(); ++i){
//            while(nums[nums[i] - 1] != nums[i]){
//                swap(nums[nums[i] - 1], nums[i]);
//            }
//        }
//        vector<int> ans;
//        for(int i = 0; i < nums.size(); ++i){
//            if(i + 1 != nums[i])
//                ans.push_back(i+1);
//        }
//        return ans;
//    }
//
//    /**********
//     *  朴素展位
//     * @param nums
//     * @return
//     */
//    vector<int> help1(vector<int>& nums) {
//        for(int i = 0; i < nums.size(); ++i){
//            while(nums[nums[i] - 1] != nums[i]){
//                swap(nums[nums[i] - 1], nums[i]);
//            }
//        }
//        vector<int> ans;
//        for(int i = 0; i < nums.size(); ++i){
//            if(i + 1 != nums[i])
//                ans.push_back(i+1);
//        }
//        return ans;
//    }
//
//
//    /*********
//     * 这个解答的原理：由于1<=a[i]<=n，所以我们可以在a[i]-1这个位置统计a[i]出现的次数，
//     * 同时为了不影响其他数字的统计，只需要加数组长度就行。
//     */
//    vector<int> help2(vector<int>& nums) {
//        int n = nums.size();
//        for (auto& num : nums) {
//            int x = (num - 1) % n;
//            nums[x] += n;
//        }
//        vector<int> ret;
//        for (int i = 0; i < n; i++) {
//            if (nums[i] <= n) {
//                ret.push_back(i + 1);
//            }
//        }
//        return ret;
//    }
//
//    /**********
//     * 这题用鸽笼原理实现，由题意可得，1~n的位置表示1~n个笼子，
//     * 如果出现过，相应的“鸽笼”就会被占掉，我们将数字置为负数表示被占掉了。
//     * 最后再遍历一遍，如果“鸽笼”为正数就是没出现的数字。
//     * @param nums
//     * @return
//     */
//    vector<int> help3(vector<int>& nums) {
////        class Solution:
////            def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
////
////                for n in nums:
////                    nums[abs(n)-1] = - abs(nums[abs(n)-1])
////                    #找到相应的鸽笼位置，取反
////
////                res = []
////                for i, v in enumerate(nums):
////                    if v >0:#如果大于0，说明没被占过，也就是没有出现过的数字
////                        res.append(i+1)
////                return res
//        return {};
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
//        vector<int> ret = Solution().findDisappearedNumbers(nums);
//
//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}