////
//// Created by 75510 on 2022/3/8.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//
///**********
// * 官方解法 暴力回溯
// */
//class Solution {
//public:
//    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
//        if (idx == candidates.size()) {
//            return;
//        }
//        if (target == 0) {
//            ans.emplace_back(combine);
//            return;
//        }
//        // 直接跳过
//        dfs(candidates, target, ans, combine, idx + 1);
//        // 选择当前数
//        if (target - candidates[idx] >= 0) {
//            combine.emplace_back(candidates[idx]);
//            dfs(candidates, target - candidates[idx], ans, combine, idx);
//            combine.pop_back();
//        }
//    }
//
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> ans;
//        vector<int> combine;
//        dfs(candidates, target, ans, combine, 0);
//        return ans;
//    }
//};
//
//
//
/////*************
//// *  转换成背包问题
//// */
////class Solution {
////public:
////    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
////        vector<vector<vector<int> > > path(target + 1);
////        path[0] = {{}};
////        for (auto x : candidates) {     // 每一个值
////            for (int i = x; i <= target; ++i) { //这个值可以在哪些数中
////                for (auto v : path[i - x]) {    //上面的数字由x+原来的组成
////                    v.push_back(x);                 // auto 默认不修改原v
////                    path[i].push_back(v);
////                }
////            }
////        }
////        return path[target];
////    }
////};
//
//
//
//
//int main() {
//    vector<int> candidates {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
//    (new Solution())->combinationSum(candidates,500);
//    return 0;
//}