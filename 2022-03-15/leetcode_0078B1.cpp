////
//// Created by 75510 on 2022/3/15.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///**********
// * 类似dp思想 多一个数 为  前面的 和  这个数加上之前的
// */
//class Solution {
//public:
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<vector<int>> res;
//        res.push_back(vector<int>());
//        for (int i = 0; i < nums.size(); i++) {
//            int all = res.size();
//            for (int j = 0; j < all; j++) {
//                vector<int> tmp = (res[j]);
//                tmp.push_back(nums[i]);
//                res.push_back(tmp);
//            }
//        }
//        return res;
//    }
//};
//
//
/////****************
//// * dfs
//// */
////class Solution {
////public:
////    vector<int> t;
////    vector<vector<int>> ans;
////
////    void dfs(int cur, vector<int>& nums) {
////        if (cur == nums.size()) {
////            ans.push_back(t);
////            return;
////        }
////        t.push_back(nums[cur]);
////        dfs(cur + 1, nums);
////        t.pop_back();
////        dfs(cur + 1, nums);
////    }
////
////    vector<vector<int>> subsets(vector<int>& nums) {
////        dfs(0, nums);
////        return ans;
////    }
////};
//
/////**********
//// * 进制
//// */
////
////class Solution {
////public:
////    vector<int> t;
////    vector<vector<int>> ans;
////
////    vector<vector<int>> subsets(vector<int>& nums) {
////        int n = nums.size();
////        for (int mask = 0; mask < (1 << n); ++mask) {
////            t.clear();
////            for (int i = 0; i < n; ++i) {
////                if (mask & (1 << i)) {
////                    t.push_back(nums[i]);
////                }
////            }
////            ans.push_back(t);
////        }
////        return ans;
////    }
////};