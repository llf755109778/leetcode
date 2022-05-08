////
//// Created by 75510 on 2022/3/8.
////
//#include "bits/stdc++.h"
//
//using namespace std;
//
//
///*************
// * 方法 ：
// *      找到非降序的属
// *      找到比前面的数大的最小数，交换，排序
// * @param input
// */
////class Solution {
////public:
////    void nextPermutation(vector<int>& nums) {
////        int m = -1;
////        for(int i = nums.size() - 1; i > 0; --i){
////            if(m<nums[i]){
////                m = max(m,nums[i]);
////            }
////            if(m > nums[i-1]){
////                int h=11111;
////                int idx;
////                for(int j = i; j < nums.size(); ++j){
////                    if(nums[i-1]<nums[j]){
////                        if(h>nums[j]-nums[i-1]){
////                            h=nums[j]-nums[i-1];
////                            idx = j;
////                        }
////                    }
////                }
////                swap(nums[idx],nums[i-1]);
////                sort(nums.begin()+i,nums.end());
////                return;
////            }
////        }
////        std::reverse(nums.begin(), nums.end());
////    }
////};
//
//
//
//
///***********
// *
// *https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/
// *注意到下一个排列总是比当前排列要大，除非该排列已经是最大的排列。我们希望找到一种方法，能够找到一个大于当前序列的新序列，且变大的幅度尽可能小。具体地：
//
//我们需要将一个左边的「较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。
//
//同时我们要让这个「较小数」尽量靠右，而「较大数」尽可能小。当交换完成后，「较大数」右边的数需要按照升序重新排列。这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。
//
//以排列 [4,5,2,6,3,1][4,5,2,6,3,1] 为例：
//
//我们能找到的符合条件的一对「较小数」与「较大数」的组合为 22 与 33，满足「较小数」尽量靠右，而「较大数」尽可能小。
//
//当我们完成交换后排列变为 [4,5,3,6,2,1][4,5,3,6,2,1]，此时我们可以重排「较小数」右边的序列，序列变为 [4,5,3,1,2,6][4,5,3,1,2,6]。
//
//具体地，我们这样描述该算法，对于长度为 nn 的排列 aa：
//
//首先从后向前查找第一个顺序对 (i,i+1)(i,i+1)，满足 a[i] < a[i+1]a[i]<a[i+1]。这样「较小数」即为 a[i]a[i]。此时 [i+1,n)[i+1,n) 必然是下降序列。
//
//如果找到了顺序对，那么在区间 [i+1,n)[i+1,n) 中从后向前查找第一个元素 jj 满足 a[i] < a[j]a[i]<a[j]。这样「较大数」即为 a[j]a[j]。
//
//交换 a[i]a[i] 与 a[j]a[j]，此时可以证明区间 [i+1,n)[i+1,n) 必为降序。我们可以直接使用双指针反转区间 [i+1,n)[i+1,n) 使其变为升序，而无需对该区间进行排序。
//
// * @param input
// */
//
//class Solution {
//public:
//    void nextPermutation(vector<int>& nums) {
//        int i = nums.size() - 2;
//        while (i >= 0 && nums[i] >= nums[i + 1]) {
//            i--;
//        }
//        if (i >= 0) {
//            int j = nums.size() - 1;
//            while (j >= 0 && nums[i] >= nums[j]) {
//                j--;
//            }
//            swap(nums[i], nums[j]);
//        }
//        reverse(nums.begin() + i + 1, nums.end());
//    }
//};
//
//
//
//
//
//
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
//        Solution().nextPermutation(nums);
//
//        string out = integerVectorToString(nums);
//        cout << out << endl;
//    }
//    return 0;
//}